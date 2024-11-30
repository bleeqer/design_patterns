#include <iostream>
#include <string>

class Target {
    public:
    virtual ~Target() {};

    virtual void request() = 0;
};

class Adaptee {
    public:
    ~Adaptee() {}

    void specificRequest() {
        std::cout << "This is specific request" << std::endl;
    }
};

class Adapter : public Target, private Adaptee {
    public:
    ~Adapter() {}

    void request() {
        specificRequest();
        std::cout << "This is request" << std::endl;
    }
};


int main() {
    Target* t = new Adapter();
    t->request();
}