#include <iostream>
#include <vector>

class Iterator;

class Aggregate {
    public:
    virtual ~Aggregate() {}

    virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
    public:
    ConcreteAggregate(int N) {
        for (int i = 0; i < N; ++i) {
            objects.emplace_back(i);
        }
    }
    ~ConcreteAggregate() {}

    Iterator* createIterator();

    int getItem(int idx) {
        return objects.at(idx);
    }

    unsigned int getSize() {
        return objects.size();
    }

    void addItem(int obj) {
        objects.emplace_back(obj);
    }

    private:
    std::vector<int> objects;
};

class Iterator {
    public:
    virtual ~Iterator() {}

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual int currentItem() = 0;
};

class ConcreteIterator : public Iterator {
    public:
    ConcreteIterator(ConcreteAggregate* aggregate) : aggregate(aggregate), index(0) {}

    void first() override {
        index = 0;
    }

    void next() override {
        index++;
    }

    bool isDone() override {
        return index >= aggregate->getSize();
    }

    int currentItem() override {
        return aggregate->getItem(index);
    }

    private:
    ConcreteAggregate* aggregate;
    int index;
};

Iterator* ConcreteAggregate::createIterator() {
    return new ConcreteIterator(this);
}


int main() {
    ConcreteAggregate* aggregate = new ConcreteAggregate(10);

    aggregate->addItem(99);

    Iterator* it = aggregate->createIterator();

    for (; !it->isDone(); it->next()) {
        std::cout << "Item value: " << it->currentItem() << std::endl;
    }

    delete it;
    delete aggregate;

    return 0;
}