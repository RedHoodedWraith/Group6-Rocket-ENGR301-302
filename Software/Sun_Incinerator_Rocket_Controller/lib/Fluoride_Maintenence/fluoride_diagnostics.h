#ifndef FLUORIDE_ERRORHANDLER_H
#define FLUORIDE_ERRORHANDLER_H

#include "padparadscha_serial.h"
#include "fluoride_sd_logger.h"

class DiagnosticHandler{
public:
    DiagnosticHandler(class PadparadschaSerial* comms, String classname): comms(comms){
        DiagnosticHandler::classname = classname;
    };
    void report_error(String message);
    void report_message(String message);
private:
    PadparadschaSerial* comms;
    String classname;

    enum DiagnosticType {
        REPORT,
        ERROR
    };

    const String MESSAGE_PREFIX1 = "[";
    const String MESSAGE_WORD_ERROR = "ERROR";
    const String MESSAGE_WORD_REPORT = "REPORT";
    const String MESSAGE_PREFIX2 = " from Package '";
    const String MESSAGE_SUFFIX = "']: ";

    String getDiagnosticTypeStr(DiagnosticType type);
    String constructMessage(DiagnosticType type, String message);
};

#endif //SUN_INCINERATOR_ROCKET_CONTROLLER_FLUORIDE_ERRORHANDLER_H
