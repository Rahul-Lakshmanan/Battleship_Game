//
// Created by rahul on 5/7/2021.
//

#ifndef BATTLESHIP__PLAYER_H_
#define BATTLESHIP__PLAYER_H_

#include <string>
#include <vector>
#include "board.h"

namespace Battleship {
class Ship;
class Player {
 public:
  Player(std::vector<Ship>& ship, const int& numRows, const int& numColumns);
  std::string attack(const int& row, const int& column, Player& victim);
  void set_name(const std::string& playerName);
  std::string get_name();
  std::vector<Battleship::Ship>& get_ships();
  Board& get_board(const std::string& type);

 private:
  std::string name;
  std::vector<Ship> playerShips;
  Board placementBoard;
  Board firingBoard;
};

}

#endif //BATTLESHIP__PLAYER_H_
