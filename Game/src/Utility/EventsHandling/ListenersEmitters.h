#ifndef SPACESHIPBP_LISTENERSEMITTERS_H
#define SPACESHIPBP_LISTENERSEMITTERS_H

#include <unordered_set>
#include <functional>
#include <type_traits>

#include "BaseClasses.h"

// Listeners

template <class EventData>
class EventListener: public EventListenerBase<EventData>
{
public:
    using EventHandler = std::function<void(const EventData&)>;

public:
    explicit EventListener(EventHandler&& eventHandler)
    : eventHandler { std::move(eventHandler) }
    { }

    void Receive(const EventData& eventData)
    {
        eventHandler(eventData);
    }

protected:
    EventHandler eventHandler;
};

template <>
class EventListener<void>: public EventListenerBase<void>
{
public:
    using EventHandler = std::function<void()>;

public:
    explicit EventListener(EventHandler&& eventHandler)
        : eventHandler { std::move(eventHandler) }
    { }

    void Receive() const
    {
        eventHandler();
    }

protected:
    EventHandler eventHandler;
};



// Emitters

template <class EventData>
class EventEmitter: public EventEmitterBase<EventData>
{
public:
    using Base = EventEmitterBase<EventData>;
    using Listener = EventListener<EventData>;

public:
    void Emit(const EventData& eventData)
    {
        for(const auto& listener: Base::listeners)
        {
            static_cast<Listener*>(listener)->Receive(eventData);
        }
    }
};


template <>
class EventEmitter<void>: public EventEmitterBase<void>
{
    using Base = EventEmitterBase<void>;
    using Listener = EventListener<void>;

public:
    void Emit()
    {
        for(const auto& listener: Base::listeners)
        {
            static_cast<const Listener*>(listener)->Receive();
        }
    }

private:

};


#endif //SPACESHIPBP_LISTENERSEMITTERS_H
