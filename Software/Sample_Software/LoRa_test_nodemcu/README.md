# RF98 NodeMCU Test Code
This project provides a single script that can be downloaded to a pair of ESP8266 based NodeMCU microcontrollers. With both devices connected to an RF98 LoRaWAN module, and a serial terminal, messages typed in one terminal will be displayed in the other, allowing for LoRa range testing.

## Hardware Setup
Each NodeMCU/RF98 setup should be wired as follows:

| NodeMCU  | RF98             |
|----------|------------------|
| D8       | NSS (CS)         |
| D7/HMOSI | MOSI             |
| D6/HMISO | HMISO            |
| D5/HSCLK | HSCLK            |
| D4       | RESET            |
| D1       | DIO0 (Interrupt) |

It is worth noting that although RESET is not passed into the RadioLib constructor, it is still utilised in the code. Due to some strange behaviour when used with RadioLib, this pin must be manually managed, rather than allowing the library to manage it. Therefore it is important that D4 is set as an `OUTPUT`, and pulled `HIGH` for radio operation.

## Software Setup
This platformio project should be downloaded to each NodeMCU, with each NodeMCU connected to a separate serial port. Personally, I use CuteCOM to view com ports. Each module should display the following messages when booted (Will need to press the reset button after opening serial port):

```
[RFM98] Initialising...
[RFM98] Success!
[RFM98] Starting to listen ... 
[RFM98] Success! Now listening
```

This means the module has connected successfully.

## Testing
### Example
#### NodeMCU 1:
Sent transmission, test output:
```
[RFM98] Initialising...
[RFM98] Success!
[RFM98] Starting to listen ... 
[RFM98] Success! Now listening
[RFM98] Transmission finished!
```

The string: `Test transmission\n` was entered into the serial port, and sent to the NodeMCU.

#### NodeMCU 2:
Received transmission, test output:
```
[RFM98] Initialising...
[RFM98] Success!
[RFM98] Starting to listen ... 
[RFM98] Success! Now listening
[RFM98] Received packet!
[RFM98] Data:           Test transmission

[RFM98] RSSI:           -80.00 dBm
```

# Important Software Notes
## `DEBUG` Flag
All debug print statements are wrapped in the following way:
```c++
#ifdef DEBUG
// Serial print statements here
#endif
```
This way, the serial print commands are only called if `DEBUG` is `#define`d in the source code.

## Interrupts
All code is interrupt driven, using the single interrupt line tied to pin `D1` (`DIO0` on the RF98). When booted, the module is placed in listening mode via `radio.startReceive()`. Additionally, the `txMode` flag is initialised as `false` to place the code in a state where it expects to receive data.

When an interrupt is triggered, the interrupt service routine is called. This sets the `isrFlag` to `true`. In the control loop, this flag is checked. When the flag has been raised, the loop will lower the flag, and proceed to check the current `txMode`.

If `txMode` is `true`, the module has been asked to transmit data, and the interrupt is an acknowledgement of transmission completion. The control code will print an acknowledgement, or error code (If `DEBUG` is set). Following this, the `txMode` is set to `false`, and `radio.startReceive()` is called to return to listening mode.

If `txMode` is `false`, the module is currently listening for data. Therefore, the interrupt signifies a packet arrival. This packet is read, and displayed to the serial port. The module is then placed back in listening mode.

When a packet is entered over serial, the control loop reads this in, and calls `transmit()`. This method passes the packet onto the LoRa module, via `radio.startTransmit()`, placing the module in a transmitting state. `txMode` is set to `true`, in order to notify the control loop that the next interrupt is a transmission complete acknowledgement.