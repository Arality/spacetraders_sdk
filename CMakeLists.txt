# Cmake version
cmake_minimum_required(VERSION 3.30)

# Set c++ standard
set(CMAKE_CXX_STANDARD 23)

# Project name
project(Template)

# Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Add subdirectories
add_subdirectory(src)
target_include_directories(main_lib PUBLIC include)

# Fetch Content
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Debugger options
add_compile_options(-Wall -Wextra -Werror -Wconversion -Wformat)
# Testing
enable_testing()
add_subdirectory(tests)
target_include_directories(tests PUBLIC include)
