#include "EasyAI.h"

#include "AI.h"

string EasyAI::fire()
{
    return opponentBoard->randCoor(true);
}

EasyAI::EasyAI()
{
    
}


EasyAI::~EasyAI()
{

}
