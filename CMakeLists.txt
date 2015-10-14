cmake_minimum_required(VERSION 3.3)
project(Scheduler_Simulation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Queue.cpp Queue.h Process.cpp Process.h Scheduler.h FCFSScheduler.cpp FCFSScheduler.h)
add_executable(Scheduler_Simulation ${SOURCE_FILES})