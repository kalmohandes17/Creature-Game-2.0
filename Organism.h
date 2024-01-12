#ifndef ORGANISM_H
#define ORGANISM_H

#include "GameBoard.h"

// ====> DJH-2: -2% Unnecessary includes in .h file. There's an opportunity to move most of these included headers into the cpp. Find out by skimming the code or commenting and moving one at a time and seeing if it compiles

#include <string> 
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
/*****************************************************************************/
// TurnInfo
//
// This struct contains parameters required for a Creature to take its turn.
// In this project, it contains just the board dimensions; but the structure
// allows us the opportunity to change this later without changing method
// signatures.
/*****************************************************************************/

struct TurnInfo {
  int rowCount;
  int colCount;
};

/*****************************************************************************/
// Creature
/*****************************************************************************/

class Organism {
public:
  Organism() = default;

  virtual ~Organism(); 

  bool positionEquals(int row, int col); 
  virtual void takeTurn(const TurnInfo &turnInfo) = 0;

  // ====> DJH-2: -3% setTile can/should be inherited by subclasses. Why would we
  // I see your thought process now.  The thing that should be marked virtual
  // and overriden was (is) the color method
  // designated it as virtual or pure virtual?
  void setTile(GameBoard *board) const;
  void clearTile(GameBoard *board) const; 
  string toString() const; 
  virtual Color color() const; 

  string name() const { return _name; }
  char glyph() const { return _glyph; }
  int row() const { return _row; }
  int col() const { return _col; }
  int calories() const { return _calories; }
  int initialCalories() const { return _initialCalories; }

protected:

  string _name = "Unkown";
  char _glyph = '?';
  int _row = 0;
  int _col = 0;
  int _calories = 0;
  int _initialCalories = 0;

  void setName(string name) { _name = name; }
  void setGlyph(char glyph) { _glyph = glyph; }
  void setRow(int row) { _row = row; }
  void setCol(int col) { _col = col; }
  void setCalories(int calories) { _calories = calories; }
  void setInitialCalories(int initialCalories) {
   _initialCalories = initialCalories;
  }
};

#endif