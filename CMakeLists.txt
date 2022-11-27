cmake_minimum_required(VERSION 3.23)
project(Project_Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_Lab main.cpp include/player.h include/board.h include/token.h include/menu.h)
