#include <iostream>
#include <string>

class Implementor {
    public:
    virtual ~Implementor() {}

    virtual void operationImpl() = 0;
};

class ConcreteImplementorA : public Implementor {
    public:
    ConcreteImplementorA() {}
    ~ConcreteImplementorA() {}

    void operationImpl() {
        std::cout << "This is operationImpl from ConcreteImplementorA" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
    public:
    ConcreteImplementorB() {}
    ~ConcreteImplementorB() {}

    void operationImpl() {
        std::cout << "This is operationImpl from ConcreteImplementorB" << std::endl;
    }
};

class Abstraction {
    public:
    virtual ~Abstraction() {}

    virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction {
    public:
    ~RefinedAbstraction() {}

    RefinedAbstraction(Implementor* ip) : implementor(ip) {
        std::cout << "RefinedAbsaction" << std::endl;
    }

    void operation() {
        implementor->operationImpl();
    }

    private:
    Implementor* implementor;
};

int main() {
    Implementor* impl1 = new ConcreteImplementorA();
    Abstraction* abs1 = new RefinedAbstraction(impl1);
    abs1->operation();
    
    Implementor* impl2 = new ConcreteImplementorB();
    Abstraction* abs2 = new RefinedAbstraction(impl2);
    abs2->operation();
}