#include <iostream>

class Product {
    public: virtual void Show() = 0;
};

class ProductA : public Product {
    public: void Show() {
        std::cout << "Product A" << std::endl;
    }
};

class ProductB : public Product {
    public: void Show() {
        std::cout << "Product B" << std::endl;
    }
};

class Creator {
    public: virtual Product* FactoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
    public: Product* FactoryMethod() {
        return new ProductA();
    }
};

class ConcreteCreatorB : public Creator {
    public: Product* FactoryMethod() {
        return new ProductB();
    }
};


int main() {
    Creator* a = new ConcreteCreatorA();

    Product* pr = a->FactoryMethod();
    pr->Show();

    delete pr;
    delete a;

    return -1;
}