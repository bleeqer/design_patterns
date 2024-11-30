#include <iostream>

class AbstractProductA {
    public:
    virtual ~AbstractProductA() {}
    virtual void checkProduct() = 0;
};

class AbstractProductB {
    public:
    virtual ~AbstractProductB() {}
    virtual void checkProduct() = 0;
};

class ProductA1 : public AbstractProductA {
    public:
    ~ProductA1() {}
    void checkProduct() {
        std::cout << "ProductA1 has been created" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
    public:
    ~ProductA2() {}
    void checkProduct() {
        std::cout << "ProductA2 has been created" << std::endl;
    }
};

class ProductB1 : public AbstractProductB {
    public:
    ~ProductB1() {}
    void checkProduct() {
        std::cout << "ProductB1 has been created" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
    public:
    ~ProductB2() {}
    void checkProduct() {
        std::cout << "ProductB2 has been created" << std::endl;
    }
};

class AbstractFactory {
    public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
    public:
    ~ConcreteFactory1() {}
    AbstractProductA* createProductA() {
        return new ProductA1;
    }

    AbstractProductB* createProductB() {
        return new ProductB1;
    }
};

class ConcreteFactory2 : public AbstractFactory {
    public:
    ~ConcreteFactory2() {}
    AbstractProductA* createProductA() {
        return new ProductA2;
    }

    AbstractProductB* createProductB() {
        return new ProductB2;
    }
};

int main() {
    AbstractFactory* cf1 = new ConcreteFactory1();
    AbstractProductA* productA1 = cf1->createProductA();
    productA1->checkProduct();
    AbstractProductB* productB1 = cf1->createProductB();
    productB1->checkProduct();

    AbstractFactory* cf2 = new ConcreteFactory2();
    AbstractProductA* productA2 = cf2->createProductA();
    productA2->checkProduct();
    AbstractProductB* productB2 = cf2->createProductB();
    productB2->checkProduct();
}