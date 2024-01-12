#include "Creature.h"

static const int increaseCalories = 5;
static const double kRestingRatio = 0.75;
static const int kCreatureCaloriesPerMove = 5;

Creature::Creature(string creatureParams) {
  stringstream ss(creatureParams);
  
  ss >> _name >> _glyph >> _row >> _col >> _dRow >> _dCol >> _calories;
  _initialCalories = _calories;
}

void Creature::takeTurn(const TurnInfo &turnInfo) {
  if (_resting) {
    rest();
  } else {
    move(turnInfo);
  }
}

// ====> DJH-2: See how this almost matches the method in Plant?
// The difference is color, so that's where the differentiation should be
Color Creature::color() const {
  // set a tile representing the creature's current state on the game board
  return Color::magenta;
}

void Creature::move(const TurnInfo &turnInfo) {
  int candidateRow = _row + _dRow;
  if (candidateRow < 0 || candidateRow >= turnInfo.rowCount) {
    _dRow *= -1;
    candidateRow = _row + _dRow;
  }
  int candidateCol = _col + _dCol;
  if (candidateCol < 0 || candidateCol >= turnInfo.colCount) {
    _dCol *= -1;
    candidateCol = _col + _dCol;
  }
  if (_row != candidateRow || _col != candidateCol) {
    _row = candidateRow;
    _col = candidateCol;
    _calories -= kCreatureCaloriesPerMove;
    if (_calories <= 0) {
      _resting = true;
    }
  }
}

void Creature::rest() {
  _calories += increaseCalories;
  if (_calories > _initialCalories * kRestingRatio) {
    _resting = false;
  }
}

// ====> DJH-2: -0% repeating the comment to inline setters and getters

//FIXED
