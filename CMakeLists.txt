cmake_minimum_required(VERSION 3.23)
project(BACKGAMMON_SIMULATOR)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(BACKGAMMON_SIMULATOR main.cpp include/player.h include/board.h include/token.h include/menu.h include/constants.h include/dice.h src/menu.cpp src/board.cpp src/constants.cpp src/player.cpp src/dice.cpp)
