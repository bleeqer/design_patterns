#include <iostream>
#include <vector>

class Memento {
    private:
    friend class Originator;

    Memento(int s) : state(s) {}

    void setState(int s) {
        state = s;
    }

    int getState() {
        return state;
    }

    private:
    int state;
};

class Originator {
    public:
    void setState(int s) {
        state = s;
    }

    int getState() {
        return state;
    }

    void setMemento(Memento* const m) {
        state = m->getState();
    }

    Memento* createMemento() {
        return new Memento(state);
    }

    int getMementoState(Memento* const m) {
        return m->getState();
    }

    private:
    int state;
};

class CareTaker {
    public:
    CareTaker(Originator* const o) : originator(o) {}

    ~CareTaker() {
        for (Memento* m : historySaved) {
            if (m) {
                delete m;
            }
        }

        for (Memento* m : historyUndo) {
            if (m) {
                delete m;
            }
        }

        historySaved.clear();
        historyUndo.clear();
    }

    void save() {
        std::cout << "Save state: " << originator->getState() << std::endl;
        historySaved.push_back(originator->createMemento());
    }

    void printSavedStates() {
        std::cout << "Saved states: " << std::endl;

        if (historySaved.empty()) {
            std::cout << "It's empty" << std::endl;
        }

        for (Memento* m : historySaved) {
            std::cout << "state " << originator->getMementoState(m) << std::endl;
        }
    }

    void undo() {
        if (historySaved.empty()) {
            std::cout << "Unable to undo state." << std::endl;
            return;
        }

        Memento* m = historySaved.back();
        originator->setMemento(m);
        std::cout << "Undo state: " << originator->getState() << std::endl;

        historySaved.pop_back();
        historyUndo.push_back(m);
    }

    void redo() {
        if (historyUndo.empty()) {
            std::cout << "Unable to redo state." << std::endl;
            return;
        }

        Memento* m = historyUndo.back();
        originator->setMemento(m);
        std::cout << "Redo state: " << originator->getState() << std::endl;

        historyUndo.pop_back();
        historySaved.push_back(m);
    }


    private:
    Originator* originator;
    std::vector<Memento*> historySaved;
    std::vector<Memento*> historyUndo;
};

int main() {
    Originator* originator = new Originator();
    CareTaker* careTaker = new CareTaker(originator);

    originator->setState(0);
    careTaker->save();
    originator->setState(1);
    careTaker->save();
    originator->setState(2);
    careTaker->save();
    
    careTaker->printSavedStates();

    careTaker->undo();
    careTaker->printSavedStates();

    careTaker->undo();
    careTaker->printSavedStates();

    careTaker->undo();
    careTaker->undo();
    careTaker->undo();
    careTaker->printSavedStates();

    return 0;
}