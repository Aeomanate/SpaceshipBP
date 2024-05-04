include(FetchContent)

FetchContent_Declare(
        better_enums
        SOURCE_DIR ${FETCHCONTENT_BASE_DIR}/better_enums-src/better_enums
        GIT_REPOSITORY https://github.com/aantron/better-enums.git
        GIT_TAG 0.11.3
)
#FetchContent_MakeAvailable(better_enums)
if(NOT better_enums_POPULATED)
    FetchContent_Populate(better_enums)
    SET(better_enums_SOURCES ${FETCHCONTENT_BASE_DIR}/better_enums-src/better_enums/enum.h)
    add_library(better_enums INTERFACE ${better_enums_SOURCES})
endif ()

set(better_enums_INCLUDE ${FETCHCONTENT_BASE_DIR}/better_enums-src)
