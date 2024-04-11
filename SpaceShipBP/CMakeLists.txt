cmake_minimum_required (VERSION 3.8)

include_directories("src/Core/include")
include_directories("src/Simulation/include")
include_directories("src/UI/include")
include_directories("src/Utility/include")

add_executable(${PROJECT_NAME}
 "src/Core/main.cpp"
 "src/Core/Application.cpp" 
 "src/Core/include/Application.h" 
 "src/Core/include/Config.h" 
 "src/Core/Config.cpp"
 
 )
 
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
install(TARGETS ${PROJECT_NAME})