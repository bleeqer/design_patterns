#include <iostream>
#include <string>

class Product {
    public:
    virtual ~Product() {}

    virtual void checkProduct() = 0;
};

class ConcreteProductA : public Product {
    public:
    ~ConcreteProductA() {}

    void checkProduct() {
        std::cout << "Product A has been created" << std::endl;
    }
};

class ConcreteProductB : public Product {
    public:
    ~ConcreteProductB() {}

    void checkProduct() {
        std::cout << "Product B has been created" << std::endl;
    }
};

class Creator {
    public:
    virtual ~Creator() {}

    virtual Product* createProductA() = 0;
    virtual Product* createProductB() = 0;
};

class ConcreteCreator : public Creator {
    public:
    ~ConcreteCreator() {}

    Product* createProductA() {
        return new ConcreteProductA();
    }

    Product* createProductB() {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creator = new ConcreteCreator();

    Product* productA = creator->createProductA();
    productA->checkProduct();

    Product* productB = creator->createProductB();
    productB->checkProduct();
}