#include "fluoride_diagnostics.h"

DiagnosticHandler::DiagnosticHandler(Padparadscha comms, String classname) {
    DiagnosticHandler::classname = classname;
    DiagnosticHandler::comms = comms;
}

void DiagnosticHandler::report_error(String message) {
    String finalMessage = constructMessage(ERROR, message);
    comms.sendDataSerial(finalMessage);
}

void DiagnosticHandler::report_message(String message) {
    String finalMessage = constructMessage(REPORT, message);
    comms.sendDataSerial(finalMessage);
}

String DiagnosticHandler::constructMessage(DiagnosticType type, String message) {
    return MESSAGE_PREFIX1 + getDiagnosticTypeStr(type) + MESSAGE_PREFIX2 + classname + MESSAGE_SUFFIX + message;
}

String DiagnosticHandler::getDiagnosticTypeStr(DiagnosticType type){
    switch (type) {
        case ERROR:
            return MESSAGE_WORD_ERROR;
        default:
            return MESSAGE_WORD_REPORT;
    }
}
