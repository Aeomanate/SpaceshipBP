#include <gtest/gtest.h>
#include <Core/EventsHandling/ListenersEmitters.h>
#include <Utility/Serialization/Serializable.h>
#include "Core/Storage/UserJsonConversions.h"
#include <rapidjson/document.h>

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

TEST(UtilitySuite, Serialization)
{
    auto g = [] <class T> ()
    {
        rapidjson::Value v;
        Serialization::SerializableVariable<T, UserJsonConversions> name { "name", T{ } };
    };

    g.operator()<std::string>();
    // g.operator()<int8_t>();    // Doesn't implemented in RapidJSON
    // g.operator()<int16_t>();   // Doesn't implemented in RapidJSON
    g.operator()<int32_t>();
    g.operator()<int64_t>();
    // g.operator()<uint8_t>();   // Doesn't implemented in RapidJSON
    // g.operator()<uint16_t>();  // Doesn't implemented in RapidJSON
    g.operator()<uint32_t>();
    g.operator()<uint64_t>();
    g.operator()<double>();
    g.operator()<float>();
    g.operator()<bool>();
    // g.operator()<void>();      // Doesn't implemented in RapidJSON
    // g.operator()<nullptr_t>(); // Doesn't implemented in RapidJSON


}
