#ifndef ORGANISMLIST_H
#define ORGANISMLIST_H

// ====> DJH-2: -0% repeating comment. Notice how neither Creature nor Plant
// are never mentioned in this file?  The includes should move to cpp
//FIXED
#include "Organism.h"
#include <vector>


class OrganismList {
public:
  ~OrganismList();

  void addOrganismsFromFile(string fileName);
  int organismCount(); 
  void setTiles(GameBoard *board); 
  void clearTiles(GameBoard *board); 
  void takeTurns(const TurnInfo &turnInfo); 
  Organism *organismAtPosition(int row, int col); 
  void eraseOrganism(Organism *organism); 
  string toString(); 

private:
  vector<Organism *> _organisms;
};

#endif