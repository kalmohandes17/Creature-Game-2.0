#include "GameBoard.h"
#include "Creature.h"
#include "OrganismList.h"

#include <cmath>
#include <iostream>
#include <string>
using namespace std;



static const int kInitialPlayerCalories = 120;
static const int kPlayerCaloriesPerMove = 5;

/*****************************************************************************/
// Utils
/*****************************************************************************/

string MessageLine(OrganismList *organismList, int playerCalories, string status = "") {
  ostringstream oss;
  oss << "Player has " << playerCalories << " cals";
  if (status.length()) oss << ". " << status << endl;
  else oss << endl;

  oss << endl << organismList->toString() << endl;
  return oss.str();
}

/*****************************************************************************/
// main / controller
/*****************************************************************************/

int main() {
  bool gameOver = false;
  int turnCount = 0;
  string status = "";

  const int kBoardRowCount = 20;
  const int kBoardColCount = 30;
  GameBoard board(kBoardRowCount, kBoardColCount);
  board.setDisplayCoords(false);

  int playerRow = 5;
  int playerCol = 5;
  int playerCalories = kInitialPlayerCalories;

  OrganismList organismList;
  organismList.addOrganismsFromFile("creature-data-project-2.txt");
  // organismList.addOrganismsFromFile("creature-data-project-2.txt");

  TurnInfo turnInfo{};

  while (!gameOver) {
    // set board tiles and message to the current status
    organismList.setTiles(&board);
    board.setTileAt(playerRow, playerCol, '@', Color::defaultColor);
    board.setMessage(MessageLine(&organismList, playerCalories, status));
    status = "";
    
    // draw the tiles and status on the console
    board.updateConsole();

    // clear tiles
    board.clearTileAt(playerRow, playerCol);
    organismList.clearTiles(&board);

    // get user input
    char cmd = board.nextCommandKey();

    bool playerMoved = false;

    // move everything that might move: first, the player
    switch (cmd) {
    case arrowUpKey:
      if (playerRow > 0) {
        playerMoved = true;
        --playerRow;
      }
      break;
    case arrowDownKey:
      if (playerRow + 1 < board.rowCount()) {
        playerMoved = true;
        ++playerRow;
      }
      break;
    case arrowRightKey:
      if (playerCol + 1 < board.colCount()) {
        playerMoved = true;
        ++playerCol;
      }
      break;
    case arrowLeftKey:
      if (playerCol > 0) {
        playerMoved = true;
        --playerCol;
      }
      break;
    case 'q':
    case 'Q':
      cout << "Bye" << endl;
      gameOver = true;
      break;
    default:
      break;
    }
    if (playerMoved) {
      playerCalories -= kPlayerCaloriesPerMove;
    }

    turnInfo = { board.rowCount(), board.colCount() };
    organismList.takeTurns(turnInfo);

    // the player and creatures may have moved. find out if a creature  occupies
    // the same position as the player. if so, the player will eat it
    Organism *organismToEat =
        organismList.organismAtPosition(playerRow, playerCol);
    if (organismToEat) {
      status = "Ate the " + organismToEat->name();
      playerCalories += organismToEat->calories();
      organismList.eraseOrganism(organismToEat);
      if (organismList.organismCount() == 0) {
        status = "Having eaten everything, player wins!";
        gameOver = true;
      }
    }

    if (playerCalories <= 0) {
      status = "Having starved, player dies.";
      gameOver = true;
    }

    ++turnCount;
  }
  organismList.setTiles(&board);
  board.setTileAt(playerRow, playerCol, '@', defaultColor);
  board.setMessage(MessageLine(&organismList, playerCalories, status));
  board.updateConsole();
}

// ====> DJH-2: Pretty good project, Khaled.
// The big decrement should be -20% for missing the extended deadline.
// I will count that as -10% this time.
// Total is -4% on the merits, -10 = 86/100