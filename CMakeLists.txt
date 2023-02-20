cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp read.cpp read.h board.cpp board.h setup.cpp setup.h Player.cpp Player.h
        inputValidation.cpp inputValidation.h game.cpp game.h Ship.cpp Ship.h gameOver.cpp gameOver.h)
