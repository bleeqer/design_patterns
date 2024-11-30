#include <iostream>
#include <string>

class Prototype {
    public:
    virtual ~Prototype() {}
    
    virtual Prototype* clone() = 0;
    
    virtual void checkPrototype() = 0;
};

class ConcretePrototype1 : public Prototype {
    public:
    ~ConcretePrototype1() {}

    Prototype* clone() {
        return new ConcretePrototype1();
    }

    void checkPrototype() {
        std::cout << "Prototype 1 has been created" << std::endl;
    }
};

class ConcretePrototype2 : public Prototype {
    public:
    ~ConcretePrototype2() {}

    Prototype* clone() {
        return new ConcretePrototype2();
    }

    void checkPrototype() {
        std::cout << "Prototype 2 has been created" << std::endl;
    }
};

class Client {
    public:
    ~Client() {
        if (prototype) {
            delete prototype;
        }
    }

    void setPrototype(Prototype* p) {
        if (prototype) {
            delete prototype;
        }
        prototype = p;
    }

    Prototype* clone() {
        if (!prototype) {
            return nullptr;
        }

        return prototype->clone();
    }

    private:
    Prototype* prototype;
};

int main() {
    Client client;
    client.setPrototype(new ConcretePrototype1());
    Prototype* p1 = client.clone();
    p1->checkPrototype();

    client.setPrototype(new ConcretePrototype2());
    Prototype* p2 = client.clone();
    p2->checkPrototype();
}