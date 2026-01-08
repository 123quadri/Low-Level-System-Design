#ifndef FORTUNER_H
#define FORTUNER_H
#include "ICar.h"

class Fortuner : public ICar
{
public:
    void drive() override
    {
        std::cout << "Driving the premium Fortuner!" << std::endl;
    }
};

#endif