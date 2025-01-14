cmake_minimum_required(VERSION 3.19)
set (CMAKE_CXX_STANDARD 17)


# Project Name
project(MyMathLibrary VERSION 1.0.0 LANGUAGES CXX)

# Set MinGW path
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(GTEST_INCLUDE_DIR "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/include")
set(GTEST_LIBRARY "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/libgtest_main.a")

enable_testing()

include_directories(include)

# Source Files
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

find_package(GTest REQUIRED)

# # Add Google Test executable
add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)


# Add the library
add_library(MyMath STATIC src/MyMath.cpp)

# Include directories for the library
# target_include_directories(MyMath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(MyMath INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Installation rules
install(TARGETS MyMath
        EXPORT MyMathTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# Export the package
export(EXPORT MyMathTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/MyMathTargets.cmake"
       NAMESPACE MyMath::)

# Create a Config file for the package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/MyMathConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_file(MyMathConfig.cmake.in
               "${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake"
               @ONLY)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/MyMathConfigVersion.cmake"
        DESTINATION lib/cmake/MyMath)

install(EXPORT MyMathTargets
        FILE MyMathTargets.cmake
        NAMESPACE MyMath::
        DESTINATION lib/cmake/MyMath)