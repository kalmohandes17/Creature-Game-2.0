#include "OrganismList.h"
#include "Creature.h"
#include "Plant.h"

OrganismList::~OrganismList() {
  // Iterate the _creatures vector, deleting the creature pointers it contains
  for (int i = 0; i < _organisms.size(); i++) {
    delete _organisms.at(i);
  }
}

void OrganismList::addOrganismsFromFile(string fileName) {
  ifstream file(fileName);

  if (!file.is_open()) {
    cout << "Failed to open file" << endl;
    exit(0);
  }

  string line;
  while (getline(file, line)) {
    if (line.size() == 0 || line.find("//") == 0)
      continue;

    string organismType;
    stringstream ss(line);

    ss >> organismType;
    if (organismType == "Creature") {
      line.erase(0,organismType.size());  // DJH-2: weird, but interesting
      Creature *myCreature = new Creature(line);
      _organisms.push_back(myCreature);
    }
    else if(organismType == "Plant") {
      line.erase(0,organismType.size());
      Plant *myPlant = new Plant(line);
      _organisms.push_back(myPlant);
    }
  }
    
  file.close();
}

int OrganismList::organismCount() {
  return _organisms.size();
}

void OrganismList::setTiles(GameBoard *board) {
  // Iterate the _creatures vector, invoking the setTile() method on each one.
  for (int i = 0; i < organismCount(); ++i) {
    _organisms.at(i)->setTile(board);
  }
}

void OrganismList::clearTiles(GameBoard *board) {
  // Iterate the _creatures vector, invoking the clearTile() method on each
  // one.
  for (int i = 0; i < organismCount(); ++i) {
    _organisms.at(i)->clearTile(board);
  }
}

void OrganismList::takeTurns(const TurnInfo &turnInfo) {
  // Iterate the _creatures vector, invoking the takeTurn() method on each one.
  for (int i = 0; i < organismCount(); ++i) {
    Organism *organism = _organisms.at(i);
    organism->takeTurn(turnInfo);
  }
}

Organism* OrganismList::organismAtPosition(int row, int col) {
  // Search the _creatures vector for a Creature with matching row and col.
  // If found, return it; otherwise return nullptr.
  Organism *result = nullptr;
  for (int i = 0; i < organismCount(); ++i) {
    Organism *organism = _organisms.at(i);
    if (organism->positionEquals(row, col)) {
      result = organism;
      break;
    } 
  }
  return result;
}

void OrganismList::eraseOrganism(Organism *organism) {
  for (int index = 0; index < organismCount(); index++) {
    if (_organisms[index] == organism) {
      delete _organisms[index];
      _organisms.erase(_organisms.begin() + index);
      break;
    }
  }
}

string OrganismList::toString() {
  // Iterate the _creatures vector, calling each Creature's toString().
  // Concatenate each string on an osstringstream, placing endl's between
  // them. return the resulting string
  ostringstream oss;
  for (int i = 0; i < organismCount(); ++i) {
    oss << _organisms[i]->toString() << endl;
  }
  return oss.str();
}