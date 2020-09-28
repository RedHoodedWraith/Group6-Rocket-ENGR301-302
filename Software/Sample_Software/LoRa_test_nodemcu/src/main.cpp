/**
 * Basic sketch for transmit/receive over LoRa
 * Handles a minimal amount of error. In production code, it will be important to handle the interaction between transmit/receive interrupts. Both of these will need to be interrupt driven, as we do not want to hang our CPU
 */
#include <Arduino.h>
#include "RadioLib.h"
#define DEBUG

#define PACKET_SIZE 64

// Declare a buffer for storing serial data before it is packaged and sent over LoRa
char serial_buf[PACKET_SIZE] = {0};

// Current position in the serial buffer
int buf_pos;

/*  Initialise the radio module
 *  CS pin: D8
 *  DIO0 (Interrupt): D1
 *  RESET pin: D2
 */

#define CS D8
#define DIO0 D1
#define RESET D3

RFM98 radio = new Module(CS, DIO0, RADIOLIB_NC);

/**
 * Interrupt Service Routine
 * This method is called whenever DIO0 (on the RFM98 module) outputs a pulse.
 * With this, we can only process received data when necessary, and have the processor free the rest of the time. This is important, as the other method is blocking, and will freeze the CPU until a transmission is received.
 * Additionally, this flag will be utilised to ensure transmissions successfully go through, without hanging the CPU
 */

// Set this flag true in the ISR. Whenever this flag is true in the main loop, there is data available on the radio module.
bool isrFlag = false;

// Allow for this interrupt to be disabled. This is probably better done at a lower level, but that can be a problem for later.
bool enableISR = true;

// Current transceiver state. If true, module is in transmit mode, waiting for transmission done interrupt
bool txMode = false;

// Store the transmission error state. This is global such that it can be utilised when the ISR fires upon transmission completion.
int txState = 0;

ICACHE_RAM_ATTR void ISR(){
  if(!enableISR)return;

  isrFlag = true;
}

// Method for handling data transmission. Will transmit serial_buf over LoRaWAN connection
void transmit(){
  // Disable interrupt while data transmission is initialised
  enableISR = false;
  // Start transmission
  txState = radio.startTransmit(serial_buf);
  txMode = true;
  // Reenable the ISR, as the module is now transmitting
  enableISR = true;
}

// Receive data, and spit it to the serial port
void receive(){
  // Read the incoming data
  String str;
  int state = radio.readData(str);

  #ifdef DEBUG
    if (state == ERR_NONE) {
      // packet was successfully received
      Serial.println(F("[RFM98] Received packet!"));

      // print data of the packet
      Serial.print(F("[RFM98] Data:\t\t"));
      Serial.println(str);

      // print RSSI (Received Signal Strength Indicator)
      // of the last received packet
      Serial.print(F("[RFM98] RSSI:\t\t"));
      Serial.print(radio.getRSSI());
      Serial.println(F(" dBm"));

    } else if (state == ERR_CRC_MISMATCH) {
      // packet was received, but is malformed
      Serial.println(F("CRC error!"));

    } else {
      // some other error occurred
      Serial.print(F("failed, code "));
      Serial.println(state);

    }
  #endif

    // put module back to listen mode
    radio.startReceive();
}

void setup() {
  Serial.begin(9600);
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, HIGH);
  
  #ifdef DEBUG
  Serial.println(F("[RFM98] Initialising..."));
  #endif
  int state = radio.begin();

  if(state == ERR_NONE){
    #ifdef DEBUG
    Serial.println(F("[RFM98] Success!"));
    #endif
  }
  else{
    #ifdef DEBUG
    Serial.print(F("[RFM98] Failed. Error: "));
    Serial.println(state);
    #endif
    while(true);
  }

  // Attach the ISR to trigger on DIO0
  radio.setDio0Action(ISR);

  // start listening for packets
  #ifdef DEBUG
  Serial.println(F("[RFM98] Starting to listen ... "));
  #endif
  state = radio.startReceive();
  if (state == ERR_NONE) {
    #ifdef DEBUG
    Serial.println(F("[RFM98] Success! Now listening"));
    #endif
  } else {
    #ifdef DEBUG
    Serial.print(F("[RFM98] Failed to listen, code "));
    Serial.println(state);
    #endif
    while (true);
  }
}

void loop() {
  // If data has arrived, handle this
  if(isrFlag){
    // disable the interrupt service routine while
    // processing the data
    enableISR = false;

    // reset flag
    isrFlag = false;

    // If the module was waiting for transmission to complete, handle this
    if(txMode){
      // Return to listening for transmissions
      radio.startReceive();
      txMode = false;

      if (txState == ERR_NONE) {
        // packet was successfully sent
        #ifdef DEBUG
        Serial.println(F("[RFM98] Transmission finished!"));
        #endif

      } else {
        #ifdef DEBUG
        Serial.print(F("[RFM98] TX failed, code "));
        Serial.println(txState);
        #endif
      }
    }
    // If the module has received data, handle this
    else{
      receive();
    }
    // enable interrupt service routine
    enableISR = true;
  }

  // Handle serial data from the terminal
  while(Serial.available()){
    char in = Serial.read();

    // If our data has vanished, don't try to read it
    if(in < 0)continue;

    // Read the data into the buffer
    serial_buf[buf_pos] = in;
    buf_pos++;

    // If the packet is full, or this is a newline, send the data
    if(in == '\n' || buf_pos >= PACKET_SIZE){
      // Transmit data, and reset the buffer
      transmit();
      memset(serial_buf, 0, PACKET_SIZE);
      buf_pos = 0;
    }
  }

}