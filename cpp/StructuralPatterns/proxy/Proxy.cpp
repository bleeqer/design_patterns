#include <iostream>

class Subject {
    public:
    virtual ~Subject() {}

    virtual void request() = 0;
    
    private:
    void sensitiveRequest() {
        std::cout << "Sensitive request" << std::endl;
    }
};

class ConcreteSubject : public Subject {
    public:
    void request() {
        std::cout << "ConcreteSubject request" << std::endl;
    }
};

class Proxy : public Subject {
    public:
    Proxy() {
        subject = new ConcreteSubject();
    }

    ~Proxy() {
        delete subject;
    }

    void request() {
        subject->request();
    }

    private:
    ConcreteSubject* subject;
};

int main() {
    Proxy* proxy = new Proxy();
    proxy->request();

    delete proxy;
    return 0;
}