//
// Created by rahul on 5/9/2021.
//

#include "Ship.h"
#include <string>
#include <iostream>

Battleship::Ship::Ship(const char& shipType, const int& shipSize) : type(shipType), length(shipSize),
                      floatStatus(true), hitsTillDeath(shipSize), xCoordinate(0), yCoordinate(0){
}

// get ship type
char Battleship::Ship::get_type() const{
  return this->type;
}

// get ship size
int Battleship::Ship::get_size() const{
  return this->length;
}

void Battleship::Ship::update_hits_till_death() {
  this->hitsTillDeath -= 1;
  if (hitsTillDeath == 0) {
    this->floatStatus = false;
  }
}

bool Battleship::Ship::get_float_status() const {
  return this->floatStatus;
}

void Battleship::Ship::set_ship_coordinates(const int &xValue, const int &yValue) {
  this->xCoordinate = xValue;
  this->yCoordinate = yValue;
}

int Battleship::Ship::get_ship_coordinate(const std::string& coordinate) const{
  if (coordinate == "x") {
    return this->xCoordinate;
  } else if (coordinate == "y"){
    return this->yCoordinate;
  } else {
    std::cout << "Error: wrong coordinate: Ship.cpp set_ship_coordinates" << std::endl;
    exit(0);
  }
}
