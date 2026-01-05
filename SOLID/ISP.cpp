#include <iostream>
using namespace std;

// Base Interface
class Shape
{
public:
    virtual void display() = 0;
};

// Segregated Interface for 2D objects
// Inherits 'display' from Shape and adds 'area'
class TwoDimensionalShape : public Shape
{
public:
    virtual double area() = 0;
};

// Segregated Interface for 3D objects
// Inherits 'display' from Shape and adds 'volume'
class ThreeDimensionalShape : public Shape
{
public:
    virtual double volume() = 0;
};

// Concrete Class: Square
// Implements only 2D capabilities
class Square : public TwoDimensionalShape
{
private:
    double side;

public:
    Square(double s)
    {
        this->side = s;
    }

    void display() override
    {
        cout << "Displaying a Square." << endl;
    }

    double area() override
    {
        return side * side;
    }
};

// Concrete Class: Rectangle
// Implements only 2D capabilities
class Rectangle : public TwoDimensionalShape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        this->length = l;
        this->width = w;
    }

    void display() override
    {
        cout << "Displaying a Rectangle." << endl;
    }

    double area() override
    {
        return length * width;
    }
};

// Concrete Class: Cube
// Implements only 3D capabilities
class Cube : public ThreeDimensionalShape
{
private:
    double side;

public:
    Cube(double s)
    {
        this->side = s;
    }

    void display() override
    {
        cout << "Displaying a Cube." << endl;
    }

    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    // Handling 2D Shapes
    Square sq(5.0);
    sq.display();
    cout << "Area: " << sq.area() << endl;

    Rectangle rect(4.0, 6.0);
    rect.display();
    cout << "Area: " << rect.area() << endl;

    cout << "-------------------" << endl;

    // Handling 3D Shapes
    Cube cube(3.0);
    cube.display();
    cout << "Volume: " << cube.volume() << endl;

    // Note: 'cube.area()' is not available here, which is good!
    // This proves ISP is working (Cube shouldn't have a 2D area method).

    return 0;
}