cmake_minimum_required(VERSION 3.20)
project(cache_sim)

set(CMAKE_CXX_STANDARD 14)

add_executable(cache_sim main.cpp CacheSim.cpp CacheSim.h)
