#include "Logger.h"

#include <fstream>
#include <iostream>
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"
#include <unordered_map>
using namespace std::string_literals;

void Logger::Log(const std::string& message, const std::string& details, Logger::Level logLevel)
{
    if(!IsLogLevelAppropriate(logLevel))
    {
        return;
    }

    // For prevent recursive call
    if(!currentLogMessage.empty())
    {
        currentLogMessage += "\n-> ";
        currentLogMessage += prefixed(explained(std::string(message), details), logLevel);
        return;
    }
    currentLogMessage = prefixed(explained(std::string(message), details), logLevel);
    LogInternal();
    currentLogMessage.clear();
}

bool Logger::IsLogLevelAppropriate(Level logLevel)
{
    return logLevel >= GlobalLogLevel;
}

void Logger::LogInternal()
{
    fs::path logFolder = getConfig().path.logFolder;
    std::string filename = getConfig().path.logName;
    fs::path logPath = logFolder / filename;

    if(!fs::exists(logFolder))
    {
        (currentLogMessage += "\n-> ")
            += explained(prefixed(*getLoc().fileOperations.createNotify, Level::NOTIFY), logFolder.string());
    }

    if(!SystemRelated::CreateDirWhenAbsent(logFolder))
    {
        if(!IsLogLevelAppropriate(Level::WARNING))
        {
            return;
        }
        (currentLogMessage += "\n-> ")
            += explained(prefixed(*getLoc().fileOperations.openOrCreateFailedWarning, Level::WARNING), logFolder.string());
        showInConsole(currentLogMessage);
        return;
    }

    std::ofstream log;
    log.open(logPath, std::ios_base::app);

    if(!log.is_open())
    {
        if(!IsLogLevelAppropriate(Level::WARNING))
        {
            return;
        }
        (currentLogMessage += "\n-> ")
            += explained(prefixed(*getLoc().fileOperations.openOrCreateFailedWarning, Level::WARNING), logPath.string());
        showInConsole(currentLogMessage);
        return;
    }

    log << currentLogMessage << std::endl;
}

void Logger::showInConsole(std::string& str)
{
    SystemRelated::ShowConsole();
    std::cerr << str << '\n';
}

const std::string& Logger::getLogPrefix(Level logLevel)
{
    static std::vector<std::string> logPrefix {
        { *getLoc().logLevel.verbose    },
        { *getLoc().logLevel.notify     },
        { *getLoc().logLevel.warning    },
        { *getLoc().logLevel.error      },
        { *getLoc().logLevel.fatalError },
    };

    return logPrefix[static_cast<int>(logLevel)];
}

std::string Logger::prefixed(const std::string& str, Level level) {
    std::string temp = "[";
    temp += getLogPrefix(level);
    temp += "] \t";
    temp += str;

    return temp;
}

std::string Logger::explained(std::string str, const std::string& details) {
    str += ": ";
    str += details;
    return str;
}


void Log(const std::string& message, const std::string& details, Logger::Level logLevel)
{
    Logger::Log(message, details, logLevel);
}
