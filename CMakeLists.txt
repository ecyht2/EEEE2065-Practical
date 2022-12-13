cmake_minimum_required(VERSION 3.21.1)

# Configure project paths
project(EEEE2065-Practical VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)

# Exporting compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG})
add_compile_options(-Wall)

# Adding Directories
add_subdirectory(Practical-1)
add_subdirectory(Practical-2)
add_subdirectory(Practical-3)
add_subdirectory(Practical-4)
add_subdirectory(Practical-5)
add_subdirectory(Practical-6)
add_subdirectory(Practical-7)
add_subdirectory(Practical-8)
