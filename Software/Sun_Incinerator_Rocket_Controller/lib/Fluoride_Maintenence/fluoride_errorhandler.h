#ifndef FLUORIDE_ERRORHANDLER_H
#define FLUORIDE_ERRORHANDLER_H

#include "padparadscha.h"

class ErrorHandler{
public:
    ErrorHandler(Padparadscha comms);
    void report_error(String message);
private:
    Padparadscha comms;
};

#endif //SUN_INCINERATOR_ROCKET_CONTROLLER_FLUORIDE_ERRORHANDLER_H
