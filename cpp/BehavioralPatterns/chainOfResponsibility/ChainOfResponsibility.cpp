#include <iostream>
#include <string>

class Handler {
    public:
    virtual ~Handler() {}

    void setSuccessor(Handler *successor) {
        this->successor = successor;
    }

    Handler *getSuccessor() {
        return this->successor;
    }

    virtual void handleRequest() = 0;

private:
    Handler *successor;
};

class ConcreteHandler1 : public Handler {
    public:
    ~ConcreteHandler1() {}

    void handleRequest() override {
        if(!this->getSuccessor()) {
            std::cout << "This is handled by Concret Handler 1" << std::endl;
        } else {
            this->getSuccessor()->handleRequest();
        }
    }
};

class ConcreteHandler2 : public Handler {
    public:
    ~ConcreteHandler2() {}

    void handleRequest() override {
        if(!this->getSuccessor()) {
            std::cout << "This is handled by Concret Handler 2" << std::endl;
        } else {
            this->getSuccessor()->handleRequest();
        }
    }
};

int main() {
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    h1->setSuccessor(h2);

    h1->handleRequest();

    delete h1;
    delete h2;

    return 0;
}