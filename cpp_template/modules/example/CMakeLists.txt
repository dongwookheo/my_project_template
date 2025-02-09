cmake_minimum_required(VERSION 3.11)

set(LIBRARY_NAME PROJECT_MODULE_EXAMPLE)
set(LIBRARY_VERSION 1.0.0)

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(${LIBRARY_NAME}_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(${LIBRARY_NAME}_INCLUDE_DIRS "${${LIBRARY_NAME}_PATH}/include")
set(${LIBRARY_NAME}_SOURCE_DIRS "${${LIBRARY_NAME}_PATH}/src")

message(STATUS "Library name: ${LIBRARY_NAME}")
message(STATUS "Library version: ${LIBRARY_VERSION}")
message(STATUS "Library path: ${${LIBRARY_NAME}_PATH}")
message(STATUS "Library include directories: ${${LIBRARY_NAME}_INCLUDE_DIRS}")
message(STATUS "Library source directories: ${${LIBRARY_NAME}_SOURCE_DIRS}\n")

set(${LIBRARY_NAME}_HEADERS
    "${${LIBRARY_NAME}_INCLUDE_DIRS}/hello.hpp"
)
set(${LIBRARY_NAME}_SOURCES
    "${${LIBRARY_NAME}_SOURCE_DIRS}/hello.cpp"
)

# SHARED: dynamic library (Linux: .so, Windows: .dll)
# - Dynamic libraries are shared libraries that can be loaded at runtime.
# - Pros: smaller executable size, easier to update, easier to share code between multiple executables.
# STATIC: static library (Linux: .a, Windows: .lib)
# - Static libraries are linked at compile time.
# - Pros: faster execution, easier to distribute, easier to deploy.
add_library(${LIBRARY_NAME} SHARED
    ${${LIBRARY_NAME}_SOURCES}
)

# Include directories
# - Announced to here that the include directories are in the include folder.
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${${LIBRARY_NAME}_INCLUDE_DIRS}
)

# Compile options
# - Wall: Enable all warnings.
# - Wextra: Enable extra warnings.
# - Wpedantic: Enable pedantic warnings.
# - Werror: Treat warnings as errors.
target_compile_options(
    ${LIBRARY_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror
)
