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

void Log(std::string&& message, LogLevel logLevel = LOG_LEVEL);

void Log(std::string_view message, std::string_view details, LogLevel logLevel = LOG_LEVEL);


#endif //SPACESHIPBP_LOGGER_H
