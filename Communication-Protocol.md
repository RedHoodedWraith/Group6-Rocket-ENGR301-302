# Mission Control to Avionics Communication Protocol

This document details a protocol for communication between the rocket mission control computer, and avionics package. This protocol defines how LoRa packets should be structured, and sequenced. These packets are sent over a serial communciation link, in packets of up to 256 characters.


## Table of Contents
  - [Mission Control to Avionics Communication Protocol](#mission-control-to-avionics-communication-protocol)
  - [Table of Contents](#table-of-contents)
  - [LoRa Packet Structure](#lora-packet-structure)
    - [Individual Data Formats](#individual-data-formats)
      - [Initialisation Data Format - OpCode '1'](#initialisation-data-format---opcode-1)
      - [Status Data Format](#status-data-format)
      - [Debug Data Format](#debug-data-format)
  - [Example Conversation](#example-conversation)
  - [Note for Systems Teams](#note-for-systems-teams)

## LoRa Packet Structure
Each LoRa packet has 256 bytes. The first byte in this packet is a character determining the purpose of this packet, with the following 255 bytes allowed for any required data or commands. All data should be transmitted as a string of characters, and will be human readable. A packet will appear over serial as follows:

`{op-code (1 byte)}{data or command (up to 255 bytes)}\n`

The following identifier characters have been defined:

- **'0'**: This packet is a ping packet. The device receiving this packet should reply with a ping packet. This is utilised for initialisating steps where avionics is ensuring all peripherals are functional.
- **'1'**: Initialisation data request/reply packet. When coming *from avionics*, this packet is requesting all initialisation data. When coming *from mission control*, the data segment of this packet will contain initialisation parameters. Details on these parameters are given below in the "Initialisation Data Format" section.
- **'2'**: Idle/Arm packet. When coming *from avionics*, this packet will contain rocket status data, in the format defined in the "Status Data Format" section. When this packet comes *from mission control*, it is informing the avionics packet to "arm". When avionics receives this packet, an armed mode should be entered. In this mode, the avionics package waits to see saturation in the vertical IMU axis, indicating a launch.
- **'3'**: Status data packet. This packet will only be transmitted *from avionics*. This packet will simply contain core avionics status data, in the format defined in the "Status Packet Format" section. Avionics should transmit these packets continuously throughout armed, flight, descent, and landed stages.
- **'4'**: Debug data packet. This packet can be optionally transmitted *from avionics*, and contains extra system status information as defined in the "Debug Data Format" section.

### Individual Data Formats

The following sections define how data should be laid out for each type of data packet.

#### Initialisation Data Format - OpCode '1'

This packet is transmitted *from mission control* *to avionics*. The packet contains information that avionics needs for flight. Data contained in this packet is as follows:

- **Launch Angle**: Desired flight vector angles. This data contains two angles, in x and y planes. These x and y planes are to be realative to the rocket gimbal, which should be labelled with x and y directions. The rocket will use these two angles as a vector to maintain during flight.
- **PID Constants**: Desired control system constants. These should be passed as doubles. Three constants should be passed, Kp, Ki, and Kd. The avionics package will load these constants directly into the control system, and the passed values should come from PID simulation of the rocket.

The data should be as follows:

`{launch angle x [degrees]},{launch angle y [degrees]},{kp},{ki},{kd}`

An example initialisation packet from mission control would appear as follows:

`"113,13,1.2,3,0\n"`

This packet is defining a launch angle of 13 on x, 13 on y, and Kp=1.2, Ki=3, and Kd=0.

#### Status Data Format

This packet is transmitted *from avionics* whenever it can transmit. This packet contains information about the current status of the rocket as follows:

- **Avionics State**: Represents the current state of the avionics package. Avionics teams have not settled on specific set of states, but will likely be the following: "INIT", "IDLE", "ARMD", "FLGT", "DESC", and "LAND". This will be a string
- **Radio RSSI**: RSSI of radio link, gives an indication of signal strength. This will be a float, and may be negative.
- **GPS Coordinates**: Sent as a pair of floats, each to 4dp maximum. Will be given as latitude,longitude.
- **GPS State**: GPS is likely to lose lock on launch. This will indicate current GPS state. Will be "NF" for no fix, "2D" for 2D fix, "3D" for 3D fix.
- **Barometer Altitude**: Altitude as measured from barometer. Will be a float.
- **Ignitor State**: Four characters representing the current state of each ignitor. "F" for fired, "U" for unfired, "N" for not configured. Rocket will have four ignitors, two per parachute. Format will be `[CHUTE_1],[CHUTE_1_BACKUP],[CHUTE_2],[CHUTE_2_BACKUP]`.
- **Battery 1 Voltage**: Current voltage of mainboard battery. Will be a float, every avionics platform should implement a meter for this. Will be a float.
- **Ignitor Battery Voltage**: Voltage of ignitor battery, if implemented. If platform does not use second battery for ignition, and instead uses a supercap or something, this should store that voltage. Will be a float.

Example of the *data component* of a status packet. OpCode may vary depending on when this data is being transmitted, but the format of this data is not to vary.

Generic format:

`[AVIONICS_STATE],[RSSI],[GPS_LAT],[GPS_LONG],[GPS_STATE],[BAR_ALTITUDE],[CHUTE_1],[CHUTE_1_BACKUP],[CHUTE_2],[CHUTE_2_BACKUP],[BATTERY_1_VOLTAGE],[IGNITOR_VOLTAGE]\n`

Populated example:

`INIT,-50.3,47.1234,47,1234,53.9222,13.3533,3D,42.0,F,U,F,U,4.2,4.2\n`


#### Debug Data Format

This packet is transmitted *from avionics* if the avionics board is programmed to send debug information, and will transmit either when neccessary, or as frequently as it can. A debug packet contains the following data:

- **Max CPU Load**: Time spent in main loop since last transmission. Will be an integer.
- **Quarternions**: Current quarternion values of rocket. This will consist of four floats, in the form: `x,y,z,w`
- **Current Servo Position**: Current angle commanded to servo. Will be two floats, in the form `x,y`.
- **Max Servo Position**: Maximum commanded servo position since last transmission. Format same as above.
- **PID Controller Setpoint**: Setpoint of PID controller
- **PID Controller Error**: Current error value of PID controller.
- **Avionics Error State**: This field needs defining, but should contain information about whether the SD card write take too long? - controller had to bail out of the write and into the control loop again? Or exceed gyro max rates, accelerometer clipping? LoRa failures?
- **Custom**: The final data in a debug packet is reserved for custom debug data.

## Example Conversation

It is important that rocket <-> mission control communications follow a specific sequence. What follows is a detailed example of what this sequence should look like.

Packet direction is defined as either:

**A => MC**: Avionics to Mission Control

**A <= MC**: Mission control to Avionics

Initially, avionics board is first powered on. Board should have hardware interlocks on ignition engaged, ensuring that any surges do not ignite parachute charges. Avionics platform begins system verification, and will eventually ping mission control, expecting a reply. The following should occur:

**A => MC** `0\n`

**A <= MC** `0\n`

Avionics now knows that LoRa is functional. After any further internal processing is complete, Avionics will request all startup parameters from Mission Control, and expects a reply with all startup information:

**A => MC** `1\n`

**A <= MC** `113,13,1.2,3,0\n`

Avionics is now initialised with a launch vector of 13 degrees in x, 13 degrees in y, Kp = 1.2, Ki = 3, Kd = 0.

Avionics is now *IDLE*. Avionics will transmit status data to mission control until an *ARM* command is received:

**A => MC** `2IDLE,-50.3,47.1234,47,1234,53.9222,13.3533,3D,0.0,U,U,U,U,4.2,4.2\n`

**A => MC** `2IDLE,-50.3,47.1234,47,1234,53.9222,13.3533,3D,0.0,U,U,U,U,4.2,4.2\n`

**A => MC** `2IDLE,-50.3,47.1234,47,1234,53.9222,13.3533,3D,0.0,U,U,U,U,4.2,4.2\n`

**A <= MC** `2\n`

Mission control has commanded Avionics to *ARM*. Avionics is now ready to launch. All ignition interlocks should be removed. Avionics will continue to send status data to mission control.

**A => MC** `3ARMD,-50.3,47.1234,47,1234,53.9222,13.3533,3D,0.0,U,U,U,U,4.2,4.2\n`

These status packets will continue to be transmitted to mission control indefinitely. Once a sudden saturation of vertical axis is detected, Avionics will begin to transmit a packet with a *FLGT* state:

**A => MC** `3FLGT,-50.3,47.1234,47,1234,53.9222,13.3533,3D,5.2,U,U,U,U,4.2,4.2\n`

Any debug packets that are set to transmit will slot into this discussion where appropriate. Mission control is not expected to send anymore data to Avionics, and should just be listening to status and debug packets coming over serial.

## Note for Systems Teams
A "packet" as defined in this document is just a line of serial. It is actually quite short, and we can fit multiple in a LoRa transmission. It may be worthwhile combining packets into LoRa packets, then splitting them on the base station end.