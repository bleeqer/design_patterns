#include <iostream>
#include <string>
#include <vector>

class Mediator;

class Colleague {
    public:
    Colleague(Mediator* const m, unsigned int i) : mediator(m), id(i) {}
    
    virtual ~Colleague() = default;

    unsigned int getId() {
        return id;
    }

    virtual void sendMsg(std::string) = 0;

    virtual void receiveMsg(std::string) = 0;

    protected:
    Mediator* mediator;
    unsigned int id;
};

class ConcreteColleague : public Colleague {
    public:
    ConcreteColleague(Mediator* const m, unsigned int i) : Colleague(m, i) {}

    ~ConcreteColleague() = default;

    void sendMsg(std::string msg) override;

    void receiveMsg(std::string msg) override {
        std::cout << "Message: " << msg << " is received by Colleague(id=" << this->getId() << ")" << std::endl;
    }

};

class Mediator {
    public:
    virtual ~Mediator() = default;

    virtual void add(Colleague* const c) = 0;

    virtual void distribute(Colleague* const sender, const std::string& msg) = 0;
};

class ConcreteMediator : public Mediator {
    public:
    ~ConcreteMediator() {
        for (unsigned long i = 0; i < colleagues.size(); ++i) {
            delete colleagues[i];
        }
        colleagues.clear();
    }

    void add(Colleague* const c) {
        colleagues.push_back(c);
    }

    void distribute(Colleague* const sender, const std::string& msg) {
        for (Colleague* colleague : colleagues) {
            if (colleague->getId() != sender->getId()) {
                colleague->receiveMsg(msg);
            }
        }
    }

    private:
    std::vector<Colleague*> colleagues;
};

void ConcreteColleague::sendMsg(std::string msg) {
    std::cout << "Message: " << msg << " is sent by Colleague(id=" << this->getId() << ")" << std::endl;
    mediator->distribute(this, msg);
}

int main() {
    Mediator* mediator = new ConcreteMediator();

    Colleague *colleague1 = new ConcreteColleague(mediator, 1);
    Colleague *colleague2 = new ConcreteColleague(mediator, 2);
    Colleague *colleague3 = new ConcreteColleague(mediator, 3);

    mediator->add(colleague1);
    mediator->add(colleague2);
    mediator->add(colleague3);

    colleague1->sendMsg("Hello");
    colleague2->sendMsg("World");
    colleague3->sendMsg("Mediator Pattern");

    delete colleague1;
    delete colleague2;
    delete colleague3;

    return 0;
}