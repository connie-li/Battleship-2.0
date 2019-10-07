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
    
    for(int i=0;i<)
}