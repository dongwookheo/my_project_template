cmake_minimum_required(VERSION 3.11)

set(PACKAGE_NAME CPP_PROJECT_TEMPLATE)
set(PACKAGE_VERSION 0.1.0)

project(${PACKAGE_NAME} VERSION ${PACKAGE_VERSION} LANGUAGES CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
# The C++ standard is required, so if the compiler does not support C++17, the build will fail.
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Do not enable compiler-specific extensions. This ensures that the code is portable.
set(CMAKE_CXX_EXTENSIONS OFF)

set(${PACKAGE_NAME}_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(${PACKAGE_NAME}_SOURCE_PATH "${${PACKAGE_NAME}_PATH}/src")
set(${PACKAGE_NAME}_TEST_PATH "${${PACKAGE_NAME}_PATH}/test")
set(${PACKAGE_NAME}_CONFIG_PATH "${${PACKAGE_NAME}_PATH}/config")
set(${PACKAGE_NAME}_MODULE_PATH "${${PACKAGE_NAME}_PATH}/modules")
set(${PACKAGE_NAME}_THIRDPARTY_PATH "${${PACKAGE_NAME}_PATH}/thirdparty")

message(STATUS "Package name: ${PACKAGE_NAME}")
message(STATUS "Package version: ${PACKAGE_VERSION}")
message(STATUS "Package path: ${${PACKAGE_NAME}_PATH}")
message(STATUS "Package source directories: ${${PACKAGE_NAME}_SOURCE_PATH}")
message(STATUS "Package test directories: ${${PACKAGE_NAME}_TEST_PATH}")
message(STATUS "Package config directories: ${${PACKAGE_NAME}_CONFIG_PATH}")
message(STATUS "Package module directories: ${${PACKAGE_NAME}_MODULE_PATH}")
message(STATUS "Package thirdparty directories: ${${PACKAGE_NAME}_THIRDPARTY_PATH}\n")

#add_subdirectory(${${PACKAGE_NAME}_THIRDPARTY_PATH})
add_subdirectory(${${PACKAGE_NAME}_MODULE_PATH})

add_executable(MAIN ${${PACKAGE_NAME}_SOURCE_PATH}/main.cpp)
target_link_libraries(MAIN PRIVATE PROJECT_MODULE_EXAMPLE)

target_compile_options(MAIN PRIVATE -Wall -Wextra -Wpedantic -Werror)