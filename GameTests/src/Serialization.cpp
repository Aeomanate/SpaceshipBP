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

    SERI_V(std::string, value1,  { });
    SERI_V(int32_t    , value2,  0);
    SERI_V(int64_t    , value3,  0);
    SERI_V(uint32_t   , value4,  0);
    SERI_V(uint64_t   , value5,  0);
    SERI_V(double     , value6,  0);
    SERI_V(float      , value7,  0);
    SERI_V(bool       , value8,  0);
    // SERI_V(int8_t     , value9,  0); // Doesn't implemented in RapidJSON
    // SERI_V(int16_t    , value10, 0); // Doesn't implemented in RapidJSON
    // SERI_V(uint8_t    , value11, 0); // Doesn't implemented in RapidJSON
    // SERI_V(uint16_t   , value12, 0); // Doesn't implemented in RapidJSON
};
SERI_S(Outer)
{
    SERI_C(Outer)
    SERI_COMPOSITE_V(Inner, compositeStruct1);
    SERI_COMPOSITE_V(Inner, compositeStruct2);
};
SERI_S(OuterOuter)
{
    SERI_C(OuterOuter)
    SERI_COMPOSITE_V(Outer, compositeStruct1);
    SERI_COMPOSITE_V(Outer, compositeStruct2);
};
SERI_S(OuterOuterOuter)
{
    SERI_C(OuterOuterOuter)
    SERI_COMPOSITE_V(OuterOuter, compositeStruct1);
    SERI_COMPOSITE_V(OuterOuter, compositeStruct2);
};

TEST(UtilitySuite, SerializationComposite)
{
    OuterOuterOuter myRoot = { "myRoot" "ROOT" };

    std::stringstream stream;

    stream << myRoot;

    std::string json = stream.str();

    stream >> myRoot;

    ASSERT_EQ(myRoot.HasParseError(), false);
}
