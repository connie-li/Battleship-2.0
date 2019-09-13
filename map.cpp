#include "map.h"
#include "ship.h"
#include <iostream>

map::map(int shipNum)
{
  //based on ship implemenation, perhaps ships could be placed in this function.
}

//check length is 2, first coordinate, second coordinate
bool map::validPos(std::string pos)
{
  if(pos.length()==2)
  {
    if(pos[0]=='A'||pos[0]=='B'||pos[0]=='C'||pos[0]=='D'||pos[0]=='E'||pos[0]=='F'||pos[0]=='G'||pos[0]=='H')
    {
      if(pos[1]=='1'||pos[1]=='2'||pos[1]=='3'||pos[1]=='4'||pos[1]=='5'||pos[1]=='6'||pos[1]=='7'||pos[1]=='8')
      {
        return true;
      }
    }
  }
  return false;
}

void map::printEnemyShotMap()
{
    //cout with grid format but if a ship icon is seen, change to empty water. For opponent.
}

void map::printCurrentMap()
{
  //cout with grid format untouched. For player
}

void map::incomingShot(std::string pos)
{
  //Fired from opponent to players board. position should already have been checked, so just go through steps to place shot.
}

bool gameOver()
{
  bool isOver = true;
  //checks if all ships are sunk.
  return(isOver);
}

map::~map()
{

}
