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

// Simple Factory Class
class DeviceFactory
{
public:
    SmartDevice *createDevice(std::string type)
    {
        if (type == "bulb")
            return new Bulb();
        else if (type == "fan")
            return new Fan();
        return nullptr;
    }
};

// Usage
int main()
{
    DeviceFactory factory;
    SmartDevice *myDevice = factory.createDevice("bulb");
    myDevice->turnOn();
    delete myDevice;
    return 0;
}