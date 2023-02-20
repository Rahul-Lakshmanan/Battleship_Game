//
// Created by Christina Lei on 5/4/21.
//

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "read.h"
#include "Ship.h"

std::vector<Battleship::Ship> Battleship::readFile(char** argv, int& numRow, int& numCol, int& numShips,
                                                   std::vector<Ship>& ships) {
  // declare variable
  std::vector<std::string> shipType;
  std::vector<int> shipSize;
  std::vector<std::string> shipInfo;
  std::string word;

  // open configuration file
  std::ifstream shipFile(argv[1]);

  // read file
  while (shipFile >> word) {
    shipInfo.push_back(word);
  }

  // get board size and number of ships
  numRow = std::stoi(shipInfo.at(0));
  numCol = std::stoi(shipInfo.at(1));
  numShips = std::stoi(shipInfo.at(2));

  // get ships
  for (int i = 3; i < (numShips * 2) + 2; i += 2) {
    shipType.push_back(shipInfo.at(i));
    shipSize.push_back(std::stoi(shipInfo.at(i + 1)));
  }

  // store ship size and type into same vector
  fill_ship_vector(ships, shipType, shipSize, numShips);

  // close file
  shipFile.close();

  return ships;
}

// store ship type and size
void Battleship::fill_ship_vector(std::vector<Ship>& ships, const std::vector<std::string>& shipType,
                                  const std::vector<int>& shipSize, const int& numShips) {
  std::string type;

  for (int i = 0; i < numShips; ++i) {
    type = shipType.at(i);
    ships.emplace_back(type.at(0), shipSize.at(i)); // pushes back type and size of each ship to vector ship
  }
}
