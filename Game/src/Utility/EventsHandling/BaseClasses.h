#ifndef SPACESHIPBP_BASECLASSES_H
#define SPACESHIPBP_BASECLASSES_H

template <class EventData>
class EventEmitterBase;

template <class EventData>
class EventListenerBase
{
    using BaseEmitter = EventEmitterBase<EventData>;

public:
    void SubscribeEmitter(BaseEmitter& eventEmitter)
    {
        emitters.insert(&eventEmitter);
        eventEmitter.SubscribeListener(*this);
    }

    void UnsubscribeEmitter(BaseEmitter& eventEmitter)
    {
        if(emitters.erase(&eventEmitter))
        {
            eventEmitter.UnsubscribeListener(*this);
        }
    }

    virtual ~EventListenerBase()
    {
        while(!emitters.empty())
        {
            this->UnsubscribeEmitter(**emitters.begin());
        }
    }

private:
    std::unordered_set<BaseEmitter*> emitters;
};


template <class EventData>
class EventListener;

template <class EventData>
class EventEmitterBase
{
public:
    using BaseListener = EventListenerBase<EventData>;
    friend class EventListenerBase<EventData>;

protected:
    void SubscribeListener(BaseListener& listener)
    {
        listeners.insert(&listener);
    }

    void UnsubscribeListener(BaseListener& listener)
    {
        if(listeners.erase(&listener))
        {
            listener.UnsubscribeEmitter(*this);
        }
    }

    virtual ~EventEmitterBase()
    {
        while(!listeners.empty())
        {
            this->UnsubscribeListener(**listeners.begin());
        }
    }

protected:
    std::unordered_set<BaseListener*> listeners;
};



#endif //SPACESHIPBP_BASECLASSES_H
