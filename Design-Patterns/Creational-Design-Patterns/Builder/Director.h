#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "ICarBuilder.h"

class Director
{
private:
    ICarBuilder *carBuilder;

public:
    Director(ICarBuilder *builder) : carBuilder(builder) {}

    void construct()
    {
        carBuilder->withEngine();
        carBuilder->withTyre();
        carBuilder->buildChassis();
        carBuilder->buildBodyShell();
    }
};

#endif