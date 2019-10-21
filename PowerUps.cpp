#include "PowerUps.h"

PowerUps::PowerUps()
{
    //tbd
}

PowerUps::~PowerUps(){
    //tbd
    //delete m_admir1;
    //delete m_admir2;
}

void PowerUps::setAdmirals(Admiral* admir1, Admiral* admir2){
    m_admir1 = admir1;
    m_admir2 = admir2;
}

Grid* PowerUps::mapPicker(bool isPlayer1){
    if(isPlayer1){
        return(m_admir2->getBoard());
    }
    return(m_admir1->getBoard());
}

void PowerUps::useTorpedo(std::string coord,bool isPlayer1, int shipSize, string* shipCoords){
    Admiral* tempAdmir = nullptr;
    
    if(isPlayer1){
        tempAdmir = m_admir1;
    }
    else{
        tempAdmir = m_admir2;
    }
    Grid* map = mapPicker(isPlayer1);
    vector<Ship*>* fleet = tempAdmir->getFleet();
    
    int tempIndex= tempAdmir->findShipbyCoord(coord);
     //check to see if the value is an int
    std::string coordValue = map->getCoor(coord);

    if(shipSize != -1){
        //this is a hit, destroy whole ship
        for(int i=0;i<shipSize;i++){
            map->setCoor(shipCoords[i], "X");

            //update the ship object
            fleet->at(tempIndex)->incNumHits();
            if(fleet->at(tempIndex)->getStatus() == false){
                tempAdmir->decNumAfloat(); 
            }
        }
    }
    else if(coordValue[0]=='~' || coordValue[0]=='O'){
        //this is water or a miss
        //should report as a miss
        map->setCoor(coord,"O");
    }
    else {
        //this tile should be a power up, assuming safe input here
        //should collect whatever powerup was there

        //add the symbol to the powerup vector list
       addPowerUp(coordValue, isPlayer1);
        map->setCoor(coord,"O");
    }

    //remove the torpedo from the list
    removePowerUp("T", isPlayer1);
    
}

void PowerUps::useRadar(std::string coord,bool isPlayer1){
    //make appropriate call to grid to show the surrounding tiles
    //should these show as water or misses?
    //went with showing them as misses... ships shown as *** 
    Grid* map = mapPicker(isPlayer1);
    int r = stoi(coord.substr(coord.find(":") + 1));
    int c = stoi(coord.substr(0, coord.find(":")));
    //get starting upper left coor row and col for 3x3 box for radar
    int startRow = r-1;
    int startCol = c -1;
    if (r ==1)
    {
        startRow = r;
    }
    else if (r == 8)
    {
        startRow -= 1;
    }
    if (c == 1)
    {
        startCol = c;
    }
    else if (c == 8)
    {
        startCol -= 1;
    }
    for (int i = startRow; i<= startRow+2; i++ )
    {
        for(int j = startCol; j<= startCol+2; j++)
        {
            string shot = to_string(i) + ":" + to_string(j);
            std::string coord1 = map->getCoor(shot);
            if(coord1 == "~"){
                map->setCoor(shot, "O");
            }else{
                map->setCoor(shot, ("$" + coord1));
            }
        }
    }
    removePowerUp("R", isPlayer1);
    
}
/**
 * Power up questions: do you want else if =='~' to make sure it is water before 
 * setting to miss?
 * How do we know if a user got a power up??
 */

void PowerUps::useScatterShot(bool isPlayer1){
    Grid* map = mapPicker(isPlayer1);
    string value = "\0";
    string coor = "\0";
    for(int i = 0; i < 3; i++){
        coor = map->randCoor(true);
        value = map->getCoor(coor);
        if(((int)value[0] >= 48 && (int)value[0] <= 57) || value == "X"){
            map->setCoor(coor, "X");
        }else if(value == "O" || value == "~"){
            map->setCoor(coor, "O");
        }else{
            addPowerUp(value, isPlayer1);
        }
    }
    removePowerUp("S", isPlayer1);
}

//10/13 I think this may only work correctly when the ships are put into the 
//vector in order from smallest to largest
void PowerUps::useUberCommander(std::string coord,bool isPlayer1){
    Admiral* tempAdmir= nullptr;
    
    bool fired = false;
    //picking which admiral to use
    if(isPlayer1){
        tempAdmir = m_admir2;
    }
    else{
        tempAdmir = m_admir1;
    }
    //gathering the correct map
    Grid* map = mapPicker(isPlayer1);
    vector<Ship*>* tempFleet = tempAdmir->getFleet();
    
    //outer loop iterates through each ship in the fleet
    for(int i=0;i<tempAdmir->getNumShips();i++){
        //getting the coordinates of the ship at the ith position of shipVector
        std::string* tempCoords = tempFleet->at(i)->getCoords();
        int tempSize = tempFleet->at(i)->getSize();
        std::string tempI = std::to_string(i+1);

        //inner loop iterates through each coordinate of a ship
        for(int j=0;j<tempSize;j++){
            if(fired ==false){
                //if value at the ship coord is = to the number
                if(tempAdmir->getBoard()->getCoor(tempCoords[j])== tempI){
                    map->setCoor(tempCoords[j], "X");
                    fired = true;
                    //adjust the ship
                    tempFleet->at(i)->incNumHits();
                    if(tempFleet->at(i)->getStatus() == false){
                        tempAdmir->decNumAfloat();
                    }
                }
            }
        }
    }
    removePowerUp("U",isPlayer1);
    
}

vector<string> PowerUps::getPowerUps(bool isPlayer1)
{
    if(isPlayer1)
    {
        return(m_admir1Powerups);
    }
    else{
        return(m_admir2Powerups);
    }
}

int PowerUps::charCoordtoIntCoord(char c){
  return (int)c - 64;
}

void PowerUps::addPowerUp(std::string value, bool isPlayer1){
     if(isPlayer1){
            m_admir1Powerups.push_back(value);
        }
        else{
            m_admir2Powerups.push_back(value);
        }
}

void PowerUps::removePowerUp(std::string value, bool isPlayer1){
    //this was a vector<string>* list = nullptr;
    vector<string>* upsList;
    
    if(isPlayer1){
        upsList = &m_admir1Powerups;
    }
    else{
        upsList = &m_admir2Powerups;
    }
    for(int i = 0;i<upsList->size();i++){
        if(upsList->at(i) == value){
            upsList->erase(upsList->begin() + i);
        }
    }
    
}

bool PowerUps::hasAPowerup(bool isPlayer1){
    if(isPlayer1){
        if(m_admir1Powerups.size() > 0){
            return(true);
        }      
        else{
             return(false);
        }  
    }
    else{
        if(m_admir2Powerups.size() > 0){
            return(true);
        }
        else{
            return(false);
        }
    }
}
/*
void PowerUps::addPowerUp(char symbol){
    char* temp = new char[(m_size+1)];
    for(int i=0;i<m_size; i++)
    {
        temp[i]=m_powerUpslist[i];
    }
    delete m_powerUpslist;
    temp[m_size] = symbol;
    
    m_powerUpslist = temp;
    m_size++;
}

void PowerUps::removePowerUp(char symbol){

    for(int i=0;i<m_size; i++){
            if(m_powerUpslist[i] == symbol){
                //do nothing, will skip from updating the list
            }
            else{
                m_powerUpslist[i] = m_powerUpslist[i];
            } 
        }
}
*/