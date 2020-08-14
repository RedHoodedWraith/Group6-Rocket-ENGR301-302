#ifndef FLUORIDE_ERRORHANDLER_H
#define FLUORIDE_ERRORHANDLER_H

#include "padparadscha.h"

class ErrorHandler{
public:
    ErrorHandler(Padparadscha comms, String classname);
    void report_error(String message);
private:
    Padparadscha comms;
    String classname;
    const String MESSAGE_PREFIX = "[ERROR from Package '";
    const String MESSAGE_SUFFIX = "']: ";

    String constructMessage(String message);
};

#endif //SUN_INCINERATOR_ROCKET_CONTROLLER_FLUORIDE_ERRORHANDLER_H
