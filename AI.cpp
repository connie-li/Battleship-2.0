#include "AI.h"

string AI::easyFire()
{
    return opponentBoard->randCoor(true);
}

AI::AI()
{
    
}

string AI::checkDirection()
{
    string fire = opponentBoard->randCoor(true);
        if (opponentBoard->getCoor(fire) == "2" || opponentBoard->getCoor(fire) == "3" ||  
        opponentBoard->getCoor(fire) == "4" || opponentBoard->getCoor(fire) == "5")
        {
            counter = 1;
            hit = true;
            prevShot = fire;
            string val = opponentBoard->getCoor(fire);
            int r = stoi(prevShot.substr(0,1));
            int c = stoi(prevShot.substr(1,2));
            if (c!=8)
            {
                string temp = to_string(r) + ":" + to_string(c+1);
                if (opponentBoard->getCoor(temp) == val)
                {
                    direction = 1;
                }
            }
            if (c!=0)
            {
                string temp = to_string(r) + ":" + to_string(c-1);
                if (opponentBoard->getCoor(temp) == val)
                {
                    direction = 3;
                }
            }
            if (r!=8)
            {
                string temp = to_string(r+1) + ":" + to_string(c);
                if (opponentBoard->getCoor(temp) == val)
                {
                    direction = 4;
                }
            }
            if (r!=0)
            {
                string temp = to_string(r-1) + ":" + to_string(c);
                if (opponentBoard->getCoor(temp) == val)
                {
                    direction = 2;
                }
            }
            
        }
        else if (opponentBoard->getCoor(fire) == "1")
        {
            hit = false;
            prevShipAfloat -= 1;
        }
}

string AI::medFire()
{
    if(!hit)
    {
        string fire = checkDirection();
        return fire;
    }
    else
    {
        string fire = "";
        //need to set current to 0 in constructor 
        int r = stoi(prevShot.substr(0,1));
        int c = stoi(prevShot.substr(1,2));
        if (current ==  0)
        {
            if (c!=8)
            {
                current =1;
            }
            else if (r!=0)
            {
                current = 2;
            }
            else
            {
                current = 3;
            }
        }
        if (current == direction)
        {
            if (current ==1)
            {
                if(c==8)
                {   
                    current = 3;
                    fire = to_string(r) + ":" + to_string(c-counter);
                    counter ++;
                    prevShot = fire;
                    return fire;
                }
                fire = to_string(r) + ":" + to_string(c+1);
                counter ++;
                prevShot = fire;
                return fire;
            }
            if (current == 2)
            {
                if (r == 0)
                {
                    current = 4;
                    fire = to_string(r+counter) + ":" + to_string(c);
                    counter ++;
                    prevShot = fire;
                    return fire;
                }
                fire = to_string(r-1) + ":" + to_string(c);
                counter ++;
                prevShot = fire;
                return fire;
            }
            if (current == 3)
            {
                if (c== 0)
                {
                    current = 1;
                    fire =  to_string(r) + ":" + to_string(c+counter);
                    counter ++;
                    prevShot = fire;
                    return fire;
                }
                fire =  to_string(r) + ":" + to_string(c-1);
                counter ++;
                prevShot = fire;
                return fire;
            }
            if (current == 4)
            {
                if (r == 8)
                {
                    current = 2;
                    fire=  to_string(r-counter) + ":" + to_string(c);
                    counter ++;
                    prevShot = fire;
                    return fire;
                }
                fire = to_string(r+1) + ":" + to_string(c);    
                counter ++;
                prevShot = fire;
                return fire;       
            }
        }
        if (current == 1)
        {
            fire = to_string(r) + ":" + to_string(c+1);
            if (r != 0)
            {
                current = 2;
            }
            else if (c!= 0)
            {
                current = 3;
            }
            else 
            {
                current = 4;
            }
            return fire;   
        }
        if (current ==2)
        {
            fire = to_string(r-1) + ":" + to_string(c);
            if(c!= 0)
            {
                current = 3;
            }
            else if (r!= 8)
            {
                current = 4;
            }
            else
            {
                current = 1;
            }
            return fire;
        }
        if (current == 3)
        {
            fire = to_string(r) + ":" + to_string(c-1);
            if (r!= 8)
            {
                current = 4;
            }
            else if (c!= 8)
            {
                current = 1;
            }
            else
            {
                current = 2;
            }
            return fire; 
        }
        if (current == 4)
        {
            fire = to_string(r+1) + ":" + to_string(c);
            if (c!= 8)
            {
                current = 1;
            }
            else if (r!= 0)
            {
                current = 2;
            }
            else
            {
                current = 3;
            }
            return fire; 
        }
        if (current >= 5 || current <= 0)
        {
            cout << "Error something went wrong in fire for medium AI";
        }
    }
}

string AI::hardFire()
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
