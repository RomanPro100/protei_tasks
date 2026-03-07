cmake_minimum_required(VERSION 3.28)
project(protei_task)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # нужно для Clangd, чтобы не выдавал ошибки include

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.x)
FetchContent_MakeAvailable(googletest)
include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR})

include_directories("include/")
set(SOURCE_LIST
    src/main.cpp
    src/readargs.cpp
    src/app_settings.cpp
)
add_executable(${PROJECT_NAME} ${SOURCE_LIST})

add_executable(test_${PROJECT_NAME} test/main.cpp src/readargs.cpp)
target_link_libraries(test_${PROJECT_NAME} gtest gtest_main)
