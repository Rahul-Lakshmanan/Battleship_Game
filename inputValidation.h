//
// Created by rahul on 5/8/2021.
//

#ifndef BATTLESHIP__INPUTVALIDATION_H_
#define BATTLESHIP__INPUTVALIDATION_H_

#include <string>
#include "Player.h"

namespace Battleship {
bool valid_orientation(const char& userInput);
bool valid_placement_coordinates(const int& row, const int& column, const int& shipSize,
                                 const char& orientation, Player& player);
bool valid_attack_coordinate(const int& row, const int& column, const Board& placementBoard);
bool within_bounds(const int& row, const int& column, const Board& board);

void stripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
void lstripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
void rstripInPlace(std::string& string, const std::string& charsToRemove = " \t\n");
bool contains(const std::string& string, char letter);
}

#endif //BATTLESHIP__INPUTVALIDATION_H_
