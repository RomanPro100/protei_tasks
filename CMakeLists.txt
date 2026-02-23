cmake_minimum_required(VERSION 3.28)
project(task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # нужно для Clangd, чтобы не выдавал ошибки include

include_directories("include/")
set(SOURCE_LIST src/main.cpp src/readargs.cpp)
add_executable(task1 ${SOURCE_LIST})
