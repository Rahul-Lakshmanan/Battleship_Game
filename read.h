//
// Created by Christina Lei on 5/4/21.
//

#ifndef BATTLESHIP_READ_H
#define BATTLESHIP_READ_H

#include <vector>
#include <string>

namespace Battleship {
class Ship;
std::vector<Ship> readFile(char** argv, int& numRow, int& numCol, int& numShips,
                           std::vector<Ship>& ships);
void fill_ship_vector(std::vector<Ship>& ships, const std::vector<std::string>& shipType,
                      const std::vector<int>& shipSize, const int& numShips);
}

#endif //BATTLESHIP_READ_H
