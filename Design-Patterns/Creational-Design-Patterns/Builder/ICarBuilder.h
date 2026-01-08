#ifndef ICARBUILDER_H
#define ICARBUILDER_H
#include "ICar.h"

class ICarBuilder
{
public:
    virtual void withEngine() = 0;
    virtual void withTyre() = 0;
    virtual void buildChassis() = 0;
    virtual void buildBodyShell() = 0;
    virtual ICar *build() = 0;
    virtual ~ICarBuilder() {}
};

#endif