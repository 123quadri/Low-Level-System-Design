#include <iostream>
using namespace std;

// Abstract Base Class
class Shape
{
public:
    virtual int getArea() = 0;
};

class Rectangle : public Shape
{
protected:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() override { return width * height; }
};

class Square : public Shape
{
private:
    int side;

public:
    Square(int s) : side(s) {}
    int getArea() override { return side * side; }
};

void printArea(Shape *s)
{
    // This function works perfectly for any substitute (Rectangle or Square)
    cout << "Area: " << s->getArea() << endl;
}

int main()
{
    Rectangle r(10, 5);
    Square s(5);

    printArea(&r); // Outputs 50
    printArea(&s); // Outputs 25
    return 0;
}