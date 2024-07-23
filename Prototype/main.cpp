#include <iostream>

class Prototype {
    public:
        int id;

        Prototype(int id) : id(id) {}

        virtual void showData() {
            std::cout << this->id << std::endl;
        }

        virtual Prototype* clone() = 0;    
};


class ConcretePrototype1 : public Prototype {
    public:
        ConcretePrototype1(int id) : Prototype(id) {}

        Prototype* clone() {
            return new ConcretePrototype1(this->id);
        }
};

class ConcretePrototype2 : public Prototype {
    public: 
        ConcretePrototype2(int id) : Prototype(id) {}

        Prototype* clone() {
            return new ConcretePrototype2(this->id);
        }
};

int main() {    
    Prototype* a = new ConcretePrototype1(1);
    Prototype* aClone = a->clone();

    a->showData();
    aClone->showData();
    
    delete aClone;
    delete a;

    return 0;
}