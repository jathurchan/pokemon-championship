cmake_minimum_required(VERSION 3.23)
project(pokemon_championship)

set(CMAKE_CXX_STANDARD 11)

add_executable(pokemon_championship main.cpp client/link_battle_client.cpp client/link_battle_client.h server/link_battle_server.cpp server/link_battle_server.h)
