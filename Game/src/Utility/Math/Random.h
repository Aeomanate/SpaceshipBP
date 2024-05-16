#ifndef SPACESHIPBP_RANDOM_H
#define SPACESHIPBP_RANDOM_H

#include <random>

class Random
{
public:
    template<class T, class U, class Common = std::common_type_t<T, U>>
    Common Range(T begin, U end)
    {
        if constexpr (std::is_floating_point<Common>())
        {
            std::uniform_real_distribution<Common> distribution(static_cast<Common>(begin), static_cast<Common>(end));
            return distribution(random);
        }
        else
        {
            std::uniform_int_distribution<Common> distribution(static_cast<Common>(begin), static_cast<Common>(end));
            return distribution(random);
        }
    }

    unsigned int operator()()
    {
        return random();
    }

    template<class T>
    T rangeUniformRandom(T begin, T end)
    {
        return rangeUniformRandom(begin, end);
    }

private:
    static std::mt19937 random;
};

#endif // SPACESHIPBP_RANDOM_H
