#ifndef SCORPIOBUILDER_H
#define SCORPIOBUILDER_H
#include "ICarBuilder.h"
#include "Scorpio.h"

class ScorpioBuilder : public ICarBuilder
{
private:
    Scorpio *s1;

public:
    ScorpioBuilder() { s1 = new Scorpio(); }

    void withEngine() override { std::cout << "Scorpio Engine getting inserted" << std::endl; }
    void withTyre() override { std::cout << "Scorpio Tyre getting inserted" << std::endl; }
    void buildChassis() override { std::cout << "Scorpio Chassis getting inserted" << std::endl; }
    void buildBodyShell() override { std::cout << "Scorpio Body getting inserted" << std::endl; }

    ICar *build() override { return s1; }
};

#endif