#include "HardAI.h"


HardAI::HardAI(Admiral* player)
{
    opponent = player;
    opponentBoard = opponent->getBoard();
    m_numShips = opponent->getNumShips();
    m_numAfloat = opponent->getNumAfloat();
}


string HardAI::fire()
{
    vector<Ship*>* fleet = opponent->getFleet(); //needs to be other player's fleet!!!
    bool foundCoor = false;
    string fire = "";
    while(!foundCoor)
    {
        for (int i = 0; i< fleet->size(); i++)
        {
            string* coor = fleet->at(i)->getCoords();
            for (int j = 0; j< fleet->at(i)->getSize(); j++ )
            {   
                string c = opponentBoard->getCoor(coor[j]);
                if (c!= "X" )
                {
                    foundCoor = true;
                    fire = coor[j];
                }
            }
        }
    }
    return fire;
    //Do i need to update that admirals num ships afloat and all that jazzz? how? 
}

HardAI::~HardAI()
{

}
