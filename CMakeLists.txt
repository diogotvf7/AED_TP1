cmake_minimum_required(VERSION 3.23)
project(AED_TP1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(AED_TP1
        src/Class.cpp
        src/Class.h
        src/main.cpp
        src/ScheduleManager.cpp
        src/ScheduleManager.h
        src/Slot.cpp
        src/Slot.h
        src/Student.cpp
        src/Student.h)
