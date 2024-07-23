#include <iostream>

class Handler {
public:
	Handler* successor;

	Handler() : successor(NULL) {}

	virtual void requestHandler(int condition) = 0;
};

class ConcreteHandler1 : public Handler {
public:
	void requestHandler(int condition) {
		std::cout << "Chain 1" << std::endl;
		if(condition == 1) {
			std::cout << "Chain ended on 1" << std::endl;
		}

		else if(successor != NULL) {
			successor->requestHandler(condition);
		}
	}
};

class ConcreteHandler2 : public Handler {
public:
	void requestHandler(int condition) {
		std::cout << "Chain 2" << std::endl;
		if(condition == 2) {
			std::cout << "Chain ended on 2" << std::endl;
		}

		else if(successor != NULL) {
			successor->requestHandler(condition);
		}
	}
};

int main() {
	Handler  *h1 = new ConcreteHandler1();
	Handler  *h2 = new ConcreteHandler2();

	h1->successor = h2;
	
	h1->requestHandler(1);

	h1->requestHandler(2);

	delete h1;
	delete h2;

	return 0;
}