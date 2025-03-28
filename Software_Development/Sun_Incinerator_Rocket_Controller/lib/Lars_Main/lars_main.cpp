//
// Created by Asami De Almeida on 14/08/20.
//

#include "lars_main.h"

RocketController::RocketController() {
    communicator = new Padparadscha();
    serial_channel = communicator->getLocalSerial();
    sensors = new Rhodonite(serial_channel);
    servos = new Rutile(serial_channel);
}
