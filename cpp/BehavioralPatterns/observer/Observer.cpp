#include <iostream>
#include <vector>

class Subject;

class Observer {
    public:
    Observer(const int id) : id(id) {}
    virtual ~Observer() {}

    virtual int getState() = 0;
    virtual void update(Subject* subject) = 0;
    virtual int getId() = 0;

    protected:
    int id;
};

class ConcreteObserver : public Observer {
    public:
    ConcreteObserver(const int state, const int id) : object_state(state), Observer(id) {}

    int getState() {
        return object_state;
    }

    int getId() {
        return id;
    }

    void update(Subject* subject);

    private:
    int object_state;
};

class Subject {
    public:
    virtual ~Subject() {}

    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(const int id) {
        for (auto it = observers.begin(); it != observers.end(); it++) {
            if ((*it)->getId() == id) {
                observers.erase(it);
            }
        }
    }

    void notify() {
        for (auto observer : observers) {
            observer->update(this);
        }
    }

    virtual int getState() = 0;
    virtual void setState(const int state) = 0;

    private:
    std::vector<Observer*> observers;
};

class ConcreteSubject : public Subject {
    public:
    ~ConcreteSubject() {}

    int getState() {
        return subject_state;
    }

    void setState(const int state) {
        subject_state = state;
    }

    private:
    int subject_state;
};

void ConcreteObserver::update(Subject* subject) {
    object_state = subject->getState();
    std::cout << "Observer(id=" << id << ") update state to: " << object_state;
}

int main() {
    ConcreteObserver observer1(1000, 1);
    ConcreteObserver observer2(2000, 2);

    std::cout << "Observer1 state: " << observer1.getState() << std::endl;
    std::cout << "Observer2 state: " << observer2.getState() << std::endl;

    Subject* subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    subject->setState(10);
    subject->notify();

    std::cout << "Observer1 state: " << observer1.getState() << std::endl;
    std::cout << "Observer2 state: " << observer2.getState() << std::endl;

    subject->detach(1);
    subject->setState(100);
    subject->notify();

    std::cout << "Observer1 state: " << observer1.getState() << std::endl;
    std::cout << "Observer2 state: " << observer2.getState() << std::endl;
    
}