#include "EasyAI.h"

string EasyAI::fire()
{
    return opponentBoard->randCoor(true);
}

EasyAI::EasyAI(Grid* grid)
{
	opponentBoard = grid;
}

EasyAI::EasyAI(Grid* grid, int numShips)
{
    setGrid(grid);
    m_numShips = numShips;
    m_numAfloat = numShips;
}

void EasyAI::setGrid(Grid* grid)
{
    opponentBoard = grid;
}

Grid* EasyAI::getGrid()
{
    return opponentBoard;
}

EasyAI::~EasyAI()
{

}
