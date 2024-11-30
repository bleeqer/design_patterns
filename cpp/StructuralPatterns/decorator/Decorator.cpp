#include <iostream>
#include <string>

class Component {
    public:
    virtual ~Component() {}

    virtual void operation() = 0;
};

class ConcreteComponent : public Component {
    public:
    ~ConcreteComponent() {}

    void operation() {
        std::cout << "Concrete Component operation" << std::endl;
    }
};

class Decorator : public Component {
    public:
    ~Decorator() {}

    Decorator(Component* c) : component(c) {}

    virtual void operation() {
        component->operation();
    }

    private:
    Component* component;
};

class ConcreteDecoratorA : public Decorator {
    public:
    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    void operation() {
        Decorator::operation();
        std::cout << "Added behavior for ConcreteDecoratorA" << std::endl;
    }
};

class ConcreteDecoratorB : public Decorator {
    public:
    ConcreteDecoratorB(Component* c) : Decorator(c) {}

    void operation() {
        Decorator::operation();
        std::cout << "Added behavior for ConcreteDecoratorB" << std::endl;
    }
};

int main() {
    Component *cc = new ConcreteComponent();
    ConcreteDecoratorA *cda = new ConcreteDecoratorA(cc);
    ConcreteDecoratorB *cdd = new ConcreteDecoratorB(cc);

    cda->operation();
    cda->operation();
}