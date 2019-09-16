#include "map.h"
#include "ship.h"
#include <iostream>

// ~ water
//O Miss
//X Hit
//5 Carrier
//4 BattleShip
//3 Cruiser
//2 Desroyer
//1 Tug
map::map(int shipNum)
{
  for(int i=0;i<8;i++) //Creating the 2D array
  {
    for(int j=0;j<8;j++)
    {
      gridMap[i][j]='~';
    }
  }
  std::string tempCoordStart;
  std::string tempCoordEnd;
  for(int i=shipNum;i>0;i--) //Filling the Array with ships
  {
    std::cout<<"Please input the starting coordinate for your "<<i<<"x1 ship.\nThis would take the form of an UPPERCASE letter and a number. Ex: A3\n";
    std::cin>>tempCoordStart;
    bool exit=false;
    while(!exit) //Checks the first Coordinate
    {
      if(!validPos(tempCoordStart))
      {
        std::cout<<"Invalid coordinate. Please inout another: \n";
        std::cin>>tempCoordStart;
      }
      else
      {
        exit=true;
      }
    }
    exit=false;
    std::cin>>tempCoordEnd;
    while(!exit) //Checks the Second Coordinate
    {
      if(!validPos(tempCoordEnd))
      {
        std::cout<<"Invalid coordinate. Please inout another: \n";
        std::cin>>tempCoordEnd;
      }
      else
      {
        exit=true;
      }
      if(tempCoordStart[0]==tempCoordEnd[0]||tempCoordStart[1]==tempCoordEnd[1])//Checks if it a Strait line
      {
        if(checkShipLength(tempCoordStart, tempCoordEnd, i))//Checks if the Ship is the correct length
        {
          if(checkShipPosition(tempCoordStart, tempCoordEnd))//Checks if the ship position is valid
          {
            addShip(tempCoordStart, tempCoordEnd);
          }
        }
      }
    }
  }
}

bool map::checkShipLength(std::string start, std::string end, int length)
{
  if(start[0]==end[0]) //Checks to see if they have the same letter and checks the difference in the numbers
  {
    if((end[1]-start[1]==length)||(start[1]-end[1]==length))
    {
      return true;
    }
  }
  if(start[1]==end[1]) //Checks to see if the number is the same and checks the difference in the letters
  {
    if((end[0]-start[0]==length)||(start[0]-end[1]==length))
    {
      return true;
    }
  }
  return false;
}

bool map::checkShipPosition(std::string start, std::string end) //finish this after fixing coordinate system
{
  int st; //start coordinate letter as an int
  int ed; //end coordinate letter as an int
  st = charCoordtoIntCoord(start[0]);
  ed = charCoordtoIntCoord(end[0]);
  if(st==ed)
  {
    if(start[1]<end[1])
    {

    }//Checks if the start coordinate is
  }
}

int map::charCoordtoIntCoord(char c)
{
  if(c=='A')
  {
    return 0;
  }
  if(c=='B')
  {
    return 1;
  }
  if(c=='C')
  {
    return 2;
  }
  if(c=='D')
  {
    return 3;
  }
  if(c=='E')
  {
    return 4;
  }
  if(c=='F')
  {
    return 5;
  }
  if(c=='G')
  {
    return 6;
  }
  if(c=='H')
  {
    return 7;
  }
}

void map::addShip(std::string start, std::string end)
{

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
  for(int i=0;i<8;i++)
  {
    std::cout<< '\n';
    for(int j=0;j<8;j++)
    {
      std::cout<<gridMap[i][j];
      std::cout<<" ";
    }
  }
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
