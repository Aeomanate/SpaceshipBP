#ifndef SPACESHIPBP_LOGGER_H
#define SPACESHIPBP_LOGGER_H

#include <string>

enum class LogLevel
{
    VERBOSE,
    NOTIFY,
    WARNING,
    ERROR,
    FATAL_ERROR,
};

extern LogLevel LOG_LEVEL;

void Log(std::string message, const std::string& details, LogLevel logLevel = LogLevel::NOTIFY);


#endif //SPACESHIPBP_LOGGER_H
