#ifndef CREATURE_H
#define CREATURE_H
#include "Organism.h"

class Creature : public Organism {
public:
  Creature(string creatureParams);

  void takeTurn(const TurnInfo &turnInfo) override; 
  Color color() const override; 
  void move(const TurnInfo &turnInfo);
  void rest();

  int dRow() const { return _dRow; }
  int dCol() const { return _dCol; }
  int resting() const { return _resting; }

private:
  int _dRow = 0;
  int _dCol = 0;
  bool _resting = false;

  void setDRow(int dRow) { _dRow = dRow; }
  void setDCol(int dCol) { _dCol = dCol; }
  void setResting(bool resting) { _resting = resting; }
};

#endif