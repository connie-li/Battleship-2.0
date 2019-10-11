#include "PowerUps.h"

PowerUps::PowerUps()
{
    //tbd
}

PowerUps::~PowerUps(){
    //tbd
}

Grid PowerUps::mapPicker(bool isPlayer1){
    if(isPlayer1){
        return(m_admir2->getBoard());
    }
    return(m_admir1->getBoard());
}

void PowerUps::useTorpedo(std::string coord,bool isPlayer1, int shipSize, string* shipCoords){
    Grid map = mapPicker(isPlayer1);
    
     //check to see if the value is an int
    std::string coordValue = map.getCoor(coord);
    if(shipSize != -1){
        //this is a hit, destroy whole ship
        for(int i=0;i<shipSize;i++){
            map.setCoor(shipCoords[i], "X");
        }
    }
    else if (coordValue[0]=='~' || coordValue[0]=='O'){
        //this is water or a miss
        //should report as a miss
        map.setCoor(coord,"O");
    }
    else {
        //this tile should be a power up, assuming safe input here
        //should collect whatever powerup was there

        //add the symbol to the powerup vector list
       addPowerUp(coordValue, isPlayer1);
        map.setCoor(coord,"O");
    }


    //call admiral func to remove powerup, ex: removePowerUp('T');
}

void PowerUps::useRadar(std::string coord,bool isPlayer1){
    //make appropriate call to grid to show the surrounding tiles
    //should these show as water or misses?
    //went with showing them as misses... ships shown as *** 
    Grid map = mapPicker(isPlayer1);
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
            std::string shot = std::to_string(i)+":"+std::to_string(j);
            std::string coord1 = map.getCoor(shot);
            if(std::isdigit(coord1.at(0)))
            {
                //if it is a number (ship) then display as *
                map.setCoor(shot, "*");
            }
            else if (coord1[0] == '~')
            {
                //if water, display as miss
                map.setCoor(shot, "O");
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
    Grid map = mapPicker(isPlayer1);
   // removePowerUp('S');

    //randomly generates coordinate
    std::string shot1 = map.randCoor(true);

    //gets the value of that coor from Grid
    std::string coord1 = map.getCoor(shot1);

    if(std::isdigit(coord1[0]))
    {
        //if it is a ship (number) then show as hit
        map.setCoor(shot1, "X");
    }
    else
    {
        //else show it as a miss --- what about other power ups????
        map.setCoor(shot1, "O");
    }
    
    std::string shot2 = map.randCoor(true);
    std::string coord2 = map.getCoor(shot2);

    if(std::isdigit(coord2[0]))
    {
        map.setCoor(shot2, "X");
    }
    else
    {
        map.setCoor(shot2, "O");
    }
    std::string shot3 = map.randCoor(true);
    std::string coord3 = map.getCoor(shot3);

    if(std::isdigit(coord3[0]))
    {
        map.setCoor(shot3, "X");
    }
    else
    {
        map.setCoor(shot3, "O");
    }
}

void PowerUps::useUberCommander(std::string coord,bool isPlayer1){
    //does this call the Hard AI to find the smallest ship? 
    Grid map = mapPicker(isPlayer1);
  //  removePowerUp('U');
}

vector<string>* PowerUps::getPowerUps(const int player) const
{
    if(player == 1)
    {
        return(m_admir1Powerups);
    }
    if(player == 2)
    {
        return(m_admir2Powerups);
    }
}

int PowerUps::charCoordtoIntCoord(char c){
  return (int)c - 64;
}

void PowerUps::addPowerUp(std::string value, bool isPlayer1){
     if(isPlayer1){
            m_admir1Powerups->push_back(value);
        }
        else{
            m_admir2Powerups->push_back(value);
        }
}

void PowerUps::removePowerUp(std::string value, bool isPlayer1){
    vector<string>* list = nullptr;
    
    if(isPlayer1){
        list = m_admir1Powerups;
    }
    else{
        list = m_admir2Powerups;
    }
    for(int i = 0;i<list->size();i++){
        if(list->at(i) == value){
            list->erase(list->begin() + i);
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