#include "Plant.h"

Plant::Plant(string plantParams) {
  stringstream ss(plantParams);

  ss >> _name >> _glyph >> _row >> _col >> _calories;
  _initialCalories = _calories;
}

void Plant::takeTurn(const TurnInfo &turnInfo) {}

Color Plant::color() const {
  // set a tile representing the creature's current state on the game board
  return Color::green;
}