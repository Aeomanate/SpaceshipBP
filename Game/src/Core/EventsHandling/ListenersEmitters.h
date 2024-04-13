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
        if(!isActive)
        {
            return;
        }
        eventHandler(eventData);
    }

    void SwitchActive(bool state)
    {
        isActive = state;
    }

protected:
    EventHandler eventHandler;
    bool isActive = true;
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

#define DATA_LISTENER(Name, EventData)                                          \
    EventListener<EventData> listener##Name { [this] (const EventData& data) {  \
        On##Name(data);                                                         \
    }};                                                                         \
    void On##Name(const EventData&)

#define SIMPLE_LISTENER(Name)                      \
    EventListener<void> listener##Name { [this] {  \
        On##Name();                                \
    }};                                            \
    void On##Name()

#define DATA_EMITTER(Name, EventData)       \
    EventEmitter<EventData> emitter##Name   \

#define SIMPLE_EMITTER(Name)           \
    EventEmitter<void> emitter##Name   \

#endif //SPACESHIPBP_LISTENERSEMITTERS_H
