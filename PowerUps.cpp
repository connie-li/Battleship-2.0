#include "PowerUps.h"

PowerUps::PowerUps()
{
    //initializes the power up list to an empty array
    m_powerUpslist = new char[0];
}

PowerUps::~PowerUps(){
    delete[] m_powerUpslist;
    m_powerUpslist = nullptr;
}

void PowerUps::useTorpedo(){
    //use the torpedo element, make appropriate calls into grid
    
    removePowerUp('T');
}

void PowerUps::useRadar(){
    //make appropriate call to grid to show the surrounding tiles
    //should these show as water or misses?

    removePowerUp('R');
}

void PowerUps::useScatterShot(){
    //make 3 random shots on the board,
    //either call an AI or we rng the shots here, then send to grid
    //as a "fire"

    removePowerUp('S');
}

void PowerUps::useUberCommander(){
    //does this call the Hard AI to find the smallest ship? 

    removePowerUp('U');
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