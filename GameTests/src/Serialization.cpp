#include <string>
#include <sstream>
#include <gtest/gtest.h>
#include <Utility/Serialization/Serializable.h>
#include "Core/Storage/GameJsonConversions.h"

template <class T>
struct CustomStruct
{
    T value;
};

SERI_S(SomeStruct)
{
    SERI_C(SomeStruct)
};

TEST(UtilitySuite, SerializationCustomType)
{
    auto g = [] <class T> {
        SERI_ROOT_V(SomeStruct, someStruct);
        std::stringstream stream;
        stream << someStruct;
        stream >> someStruct;
        ASSERT_EQ(someStruct.HasParseError(), false);
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


SERI_S(Inner)
{
    SERI_C(Inner)
    SERI_V(int, someNumber1, 123);
    SERI_V(int, someNumber2, 123);
};
SERI_S(Outer)
{
    SERI_C(Outer)
    SERI_COMPOSITE_V(Inner, compositeStruct1);
    SERI_COMPOSITE_V_MEMBERS_INIT(
        Inner, compositeStruct2,
        777
    );
};

TEST(UtilitySuite, SerializationComposite)
{
    SERI_ROOT_V(Outer, myRoot);

    std::stringstream stream;

    stream << myRoot;

    std::string json = stream.str(); //-V808

    stream >> myRoot;

    ASSERT_EQ(myRoot.HasParseError(), false);
}
