cmake_minimum_required (VERSION 3.11)

include_directories(
        "src/Core/include"
        "src/Simulation/include"
        "src/UI/include"
        "src/Utility/include"
        ${RAPIDJSON_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME}
    src/Core/main.cpp
    src/Core/Application.cpp
    src/Core/include/Application.h
    src/Core/include/Config.h
    src/Core/Config.cpp
    src/UI/EndGameMenu.cpp
    src/UI/include/MainMenu.h
    src/UI/MainMenu.cpp
)

add_dependencies(${PROJECT_NAME} RapidJSON)
 
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-system sfml-window sfml-graphics)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
