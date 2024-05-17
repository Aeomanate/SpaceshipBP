#ifndef SPACESHIPBP_COMMON_H
#define SPACESHIPBP_COMMON_H

#include <exception>
#include <source_location>
#include "Core/Application/ObjectsAggregator/GetterLog.h"

#ifndef __GNUC__
#define __attribute__
#endif

template <class T>
inline __attribute__((always_inline)) T& REF(T* ptr)
{
    if(!ptr)
    {
        Log(getLoc().application.nullPointerAccess,
            std::format("{}:{} in File ' {} ' in func: ' {} '",
                        std::source_location::current().line(),
                        std::source_location::current().column(),
                        std::source_location::current().file_name(),
                        std::source_location::current().function_name()
            ),
            Logger::Level::ERROR);

        throw std::runtime_error(getLoc().application.nullPointerAccess);
    }
    return *ptr;
}

#endif //SPACESHIPBP_COMMON_H
