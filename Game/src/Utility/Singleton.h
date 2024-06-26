#ifndef SPACESHIPBP_SINGLETON_H
#define SPACESHIPBP_SINGLETON_H

#include <memory>

template<class Derived>
class Singleton
{
public:
    static Derived& GetInstance()
    {
        static Derived instance;

        return instance;
    }

protected:
    Singleton() = default;
};

#endif //SPACESHIPBP_SINGLETON_H
