cmake_minimum_required(VERSION 3.23)
project(pokemon_championship)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemon_championship main.cpp server.cpp client.cpp server2.cpp)
