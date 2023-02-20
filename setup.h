//
// Created by Christina Lei on 5/5/21.
//

#ifndef BATTLESHIP_SETUP_H
#define BATTLESHIP_SETUP_H

#include <string>
#include <vector>

namespace Battleship {
class Ship;
class Player;
class Board;

void setup_game(Player& player1, Player& player2);
void place_ship(Player& player, const int& shipSize, const int& i);
void get_name(Player& player, const int& playerNumber);
char get_orientation(const std::string& playerName, const char& shipType);
bool get_placement_coordinates(int& rowCoordinate, int& columnCoordinate, Player& player, const char& shipType,
                               const int& shipSize, const char& orientation);
}

#endif //BATTLESHIP_SETUP_H
