//
// Created by rahul on 5/9/2021.
//

#ifndef BATTLESHIP__SHIP_H_
#define BATTLESHIP__SHIP_H_

#include <string>

namespace Battleship {
class Ship {
 public:
  Ship(const char& shipType, const int& shipSize);
  char get_type() const;
  int get_size() const;
  void update_hits_till_death();
  bool get_float_status() const;
  void set_ship_coordinates(const int& xValue, const int& yValue);
  int get_ship_coordinate(const std::string& coordinate) const;
 private:
  int length;
  char type;
  bool floatStatus;
  int hitsTillDeath;
  int xCoordinate;
  int yCoordinate;
};
}

#endif //BATTLESHIP__SHIP_H_
