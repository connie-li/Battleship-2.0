#include "AI.h"

void AI::easyFire()
{
    string shot1 = opponentBoard->randCoor(true);
    string coord1 = opponentBoard->getCoor(shot1);
    if(isdigit(coord1[0]))
    {
        //if it is a ship (number) then show as hit
        opponentBoard->setCoor(shot1, "X");
    }
    else
    {
        //else show it as a miss --- AI can't use powerups 
        opponentBoard->setCoor(shot1, "O");
    }

}

AI::AI()
{

}

string AI::hardFire()
{
    vector<Ship*> fleet = getFleet();
    bool foundCoor = false;
    string fire = "";
    while(!foundCoor)
    {
        for (int i = 0; i< fleet.size(); i++)
        {
            string* coor = fleet[i]->getCoords();
            for (int j = 0; j< fleet[i]->getSize(); j++ )
            {   
                string c = opponentBoard->getCoor(coor[j]);
                if (c!= "X" )
                {
                    foundCoor = true;
                    fire = c;
                }
            }
        }
    }
    opponentBoard->setCoor(fire, "X");
    //Do i need to update that admirals num ships afloat and all that jazzz? how? 
}

AI::~AI()
{

}
