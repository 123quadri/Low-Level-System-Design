#include <iostream>
#include <string>

// --- Products ---
class Bulb
{
public:
    virtual void glow() = 0;
};
class Fan
{
public:
    virtual void spin() = 0;
};

// --- Xiaomi Brand Products ---
class XiaomiBulb : public Bulb
{
public:
    void glow() override { std::cout << "Xiaomi Bulb glows dimly."; }
};
class XiaomiFan : public Fan
{
public:
    void spin() override { std::cout << "Xiaomi Fan spins fast."; }
};

// --- Philips Brand Products ---
class PhilipsBulb : public Bulb
{
public:
    void glow() override { std::cout << "Philips Bulb glows brightly."; }
};
class PhilipsFan : public Fan
{
public:
    void spin() override { std::cout << "Philips Fan spins silently."; }
};

// --- The Abstract Factory ---
class SmartHomeFactory
{
public:
    virtual Bulb *createBulb() = 0;
    virtual Fan *createFan() = 0;
};

// --- Concrete Factory 1: Xiaomi ---
class XiaomiFactory : public SmartHomeFactory
{
public:
    Bulb *createBulb() override { return new XiaomiBulb(); }
    Fan *createFan() override { return new XiaomiFan(); }
};

// --- Concrete Factory 2: Philips ---
class PhilipsFactory : public SmartHomeFactory
{
public:
    Bulb *createBulb() override { return new PhilipsBulb(); }
    Fan *createFan() override { return new PhilipsFan(); }
};

// Usage
int main()
{
    // The user decides they want a Philips themed house
    SmartHomeFactory *houseBrand = new PhilipsFactory();

    Bulb *b = houseBrand->createBulb();
    Fan *f = houseBrand->createFan();

    b->glow();
    f->spin();

    delete b;
    delete f;
    delete houseBrand;
    return 0;
}