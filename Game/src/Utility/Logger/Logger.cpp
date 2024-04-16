#include "Logger.h"

#include <fstream>
#include <iostream>
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"
#include <unordered_map>

LogLevel LOG_LEVEL = LogLevel::NOTIFY;

std::string getLogPrefix(LogLevel logLevel)
{
    static std::unordered_map<LogLevel, std::string> logPrefix {
        { LogLevel::VERBOSE    , getLoc().logLevel.verbose    },
        { LogLevel::NOTIFY     , getLoc().logLevel.notify     },
        { LogLevel::WARNING    , getLoc().logLevel.warning    },
        { LogLevel::ERROR      , getLoc().logLevel.error      },
        { LogLevel::FATAL_ERROR, getLoc().logLevel.fatalError },
    };

    return logPrefix[logLevel];
}

bool isLogLevelAppropriate(LogLevel logLevel)
{
    return logLevel >= LOG_LEVEL;
}

void Log(std::string&& message, LogLevel logLevel)
{
    if(!isLogLevelAppropriate(logLevel))
    {
        return;
    }

    message = "[" + getLogPrefix(logLevel) + "] " + message;

    fs::path logPath = getConfig().Logs.Folder / getConfig().Logs.Name;

    if(SystemRelated::CreateDirWhenAbsent(getConfig().Logs.Folder) && isLogLevelAppropriate(logLevel))
    {
        message += (getLoc().fileOperations.createNotify + ": " += getConfig().Logs.Folder.string() + "\n");
    }

    if(!fs::exists(logPath) && isLogLevelAppropriate(logLevel))
    {
        message += (getLoc().fileOperations.createNotify + ": " += logPath.string() + "\n");
    }

    std::ofstream log;
    log.open(logPath, std::ios_base::app);

    if(!log.is_open() && isLogLevelAppropriate(LogLevel::WARNING))
    {
        message += getLoc().fileOperations.createFailed + ": " += logPath.string() + "\n";
        SystemRelated::ShowConsole();
        std::cerr << message << '\n';
        return;
    }

    log << message << std::endl;
}

void Log(std::string_view message, std::string_view details, LogLevel logLevel)
{
    if(!isLogLevelAppropriate(logLevel))
    {
        return;
    }

    std::string fullMessage(message);
    fullMessage += ": ";
    fullMessage += details;

    Log(std::move(fullMessage));
}
