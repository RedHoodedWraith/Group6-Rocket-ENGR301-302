#include "rhodonite.h"
#include <SPI.h>
#include <SD.h>

// File myFile;

// void setup() {
//   // Open serial communications and wait for port to open:
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for native USB port only
//   }

//   Serial.print("Initializing SD card...");

//   if (!SD.begin(4)) {
//     Serial.println("initialization failed!");
//     while (1);
//   }
//   Serial.println("initialization done.");

//   // open the file. note that only one file can be open at a time,
//   // so you have to close this one before opening another.
//   myFile = SD.open("test.txt", FILE_WRITE);

//   // if the file opened okay, write to it:
//   if (myFile) {
//     Serial.print("Writing to test.txt...");
//     myFile.println("testing 1, 2, 3.");
//     // close the file:
//     myFile.close();
//     Serial.println("done.");
//   } else {
//     // if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }

//   // re-open the file for reading:
//   myFile = SD.open("test.txt");
//   if (myFile) {
//     Serial.println("test.txt:");

//     // read from the file until there's nothing else in it:
//     while (myFile.available()) {
//       Serial.write(myFile.read());
//     }
//     // close the file:
//     myFile.close();
//   } else {
//     // if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }
// }

// void loop() {
//   // nothing happens after setup
// }



Rhodonite::Rhodonite(PadparadschaSerial* comms) {
    error = new DiagnosticHandler(comms, classname);
}

float Rhodonite::getAirPressure() {
    return air_pressure;
}

float Rhodonite::getTime() {
    return time;
}

float Rhodonite::getLongitude(){
    return longitude;
}

float Rhodonite::getLatitude(){
    return latitude;
}

float Rhodonite::getAltitude(){
    return altitude;
}

float Rhodonite::getAcceleration() {
    return acceleration;
}

void Rhodonite::setAirPressure(float a) {
    air_pressure = a;
}

void Rhodonite::setTime(float t) {
    time = t;
}

void Rhodonite::setLongitude(float l){
    longitude = l;
}

void Rhodonite::setLatitude(float l){
    latitude = l;
}

void Rhodonite::setAltitude(float a){
    altitude = a;
}

void Rhodonite::setAcceleration(float a){
    acceleration = a;
}
