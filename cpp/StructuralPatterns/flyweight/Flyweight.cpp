#include <iostream>
#include <string>
#include <unordered_map>

class Flyweight {
    public:
    virtual ~Flyweight() {}

    virtual void operation(const std::string& extrinsicState) = 0;
};

class ConcreteFlyweight : public Flyweight {
    public:
    ConcreteFlyweight(const std::string& instrinsicState) : instrinsicState(instrinsicState) {};

    ~ConcreteFlyweight() {}

    void operation(const std::string& extrinsicState) {
        std::cout << "ConcreteFlyweight operation extrinsicState: " << extrinsicState << std::endl;
    }

    private:
    std::string instrinsicState;
};

class UnsharedConcreteFlyweight : public Flyweight {
    public:
    UnsharedConcreteFlyweight(const std::string& allState) : allState(allState) {}

    void operation(const std::string& extrinsicState) {
        std::cout << "UnsharedConcreteFlyweight operation extrinsicState: " << extrinsicState << std::endl;
    }

    private:
    std::string allState;
};

class FlyweightFactory {
    public:
    ~FlyweightFactory() {
        for (auto it = flys.begin(); it != flys.end(); it++) {
            delete it->second;
        }
        flys.clear();
    }

    Flyweight* getFlyweight(const std::string& key) {
        if (flys.find(key) != flys.end()) {
            std::cout << " existed flyweight" << std::endl;
            return flys[key];
        } else {
            Flyweight* fly = new ConcreteFlyweight(key);
            flys.insert(std::make_pair(key, fly));
            std::cout << "new flyweight" << std::endl;
            return fly;
        }
    }

    private:
    std::unordered_map<std::string, Flyweight*> flys;
};

int main() {
    FlyweightFactory* factory = new FlyweightFactory();
    factory->getFlyweight("hello")->operation("world");
    factory->getFlyweight("hello")->operation("world");

    Flyweight* unsharedFly = new UnsharedConcreteFlyweight("What' up");
    unsharedFly->operation("Hello world");
    unsharedFly->operation("Hello world");
}