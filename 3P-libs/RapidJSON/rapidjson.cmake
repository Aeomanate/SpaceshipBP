include(ExternalProject)
ExternalProject_Add(
        RapidJSON
        PREFIX "_deps/rapidjson"
        GIT_REPOSITORY "https://github.com/Tencent/rapidjson.git"
        GIT_TAG ab1842a2dae061284c0a62dca1cc6d5e7e37e346
        TIMEOUT 10
        CMAKE_ARGS
        -DRAPIDJSON_BUILD_TESTS=OFF
        -DRAPIDJSON_BUILD_DOC=OFF
        -DRAPIDJSON_BUILD_EXAMPLES=OFF
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        UPDATE_COMMAND ""
)
# Prepare RapidJSON
ExternalProject_Get_Property(RapidJSON SOURCE_DIR)
set(RAPIDJSON_INCLUDE_DIR ${SOURCE_DIR}/include)

include_directories(SYSTEM ${RAPIDJSON_INCLUDE_DIR})
