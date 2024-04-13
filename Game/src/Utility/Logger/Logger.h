#ifndef SPACESHIPBP_LOGGER_H
#define SPACESHIPBP_LOGGER_H

#include <string>

class Logger
{
public:
    static void Log(const std::string& message);

private:

};

#define LOG(Message) Logger::LOG(Message)


#endif //SPACESHIPBP_LOGGER_H
