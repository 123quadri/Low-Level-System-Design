#include <iostream>
#include <string>

// The Product Interface
class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual ~SmartDevice() {}
};

// Concrete Product 1
class Bulb : public SmartDevice
{
public:
    void turnOn() override { std::cout << "Bulb is glowing!" << std::endl; }
};

// Concrete Product 2
class Fan : public SmartDevice
{
public:
    void turnOn() override { std::cout << "Fan is spinning!" << std::endl; }
};

// The Creator (Base Factory)
class DeviceFactory
{
public:
    virtual SmartDevice *factoryMethod() = 0; // The Factory Method
    virtual ~DeviceFactory() {}
};

// Concrete Creator 1
class BulbFactory : public DeviceFactory
{
public:
    SmartDevice *factoryMethod() override { return new Bulb(); }
};

// Concrete Creator 2
class FanFactory : public DeviceFactory
{
public:
    SmartDevice *factoryMethod() override { return new Fan(); }
};

// Usage
int main()
{
    // If we want a bulb, we use the BulbFactory
    DeviceFactory *factory = new BulbFactory();
    SmartDevice *myDevice = factory->factoryMethod();

    myDevice->turnOn();

    delete myDevice;
    delete factory;
    return 0;
}