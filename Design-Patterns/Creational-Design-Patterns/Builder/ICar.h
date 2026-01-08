#ifndef ICAR_H
#define ICAR_H
#include <iostream>

class ICar
{
public:
    virtual void drive() = 0;
    virtual ~ICar() {}
};

#endif