#include "fluoride_errorhandler.h"

ErrorHandler::ErrorHandler(Padparadscha comms, String classname) {
    ErrorHandler::classname = classname;
    ErrorHandler::comms = comms;
}

void ErrorHandler::report_error(String message) {
    String finalMessage = constructMessage(message);
    comms.sendDataSerial(finalMessage);
}

String ErrorHandler::constructMessage(String message) {
    return MESSAGE_PREFIX + classname + MESSAGE_SUFFIX + message;
}
