#ifndef CONSTANTS_H
#define CONSTANTS_H

// set this setting zero for final build
#define DEVELOPMENT_BUILD 1

#define CONFIGFILE "../../../config.ini"


//config.ini file fields
#define STR_GROUP_DRIVER "SQLdriver"
   #define STR_DRIVERNAME "drivername"

#define STR_GROUP_DATABASE "database"
    #define STR_HOSTNAME "hostname"
    #define STR_DATABASENAME "databasename"
    #define STR_TABLENAME "tablename"

#define STR_GROUP_UITABLE "ui_table"
    #define STR_VISIBLECOLS "visibleCols"

#define STR_GROUP_CONDITIONFIELDS "condition_fields"
    #define STR_TYPE "Type"
    #define STR_KVA "KVA"
    #define STR_PHASE "Phase"
    #define STR_PRY_VOLTAGE "PrimaryVoltage"
    #define STR_SRY_VOLTAGE "SecondaryVoltage"

#if DEVELOPMENT_BUILD
    #define DATASHEET_TEMPLATE_PATH "../../../templates/"
    #define DATASHEET_TEMP_PATH "../../../temp"
    #define LOGFOLDER_PATH "../../../log"
#else
    #define DATASHEET_TEMPLATE_PATH "../templates"
    #define DATASHEET_TEMP_PATH "../temp"
    #define LOGFOLDER_PATH "../log"
#endif

#define DATASHEET_TEMPLATE_FILE "datasheet_template.html"
#define DATASHEET_TEMP_FILE "tempfile.html"

#endif // CONSTANTS_H
