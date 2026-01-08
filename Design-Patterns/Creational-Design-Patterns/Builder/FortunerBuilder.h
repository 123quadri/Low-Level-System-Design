#ifndef FORTUNERBUILDER_H
#define FORTUNERBUILDER_H
#include "ICarBuilder.h"
#include "Fortuner.h"

class FortunerBuilder : public ICarBuilder
{
private:
    Fortuner *f1;

public:
    FortunerBuilder() { f1 = new Fortuner(); }

    void withEngine() override { std::cout << "Fortuner Engine getting inserted" << std::endl; }
    void withTyre() override { std::cout << "Fortuner Tyre getting inserted" << std::endl; }
    void buildChassis() override { std::cout << "Fortuner Chassis getting inserted" << std::endl; }
    void buildBodyShell() override { std::cout << "Fortuner Body getting inserted" << std::endl; }

    ICar *build() override { return f1; }
};

#endif