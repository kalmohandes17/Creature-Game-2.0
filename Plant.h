#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"

class Plant : public Organism {
  public:
    Plant(string plantParams);

    void takeTurn(const TurnInfo &turnInfo) override; 
    Color color() const override; 

  private:
};

#endif