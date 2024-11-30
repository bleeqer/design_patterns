#include <iostream>
#include <string>
#include <vector>

class Component {
    public:
    virtual ~Component() {}

    virtual void operation() = 0;

    virtual void add(Component* compoenent) {};

    virtual void remove(Component* component) {};

    virtual Component* getChild(int) {
        return nullptr;
    }
};

class Leaf : public Component {
    public:
    Leaf(int id) : id(id) {};
    ~Leaf() {}

    void operation() {
        std::cout << "This is operation from Leaf: " << id << std::endl;
    }

    private:
    int id;
};

class Composite : public Component {
    public:
    ~Composite() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

    void operation() {
        std::cout << "size of children: " << children.size() << std::endl;
        for (int i = 0; i < children.size(); i++) {
            children[i]->operation();
        }
    }

    void add(Component* c) {
        children.push_back(c);
    }

    void remove(Component* c) {
        for (auto iter = children.begin(); iter != children.end(); iter++) {
            if (*iter == c) {
                children.erase(iter);
            }
        }
    }

    Component* getChild(int idx) {
        return idx < children.size() ? children[idx] : nullptr;
    }

    private:
    std::vector<Component*> children;
};

int main() {
    Composite composite;

    for (int i = 0; i < 3; i++) {
        composite.add(new Leaf(i));
    }
    Composite* newComposite = new Composite();
    newComposite->add(new Leaf(3));
    newComposite->add(new Leaf(4));

    composite.add(newComposite);

    composite.operation();

}