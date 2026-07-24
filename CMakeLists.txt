cmake_minimum_required(VERSION 3.28)
project(cpp_starter_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Project structure:
#   - Header files (.h)  → include/
#   - Source files (.cpp) → src/
#
# Add one line per program. For programs with multiple .cpp files,
# list them all space-separated after the program name.
# After any change to this file, re-run: cmake .. (from the build/ folder)
#
# Examples:
#   add_executable(main src/main.cpp)
#   add_executable(a1 src/assignmeht1.cpp)
#   add_executable(lab2 src/lab2.cpp src/helpers.cpp)
add_executable(main src/main.cpp)
add_executable(a2 src/a2.cpp)
add_executable(a3 src/a3.cpp)
add_executable(a5 src/a5.cpp src/string_maker.cpp)
add_executable(a6 src/a6.cpp src/circle.cpp src/rectangle.cpp src/triangle.cpp)
configure_file(
    ${CMAKE_SOURCE_DIR}/resources/shapes.txt
    ${CMAKE_BINARY_DIR}/shapes.txt
    COPYONLY
)