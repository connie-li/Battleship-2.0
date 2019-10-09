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
    //went with showing them as misses... ships shown as *** 
    Grid* map = mapPicker(isPlayer1);
    int r = std::stoi(coord.substr(0,1));
    int c = charCoordtoIntCoord(coord.at(2));

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
    for (int i = startRow; i< startRow+2; i++ )
    {
        for(int j = startCol; j< startCol+2; j++)
        {
            std::string shot = i+":"+j;
            std::string coord1 = map->getCoor(shot);
            if(std::isdigit(coord1.at(0)))
            {
                //if it is a number (ship) then display as *
                map->setCoor(shot, "*");
            }
            else if (coord1[0] == '~')
            {
                //if water, display as miss
                map->setCoor(shot, "O");
            }
        }
    }
}
/**
 * Power up questions: do you want else if =='~' to make sure it is water before 
 * setting to miss?
 * How do we know if a user got a power up??
 */

void PowerUps::useScatterShot(std::string coord,bool isPlayer1){
    //make 3 random shots on the board,
    //either call an AI or we rng the shots here, then send to grid
    //as a "fire"
    Grid* map = mapPicker(isPlayer1);
   // removePowerUp('S');

    //randomly generates coordinate
    std::string shot1 = map->randCoor(true);

    //gets the value of that coor from Grid
    std::string coord1 = map->getCoor(shot1);

    if(std::isdigit(coord1[0]))
    {
        //if it is a ship (number) then show as hit
        map->setCoor(shot1, "X");
    }
    else
    {
        //else show it as a miss --- what about other power ups????
        map->setCoor(shot1, "O");
    }
    
    std::string shot2 = map->randCoor(true);
    std::string coord2 = map->getCoor(shot2);

    if(std::isdigit(coord2[0]))
    {
        map->setCoor(shot2, "X");
    }
    else
    {
        map->setCoor(shot2, "O");
    }
    std::string shot3 = map->randCoor(true);
    std::string coord3 = map->getCoor(shot3);

    if(std::isdigit(coord3[0]))
    {
        map->setCoor(shot3, "X");
    }
    else
    {
        map->setCoor(shot3, "O");
    }
}

void PowerUps::useUberCommander(std::string coord,bool isPlayer1){
    //does this call the Hard AI to find the smallest ship? 
    Grid* map = mapPicker(isPlayer1);
  //  removePowerUp('U');
}

int PowerUps::charCoordtoIntCoord(char c){
  return (int)c - 64;
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