#include <iostream>

class AbstractProductA {
    public: virtual void show() = 0;
};

class AbstractProductB {
    public: virtual void show() = 0;
};

class ProductA1 : public AbstractProductA {
    public: void show() {
        std::cout << "Product A1" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
    public: void show() {
        std::cout << "Product A2" << std::endl;
    }
};

class ProductB1 : public AbstractProductB {
    public: void show() {
        std::cout << "Product B1" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
    public: void show() {
        std::cout << "Product B2" << std::endl;
    }
};

class AbstractFactory {
    public: virtual AbstractProductA* createProductA() = 0;
    public: virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
    public: AbstractProductA* createProductA() {
        return new ProductA1();
    }

    public: AbstractProductB* createProductB() {
        return new ProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
    public: AbstractProductA* createProductA() {
        return new ProductA2();
    }

    public: AbstractProductB* createProductB() {
        return new ProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractFactory* factory2 = new ConcreteFactory2();

    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    productA1->show();
    productA2->show();
    productB1->show();
    productB2->show();

    delete productA1;    
    delete productA2;
    delete productB1;
    delete productB2;
    delete factory1;
    delete factory2;

    return -1;
}