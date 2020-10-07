#ifndef SD_LOGGER
#define SD_LOGGER

#include <Arduino.h>
#include <STM32SD.h>

// If SD card slot has no detect pin then define it as SD_DETECT_NONE
// to ignore it. One other option is to call 'SD.begin()' without parameter.
#ifndef SD_DETECT_PIN
#define SD_DETECT_PIN SD_DETECT_NONE
#endif

class SD_Handler{
    public:
        SD_Handler();
    private:
        File theFile;
};

#endif