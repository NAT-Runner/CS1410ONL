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
