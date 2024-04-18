#include "Logger.h"

#include <fstream>
#include <iostream>
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"
#include <unordered_map>
using namespace std::string_literals;

LogLevel LOG_LEVEL = LogLevel::NOTIFY;

const std::string& getLogPrefix(LogLevel logLevel)
{
    static std::unordered_map<LogLevel, std::string> logPrefix {
        { LogLevel::VERBOSE    , *getLoc().logLevel.verbose    },
        { LogLevel::NOTIFY     , *getLoc().logLevel.notify     },
        { LogLevel::WARNING    , *getLoc().logLevel.warning    },
        { LogLevel::ERROR      , *getLoc().logLevel.error      },
        { LogLevel::FATAL_ERROR, *getLoc().logLevel.fatalError },
    };

    return logPrefix[logLevel];
}

#define PREFIXED(str, level) \
    ((("["s += getLogPrefix(level)) += "] \t") += str)
#define EXPLAINED(str, details) \
    ((str += ": ") += details)

bool isLogLevelAppropriate(LogLevel logLevel)
{
    return logLevel >= LOG_LEVEL;
}

void warningToConsole(std::string& str)
{
    SystemRelated::ShowConsole();
    std::cerr << str << '\n';
}

void LogInternal(std::string& message, LogLevel logLevel)
{
    if(!isLogLevelAppropriate(logLevel))
    {
        return;
    }

    message = PREFIXED(message, logLevel);

    fs::path logFolder = getConfig().logs.Folder;
    std::string filename = getConfig().logs.name;
    fs::path logPath = logFolder / filename;

    if(!fs::exists(logFolder))
    {
        (message += "\n-> ") += EXPLAINED(PREFIXED(*getLoc().fileOperations.createNotify, LogLevel::NOTIFY), logFolder.string());
    }

    if(!SystemRelated::CreateDirWhenAbsent(getConfig().logs.Folder))
    {
        if(!isLogLevelAppropriate(LogLevel::WARNING))
        {
            return;
        }
        (message += "\n-> ") += EXPLAINED(PREFIXED(*getLoc().fileOperations.openOrCreateFailedWarning, LogLevel::WARNING), logFolder.string());
        warningToConsole(message);
        return;
    }

    std::ofstream log;
    log.open(logPath, std::ios_base::app);

    if(!log.is_open())
    {
        if(!isLogLevelAppropriate(LogLevel::WARNING))
        {
            return;
        }
        (message += "\n-> ") += EXPLAINED(PREFIXED(*getLoc().fileOperations.openOrCreateFailedWarning, LogLevel::WARNING), logPath.string());
        warningToConsole(message);
        return;
    }

    log << message << std::endl;
}

void Log(std::string message, const std::string& details, LogLevel logLevel)
{
    if(!isLogLevelAppropriate(logLevel))
    {
        return;
    }

    LogInternal(EXPLAINED(message, details), logLevel);
}
