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
    if(medAI_arr == nullptr)
    {
        return opponentBoard->randCoor(true);
    }
    else
    {
        if (hit)
        {
            string prevShot = "";
        }
    }
}

void AI::updateHit(string coor)
{
    hit = true;
    medAI_arr[counter] = coor;
    counter = counter +1;
    int shipsLeft = opponent->getNumAfloat();
    if (shipsLeft == prevShipAfloat -1)
    {
        hit = false;
        delete[] medAI_arr;
        medAI_arr = nullptr;
        counter = 0;
    }
}


string AI::hardFire()
{
    vector<Ship*> fleet = opponent->getFleet(); //needs to be other player's fleet!!!
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
    /* or
    hardFire(int i, int j)
    string* coor = fleet[i]->getCoords();
    string fire = coor[j];
    */
    return fire;
    //Do i need to update that admirals num ships afloat and all that jazzz? how? 
}

AI::~AI()
{

}
