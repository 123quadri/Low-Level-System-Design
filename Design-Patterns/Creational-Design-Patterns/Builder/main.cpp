#include "ScorpioBuilder.h"
#include "Director.h"

int main()
{
    // Constructing a Scorpio
    ICarBuilder *builder = new ScorpioBuilder();
    Director *director = new Director(builder);

    director->construct();

    ICar *myCar = builder->build();
    myCar->drive();

    delete myCar;
    delete builder;
    delete director;

    return 0;
}