#ifndef AI_H
#define AI_H
#include <iostream>
#include "Admiral.h"
#include "stdlib.h"

class AI : public Admiral
{
    private: 
    public:
    
    AI();

    ~AI();
    bool fire();

    void placeShips(int numShips);

};
#endif