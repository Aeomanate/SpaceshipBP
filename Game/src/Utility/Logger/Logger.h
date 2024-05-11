#ifndef SPACESHIPBP_LOGGER_H
#define SPACESHIPBP_LOGGER_H

#include <string>
#include <format>
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Clock.hpp"
#include "Utility/Visual/PositionInRectangle.h"


class Logger
{
public:
    enum class Level
    {
        VERBOSE     = 0,
        NOTIFY      = 1,
        WARNING     = 2,
        ERROR       = 3,
        FATAL_ERROR = 4,
    };
    static inline Level GlobalLogLevel = Level::NOTIFY;

public:
    static void Log(const std::string& message, const std::string& details, Level logLevel = Level::NOTIFY);

    static bool IsLogLevelAppropriate(Level logLevel);

private:
    static void LogInternal();

    static void showInConsole(std::string& str);

    static const std::string& getLogPrefix(Logger::Level logLevel);

    static std::string prefixed(const std::string& str, Level level);

    static std::string explained(const std::string& str, const std::string& details);

private:
    static inline std::string currentLogMessage;
    static inline sf::Clock clockRealtime;
};

void Log(const std::string& message, const std::string& details = { }, Logger::Level logLevel = Logger::Level::NOTIFY);

template <class T>
std::string toString(sf::Vector2<T> v)
{
    return std::format("[ {:10.4}; {:10.4} ]", std::to_string(v.x), std::to_string(v.y));
}


#endif //SPACESHIPBP_LOGGER_H
