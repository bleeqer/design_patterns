#include <iostream>
#include <string>

class Product {
    public:
    void partA(const std::string& part) {
        part_a = part;
    }
    
    void partB(const std::string& part) {
        part_b = part;
    }
    
    void partC(const std::string& part) {
        part_c = part;
    }

    void checkProduct() {
        std::cout << part_a + " " << part_b << " " << part_c << std::endl;
    }

    private:
    std::string part_a;
    std::string part_b;
    std::string part_c;
};

class Builder {
    public:
    virtual ~Builder() {}
    Product getProduct() {
        return product;
    }

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

    protected:
    Product product;
};


class ConcreteProductBuilder1 : public Builder {
    public:
    ~ConcreteProductBuilder1() {}

    void buildPartA() {
        product.partA("1-A");
    }

    void buildPartB() {
        product.partB("1-B");
    }

    void buildPartC() {
        product.partC("1-C");
    }
};

class ConcreteProductBuilder2 : public Builder {
    public:
    ~ConcreteProductBuilder2() {}

    void buildPartA() {
        product.partA("2-A");
    }

    void buildPartB() {
        product.partB("2-B");
    }

    void buildPartC() {
        product.partC("2-C");
    }
};

class Director {
    public:
    ~Director() {
        if (builder) {
            delete builder;
        }
    }

    void setBuilder(Builder* b) {
        if (builder) {
            delete builder;
        }

        builder = b;
     }

     Product getProduct() {
        return builder->getProduct();
     }

     void construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
     }

     private:
     Builder* builder = nullptr;
};

int main() {
    Director director;
    director.setBuilder(new ConcreteProductBuilder1());
    director.construct();

    Product product1 = director.getProduct();
    product1.checkProduct();

    director.setBuilder(new ConcreteProductBuilder2());
    director.construct();

    Product product2 = director.getProduct();
    product2.checkProduct();
}