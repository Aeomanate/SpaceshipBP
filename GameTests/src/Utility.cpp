#include <gtest/gtest.h>
#include <Utility/EventsHandling/ListenersEmitters.h>

TEST(UtilitySuite, EventHandling)
{
    int localValue = 12;

    EventEmitter<int> emitter;
    EventListener<int> listener([&localValue](int emittedValue) {
        localValue += emittedValue;
    });

    listener.SubscribeEmitter(emitter);

    emitter.Emit(12);

    ASSERT_EQ(localValue, 24);
}
