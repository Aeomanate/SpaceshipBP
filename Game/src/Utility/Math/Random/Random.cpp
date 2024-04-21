#include "Random.h"

#include <chrono>

#ifdef NDEBUG

std::mt19937 Random::random {
    static_cast<unsigned>(
        std::chrono::system_clock::now().time_since_epoch().count()
    )
};

#else

std::mt19937 Random::random {
    static_cast<unsigned>(0)
};

#endif
