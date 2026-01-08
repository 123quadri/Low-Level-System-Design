#ifndef SCORPIO_H
#define SCORPIO_H
#include "ICar.h"

class Scorpio : public ICar
{
public:
    void drive() override
    {
        std::cout << "Driving the powerful Scorpio!" << std::endl;
    }
};

#endif