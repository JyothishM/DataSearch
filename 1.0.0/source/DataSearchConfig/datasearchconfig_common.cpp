#include "datasearchconfig_common.h"
#include "constants.h"
#include <QDateTime>

Logger* DataSearchConfig_Common::CreateDSConfigLogger()
{
    // creating logger
    Logger* logger = new Logger(QString("%0/%1.%2").arg(LOGFOLDER_PATH)
                                .arg(QDate::currentDate().toString("yy MM dd config"))
                                .arg("log"));
    logger->SetTraceLevel((unsigned int)Logger::DEBUG);
    return logger;
}
