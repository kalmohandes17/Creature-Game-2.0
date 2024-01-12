# Object-Project-2.0

Instructions

In this project, you will improve the simulation you built in the prior project. We'll introduce a class hierarchy and two new types of objects with which the human player will interact.

BEFORE YOU BEGIN The project relies heavily on well-built and working code from the prior project. Make sure your code from that project has been corrected according to my comments. Take advantage of the solution if you need to. Recurring issues flagged in the previous project may incur higher deductions this time.

Class Hierarchy

In the first project, we had a flat hierarchy. You built the majority of a Creature class and a CreatureList class.



Here, we will use inheritance to develop new sorts of things on the board that the human player may eat.

In this project, your Creature class from the last project will be divided into two: a base class, called Organism, which represents any living thing on the board, having a name, a glyph, a position, etc., and a derived class, still called Creature, which represents those living things on the board that can move around, expending calories.

The new Organism class will form the basis for a new derived class called Plant, which is an organism that cannot move. Plants inherit their name, glyph, location, and so on from their base class, but unlike their Creature siblings, a plant's only hope for survival is that the player dies from malnutrition before eating them.



Your old CreatureList class can be straightforwardly modified to become an OrganismList. The _creatures vector it contains will be renamed in this project, and it will become a vector of pointers to different sorts of organisms.

You might also decide to derive a new kind of Creature called a FleeingCreature. Unlike their parent class, fleeing creatures don't run around just any which way, they know the player is a predator, and they always run away from the player.

How to Complete the Project

Part A: Rough Draft

Begin with your corrected CreatureList class from the last project. Add a file to this project called OrganismList.h. Copy your CreatureList class to OrganismList.h, renaming "Creature" to "Organism" (uppercase) and "creature" to "organism" (lowercase) wherever those words appear. (There's a little arrow icon in the replit find dialog where you can toggle case sensitivity). There's one exception to the string replacement of creature: in the addOrganismsFromFile() method, as we read the input lines to create objects, we must still create creatures with new Creature(params);
Do the same with your corrected Creature class. Create a Organism.h header file in this project, copy your old class to Organism.h, and replace the string "creature" with "organism", sensitive to case. Be sure to include the TurnInfo struct declaration in the new Organism.h header.
Since Organism is abstract, add a virtual destructor. No destructor behavior is necessary, so define this method to do nothing.
Create the new Creature.h header file in this project. Data and code in this project's Creature class will be derived from the Organism class.
   class Creature : public Organism {
   };

How do creatures and organisms differ? Organism will be the base class of both Creature and Plant. It will contain everything common to both, like having a name and calories and a position on the board. Creature is a kind of organism that moves around, expends its calories, rests, and so on.

Move the running-around member variables from Organism to Creature. These are _dRow, _dCol, and _resting. Move their associated getters and setters too. You'll find that the Organism private declarations will need to become protected.
Move the Organism's constructor to the Creature class.
All organisms will be asked to takeTurn() on each turn of the main loop, but different derived classes will have different behaviors. takeTurn() will be polymorphic. Declare the organism's takeTurn() method as pure-virtual, and move its definition to your Creature class. There, indicate in the declaration that you are overriding the inherited method.
Move both the declarations and definitions of the move() and rest() methods to the Creature class.
Compile and run. With only the code from the prior project, refactored as described above, get this project to compile and run. If you get this far and get the project working, you've done 75% of the work!

Part B: Elaborate

Repackage the OrganismList, Organism, and Creature classes into separate headers and cpp files. Remember that most method definitions, with the exception of getters and setters, should be provided in the cpp files.
Add a derived subclass of Organism called Plant in new Plant.h and Plant.cpp files. Give the plant a constructor that reads only name, glyph, row, column, and calories from a string parameter.
Plant should override takeTurn(). A plant's behavior when it takes a turn is simple: it doesn't do anything. Implement this empty method.
Now that we have plants and creatures, we'll need plant and creature data. At the start of the main() function, have the organismList add organisms from a different file: creature-data-project-2.txt .
Each line in that file is prefixed with the class name of the Organism subclass that it describes. OrganismList::addOrganismsFromFile() must parse that prefix from the start of the input line and use it to determine what class to instantiate.
There are three classes mentioned in the data: Creature, Plant, and FleeingCreature. For now, ignore the FleeingCreatures.
Compile and run. You should now be able to see (and eat) plants on the board.

Optional Part C: Add Some Fun

Part C is mandatory for the honors section, optional for others

Create the FleeingCreature class, a subclass derived from the Creature class. It will override the creature's move() method, adding behavior to run away from the player who who gets too close.
To do this, the fleeing creature needs to know where the player is. Add two ints to the TurnInfo struct defined in Organism.h called playerRow and playerCol. In the main() function, find the place where the turnInfo struct is updated, and assign the current playerRow and playerCol values.
Add a method to FleeingCreature like this:
int manhattanDistanceTo(int row, int col);

Have it return the sum of the absolute distances between the creature's _row and _col position and the row and col parameters.

static const int kFleeThreshold = 6;

In it's move() method, the fleeing creature should sense danger when its distance to the player is below the threshold. Under that condition, how would you, as a FleeingCreature, run away from the player? It's simple: if the player is above you, set your _dRow = 1, if the player is below you, set _dRow = -1. Do the same for dCol by comparing your _col with the playerCol. The creature must still take care to not walk out of bounds. Figure out how to reuse the code you've already written to implement bouncing off the walls.
Add some color. Make the Organism's color() method virtual, and override it in Plant, Creature, and FleeingCreature. A good choice for plants might be green. Apply your own taste to the creatures, but make sure the FleeingCreature stands out.
Compile and run. Play a few times to see if you can figure out a sequence of moves that leaves your player with the most calories after eating everything. You're done!
