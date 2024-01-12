#include "Organism.h"


// ====> DJH-2: -1% Should be inlined, per classroom instruction
//FIXED

Organism::~Organism() {}

// return true if the Creature's position equals the passed position.
bool Organism::positionEquals(int row, int col) { 
  return _row == row && _col == col; 
}

void Organism::clearTile(GameBoard *board) const {
  // clear a tile representing the creature's current state on the game board
  board->clearTileAt(_row, _col);
}

void Organism::setTile(GameBoard *board) const {
  // clear a tile representing the creature's current state on the game board
  board->setTileAt(_row, _col, _glyph, color());
}
string Organism::toString() const {
  ostringstream oss;
  oss << left << setw(16) << _name << "(" << _glyph << ") " << " " <<      _calories << setw(16);
  return oss.str();
}

// ====> DJH-2: -0% Can be inlined, per classroom instruction
Color Organism::color() const { return Color::blue; }

// ====> DJH-2: -1% Should be inlined, per classroom instruction
//FIXED

