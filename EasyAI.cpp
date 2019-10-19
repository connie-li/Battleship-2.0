#include "EasyAI.h"

#include "AI.h"

string EasyAI::fire()
{
    return opponentBoard->randCoor(true);
}

EasyAI::EasyAI(Grid* grid)
{
    setGrid(grid);
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
