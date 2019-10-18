#include "AI.h"

string AI::easyFire()
{
    return opponentBoard->randCoor(true);
}

AI::AI()
{

}

string AI::medFire()
{
    if(hit)
    {

    }
}

void AI::updateHit()
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
    return fire;
    //Do i need to update that admirals num ships afloat and all that jazzz? how? 
}

AI::~AI()
{

}
