cmake_minimum_required(VERSION 3.24)

project("What Runs All Day But Has No Legs")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp src/my_clock.cpp
        src/my_time_logic.cpp
)
