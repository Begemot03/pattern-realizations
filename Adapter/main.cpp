#include <iostream>

class Transport {
public:
	virtual void drive() = 0;
};

class Auto : public Transport {
public:
	void drive() {
		std::cout << "Brm brm brm..." << std::endl;
	}
};

class Driver {
public:
	void travel(Transport *transport) {
		transport->drive();
	}
};

class Animal {
public:
	virtual void move() = 0;
};

class Camel : public Animal {
public:
	void move() {
		std::cout << "igogogo..." << std::endl;
	}
};

class CamelToTransportAdapter : public Transport {
private:
	Animal *camel;

public:
	CamelToTransportAdapter(Animal *camel) : camel(camel) {}

	void drive() {
		camel->move();
	}
};

int main() {
	Driver driver;

	Transport *car = new Auto();
	
	driver.travel(car);

	Animal *camel = new Camel();
	Transport *adapter = new CamelToTransportAdapter(camel);

	driver.travel(adapter);

	delete car;
	delete camel;
	delete adapter;

	return 0;
}