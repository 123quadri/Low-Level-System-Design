#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton &getInstance()
    {
        // Guaranteed to be destroyed and instantiated on completion of utility
        static Singleton instance;
        return instance;
    }

private:
    Singleton()
    {
        cout << "Creating Object" << endl;
    }

    // Delete copy constructor and assignment operator to prevent cloning
    Singleton(Singleton const &) = delete;
    Singleton &operator=(Singleton const &) = delete;
};

int main()
{
    // Requesting the instance for the first time (triggers creation)
    Singleton &instance1 = Singleton::getInstance();
    cout << &instance1 << endl;

    // Requesting the instance a second time (reuses the existing object)
    Singleton &instance2 = Singleton::getInstance();
    cout << &instance2 << endl;

    return 0;
}