//
// Created by rahul on 5/7/2021.
//

#include <iostream>
#include <sstream>
#include "Player.h"
#include "Ship.h"

Battleship::Player::Player(std::vector<Ship>& ship, const int& numRows, const int& numColumns) :
                          playerShips(ship), placementBoard(numRows, numColumns), firingBoard(numRows, numColumns){}

// player move to attack, see if it's a hit or miss
std::string Battleship::Player::attack(const int& row, const int& column, Player& victim) {
  std::ostringstream statement;
  std::string message;

  if (victim.get_board("placement").get_piece(row, column) != '*') {
    for (int i = 0; i < victim.get_ships().size(); ++i) {
      if (victim.get_ships().at(i).get_type() == victim.get_board("placement").get_piece(row, column)) {
        victim.get_board("placement").set_piece(row, column, 'X');
        this->get_board("firing").set_piece(row, column, 'X');

        victim.get_ships().at(i).update_hits_till_death();
        victim.get_ships().at(i).update_hits_till_death();
        bool shipSunk = victim.get_ships().at(i).get_float_status();

        if (shipSunk) {
            statement << this->get_name() << " hit " << victim.get_name() << "'s " << victim.get_ships().at(i).get_type()
                      << "!" << std::endl;
            message = statement.str();
            return message;
        } else {
            statement << this->get_name() << " hit " << victim.get_name() << "'s " << victim.get_ships().at(i).get_type()
                      << "!\n" << this->get_name() << " destroyed " << victim.get_name() << "'s "
                      << victim.get_ships().at(i).get_type() << "!\n";
            message = statement.str();
            return message;
        } /*else {
            std::cout << "Something went wrong?" << std::endl;
            exit(0);
        } */
      }
    }
    std::cout << "Error: hit an 'X' or 'O': Player.cpp attack()" << std::endl;
    exit(0);
  } else {
      victim.get_board("placement").set_piece(row, column, 'O');
      this->get_board("firing").set_piece(row, column, 'O');
      message = "Missed.";
  }
  return message;
}

void Battleship::Player::set_name(const std::string& playerName) {
  this->name = playerName;
}

std::string Battleship::Player::get_name() {
  return this->name;
}
std::vector<Battleship::Ship>& Battleship::Player::get_ships() {
  return this->playerShips;
}

Battleship::Board& Battleship::Player::get_board(const std::string& type) {
  if (type == "placement") {
    return this->placementBoard;
  } else if (type == "firing") {
    return this->firingBoard;
  } else {
    std::cout << "Error: wrong board type: Player.cpp get_board()" << std::endl;
    exit(0);
  }
}
