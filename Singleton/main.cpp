#include <iostream>
#include <string>

class Singleton;

class SingletonDestroyer {
    private:
        Singleton *instance;
    public:
        ~SingletonDestroyer() {
            delete this->instance;
        }

        void init(Singleton *p) {
            instance = p;
        }
};

class Singleton {
    private: 
        static Singleton *instance;
        static SingletonDestroyer destroyer;

    protected: 
        friend class SingletonDestroyer;
        Singleton(std::string name) : name(name) {}
        ~Singleton() {}

    public: 
        std::string name;

        static Singleton& getInstance(std::string name) {
            if(!instance) {
                instance = new Singleton(name);
                destroyer.init(instance);
            }

            return *instance;
        }

        void show() {
            std::cout << this->name << std::endl;
        }
};

Singleton * Singleton::instance = 0;
SingletonDestroyer Singleton::destroyer;

int main() {

    Singleton &a = Singleton::getInstance("a");
    Singleton &b = Singleton::getInstance("b");

    a.show();
    b.show();
    
    return 0;
}