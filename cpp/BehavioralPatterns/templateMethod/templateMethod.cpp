#include <iostream>

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor {
    public:
    virtual ~Visitor() {}

    virtual void visitorElementA(ConcreteElementA* const element) = 0;
    virtual void visitorElementB(ConcreteElementB* const element) = 0;
};

class ConcreteVisitor1 : public Visitor {
    public:
    ~ConcreteVisitor1() {}

    void visitorElementA(ConcreteElementA* const element);
    void visitorElementB(ConcreteElementB* const element);
};

class ConcreteVisitor2 : public Visitor {
    public:
    ~ConcreteVisitor2() {}

    void visitorElementA(ConcreteElementA* const element);
    void visitorElementB(ConcreteElementB* const element);
};

class Element {
    public:
    virtual ~Element() {}

    virtual void accept(Visitor& v) = 0;
};

class ConcreteElementA : public Element {
    public:
    ConcreteElementA(const std::string& data) : data(data) {}
    ~ConcreteElementA() {}

    void accept(Visitor& v) {
        v.visitorElementA(this);
    }

    std::string getData() {
        return data;
    }

    private:
    std::string data;
};

class ConcreteElementB : public Element {
    public:
    ConcreteElementB(const std::string& data) : data(data) {}
    ~ConcreteElementB() {}

    void accept(Visitor& v) {
        v.visitorElementB(this);
    }

    std::string getData() {
        return data;
    }

    private:
    std::string data;
};

void ConcreteVisitor1::visitorElementA(ConcreteElementA* const element) {
    std::cout << "Concrete Visitor 1 : Element A visited." << std:: endl;
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVisitor1::visitorElementB(ConcreteElementB* const element) {
    std::cout << "Concrete Visitor 1 : Element B visited." << std:: endl;
    std::cout << "Element B data: " << element->getData() << std::endl;
}

void ConcreteVisitor2::visitorElementA(ConcreteElementA* const element) {
    std::cout << "Concrete Visitor 2 : Element A visited." << std:: endl;
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVisitor2::visitorElementB(ConcreteElementB* const element) {
    std::cout << "Concrete Visitor 2 : Element B visited." << std:: endl;
    std::cout << "Element B data: " << element->getData() << std::endl;
}


int main() {
    ConcreteElementA elementA("Hello");
    ConcreteElementB elementB("World");

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    elementA.accept(visitor1);
    elementB.accept(visitor1);

    elementA.accept(visitor2);
    elementB.accept(visitor2);

    return 0;
}