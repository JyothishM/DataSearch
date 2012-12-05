#ifndef DATASEARCHCONFIG_COMMON_H
#define DATASEARCHCONFIG_COMMON_H

#include "logger.h"

struct DataSearchConfig_Common
{
    static Logger* CreateDSConfigLogger();
};

// logger.
static Logger* DSConfigLogger = DataSearchConfig_Common::CreateDSConfigLogger();

#endif // DATASEARCHCONFIG_COMMON_H
