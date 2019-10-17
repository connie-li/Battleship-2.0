#include "AI.h"

void AI::easyFire()
{
    string shot1 = ai_board->randCoor(true);
    string coord1 = ai_board->getCoor(shot1);
    if(isdigit(coord1[0]))
    {
        //if it is a ship (number) then show as hit
        ai_board->setCoor(shot1, "X");
    }
    else
    {
        //else show it as a miss --- AI can't use powerups 
        ai_board->setCoor(shot1, "O");
    }

}

AI::AI()
{

}

string AI::hardFire(Grid* board)
{
    
}

AI::~AI()
{

}
