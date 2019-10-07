#include "PowerUps.h"

PowerUps::PowerUps(Grid* playerGrid)
{
    //initializes the power up list to an empty array
    m_powerUpslist = new char[0];

    m_map = playerGrid;
}

PowerUps::~PowerUps(){
    delete[] m_powerUpslist;
    m_powerUpslist = nullptr;
    delete[] m_map;
    m_map = nullptr;
}

void PowerUps::useTorpedo(std::string coord){
    //use the torpedo element, make appropriate calls into grid
    
    removePowerUp('T');
}

void PowerUps::useRadar(std::string coord){
    //make appropriate call to grid to show the surrounding tiles
    //should these show as water or misses?

    removePowerUp('R');
}

void PowerUps::useScatterShot(std::string coord){
    //make 3 random shots on the board,
    //either call an AI or we rng the shots here, then send to grid
    //as a "fire"

    removePowerUp('S');
}

void PowerUps::useUberCommander(std::string coord){
    //does this call the Hard AI to find the smallest ship? 

    removePowerUp('U');
}

char* PowerUps::getPowerUps(){
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