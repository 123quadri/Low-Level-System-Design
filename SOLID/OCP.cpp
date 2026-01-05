#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
private:
    string name;
    string color;
    string size;

public:
    Product(string n, string c, string s) : name(n), color(c), size(s) {}
    string getName() { return name; }
    string getColor() { return color; }
    string getSize() { return size; }
};

// Abstract Specification (Open for extension)
class Specification
{
public:
    virtual bool isSatisfied(Product *item) = 0;
};

// Concrete Specification for Color
class ColorSpecification : public Specification
{
private:
    string colorToFind;

public:
    ColorSpecification(string color) : colorToFind(color) {}
    bool isSatisfied(Product *item) override
    {
        return item->getColor() == colorToFind;
    }
};

// Concrete Specification for Size
class SizeSpecification : public Specification
{
private:
    string sizeToFind;

public:
    SizeSpecification(string size) : sizeToFind(size) {}
    bool isSatisfied(Product *item) override
    {
        return item->getSize() == sizeToFind;
    }
};

// The Filter (Closed for modification)
class ProductFilter
{
public:
    vector<Product *> filter(vector<Product *> items, Specification *spec)
    {
        vector<Product *> result;
        for (Product *item : items)
        {
            if (spec->isSatisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main()
{
    Product p1("Apple", "Green", "Small");
    Product p2("Tree", "Green", "Large");
    Product p3("House", "Blue", "Large");

    vector<Product *> products = {&p1, &p2, &p3};

    ProductFilter pf;

    // We can filter by Color
    ColorSpecification greenSpec("Green");
    vector<Product *> greenThings = pf.filter(products, &greenSpec);

    // We can filter by Size without changing the ProductFilter class
    SizeSpecification largeSpec("Large");
    vector<Product *> largeThings = pf.filter(products, &largeSpec);

    return 0;
}