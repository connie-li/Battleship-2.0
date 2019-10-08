#include "PowerUps.h"

PowerUps::PowerUps()
{
    //tbd
}

PowerUps::~PowerUps(){
    delete[] m_admir1Map;
    m_admir1Map = nullptr;
    delete[] m_admir2Map;
    m_admir2Map = nullptr;
}

Grid* PowerUps::mapPicker(bool isPlayer1){
    if(isPlayer1){
        return(m_admir2Map);
    }
    return(m_admir1Map);
}

void PowerUps::useTorpedo(std::string coord,bool isPlayer1){
    Grid* map = mapPicker(isPlayer1);
    
     //check to see if the value is an int
    std::string coordValue = map->getCoor(coord);
    if(isdigit(coordValue[0]) == '1'|| coordValue[0]=='X'){
        //this is a hit, destory whole ship

    }
    else if (coordValue[0]=='~' || coordValue[0]=='O'){
        //this is water or a miss
        //should report as a miss
        map->setCoor(coord,"O");
    }
    else {
        //this tile should be a power up, assuming safe input here
        //should collect whatever powerup was there

        //call admiral helper function to add a new powerup
        map->setCoor(coord,"O");
    }


    //call admiral func to remove powerup, ex: removePowerUp('T');
}

void PowerUps::useRadar(std::string coord,bool isPlayer1){
    //make appropriate call to grid to show the surrounding tiles
    //should these show as water or misses?

    removePowerUp('R');
}

void PowerUps::useScatterShot(std::string coord,bool isPlayer1){
    //make 3 random shots on the board,
    //either call an AI or we rng the shots here, then send to grid
    //as a "fire"

    removePowerUp('S');
}

void PowerUps::useUberCommander(std::string coord,bool isPlayer1){
    //does this call the Hard AI to find the smallest ship? 

    removePowerUp('U');
}

/*
These may get removed, PowerUp doesn't own the list anymore
string* PowerUps::getPowerUps(){
    return(m_powerUpslist);
}

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