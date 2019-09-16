#include "map.h"
#include "ship.h"
#include <iostream>

// ~ water
//O Miss
//X Hit
//5 Carrier
//4 BattleShip
//3 Desroyer
//2 Submarine
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
  if(start[0]==end[0]) //Checks to see if they have the same number and checks the difference in the letters
  {
    if((end[1]-start[1]==length)||(start[1]-end[1]==(length-1)))
    {
      return true;
    }
  }
  if(start[1]==end[1]) //Checks to see if the letters are the same and checks the difference in the numbers
  {
    if((end[0]-start[0]==length)||(start[0]-end[0]==(length-1)))
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
  if(st==ed) //if the letters are the same
  {
    if(start[1]<end[1]) //checks if the start number is less than the end number
    {
      for(int i=0;i<(end[1]-start[1])+1;i++)
      {
        if(gridMap[start[1]-49+i][st]!='~')
        {
          return false;
        }
      }
    }
    else
    {
      for(int i=0;i<(start[1]-end[1])+1;i++)
      {
        if(gridMap[end[1]-49+i][ed]!='~')
        {
          return false;
        }
      }
    }
  }
  else //if the letters are different
  {
    if(st<ed) //checks if the start letter is less than the end letter
    {
      for(int i=0;i<(ed-st)+1;i++)
      {
        if(gridMap[start[1]-49][st+i]!='~')
        {
          return false;
        }
      }
    }
    else
    {
      for(int i=0;i<(st-ed)+1;i++)
      {
        if(gridMap[end[1]-49][ed+i]!='~')
        {
          return false;
        }
      }
    }
  }
  return true;
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
  int st; //start coordinate letter as an int
  int ed; //end coordinate letter as an int
  st = charCoordtoIntCoord(start[0]);
  ed = charCoordtoIntCoord(end[0]);
  if(st==ed) //if the letters are the same
  {
    if(start[1]<end[1]) //checks if the start number is less than the end number
    {
      for(int i=0;i<(end[1]-start[1])+1;i++)
      {
        if(((end[1]-start[1])+1)==2)
        {
          gridMap[start[1]-49+i][st]='S';
        }
        else if(((end[1]-start[1])+1)==3)
        {
          gridMap[start[1]-49+i][st]='D';
        }
        else if(((end[1]-start[1])+1)==4)
        {
          gridMap[start[1]-49+i][st]='B';
        }
        else
        {
          gridMap[start[1]-49+i][st]='C';
        }
      }
    }
    else
    {
      for(int i=0;i<(start[1]-end[1])+1;i++)
      {
        if(((start[1]-end[1])+1)==2)
        {
          gridMap[end[1]-49+i][ed]='S';
        }
        else if(((start[1]-end[1])+1)==3)
        {
          gridMap[end[1]-49+i][ed]='D';
        }
        else if(((start[1]-end[1])+1)==4)
        {
          gridMap[end[1]-49+i][ed]='B';
        }
        else
        {
          gridMap[end[1]-49+i][ed]='C';
        }
      }
    }
  }
  else //if the letters are different
  {
    if(st<ed) //checks if the start letter is less than the end letter
    {
      for(int i=0;i<(ed-st)+1;i++)
      {
        if(((end[1]-start[1])+1)==2)
        {
          gridMap[start[1]-49][st+i]='S';
        }
        else if(((end[1]-start[1])+1)==3)
        {
          gridMap[start[1]-49][st+i]='D';
        }
        else if(((end[1]-start[1])+1)==4)
        {
          gridMap[start[1]-49][st+i]='B';
        }
        else
        {
          gridMap[start[1]-49][st+i]='C';
        }
      }
    }
    else
    {
      for(int i=0;i<(st-ed)+1;i++)
      {
        if(((start[1]-end[1])+1)==2)
        {
          gridMap[end[1]-49][ed+i]='S';
        }
        else if(((start[1]-end[1])+1)==3)
        {
          gridMap[end[1]-49][ed+i]='D';
        }
        else if(((start[1]-end[1])+1)==4)
        {
          gridMap[end[1]-49][ed+i]='B';
        }
        else
        {
          gridMap[end[1]-49][ed+i]='C';
        }
      }
    }
  }
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
  for(int i=0;i<8;i++)
  {
    std::cout<< '\n';
    for(int j=0;j<8;j++)
    {
      if(gridMap[i][j]!='~'||gridMap[i][j]!='O'||gridMap[i][j]!='X')
      {
        std::cout<<"~ ";
      }
      else
      {
        std::cout<<gridMap[i][j];
        std::cout<<" ";
      }
    }
  }
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

//Fired from opponent to players board. position should already have been checked, so just go through steps to place shot.
void map::incomingShot(std::string pos)
{
  int posLetter = charCoordtoIntCoord(pos[0]);
  bool exit=false;
  while(!exit)
  {
    if(gridMap[pos[1]-49][posLetter]=='O'||gridMap[pos[1]-49][posLetter]=='X')
    {
      std::cout<<"You have already shot here. Please select another coordinate: \n";
    }
    else
    {
      exit=true;
    }
  }
  bool sunk=true;
  if(gridMap[pos[1]-49][posLetter]=='C')
  {
    std::cout<<"Hit!\n";
    gridMap[pos[1]-49][posLetter]='X';
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(gridMap[pos[1]-49][posLetter]=='C')
        {
          sunk=false;
        }
      }
    }
    if(sunk==true)
    {
      std::cout<<"You sunk my Carrier!\n";
    }
  }
  else if(gridMap[pos[1]-49][posLetter]=='B')
  {
    std::cout<<"Hit!\n";
    gridMap[pos[1]-49][posLetter]='X';
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(gridMap[pos[1]-49][posLetter]=='B')
        {
          sunk=false;
        }
      }
    }
    if(sunk==true)
    {
      std::cout<<"You sunk my Battleship!\n";
    }
  }
  else if(gridMap[pos[1]-49][posLetter]=='D')
  {
    std::cout<<"Hit!\n";
    gridMap[pos[1]-49][posLetter]='X';
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(gridMap[pos[1]-49][posLetter]=='D')
        {
          sunk=false;
        }
      }
    }
    if(sunk==true)
    {
      std::cout<<"You sunk my Destroyer!\n";
    }
  }
  else if(gridMap[pos[1]-49][posLetter]=='S')
  {
    std::cout<<"Hit!\n";
    gridMap[pos[1]-49][posLetter]='X';
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(gridMap[pos[1]-49][posLetter]=='S')
        {
          sunk=false;
        }
      }
    }
    if(sunk==true)
    {
      std::cout<<"You sunk my Carrier!\n";
    }
  }
  else if(gridMap[pos[1]-49][posLetter]=='T')
  {
    std::cout<<"Hit!\n";
    gridMap[pos[1]-49][posLetter]='X';
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(gridMap[pos[1]-49][posLetter]=='T')
        {
          sunk=false;
        }
      }
    }
    if(sunk==true)
    {
      std::cout<<"You sunk my Tug Boat!\n";
    }
  }
  else //Has to be ~ then
  {
    gridMap[pos[1]-49][posLetter]='O';
    std::cout<<"Miss!\n";
  }
}

bool map::gameOver()
{
  bool isOver = true;
  //checks if all ships are sunk.
  return(isOver);
}

map::~map()
{

}
