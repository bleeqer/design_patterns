#include <iostream>
#include <string>

class Singleton {
    public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance() {
        if (!instance_) {
            instance_ = new Singleton();
        }
        return instance_;
    }

    void checkSingleton() {
        std::cout << "Singleton has been created" << std::endl;
    }

    private:
    Singleton() {
        std::cout << "Singleton" << std::endl;
    }

    static Singleton* instance_;
};

Singleton* Singleton::instance_ = nullptr;

int main() {
    Singleton* singleton = Singleton::instance();
    singleton->checkSingleton();

    return 0;
}
