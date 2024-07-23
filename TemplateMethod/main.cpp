#include <iostream>

class TemplateMethodClass {
public:
	void templateMethod() {
		operation1();
		operation2();
	}

	virtual void operation1() = 0;
	virtual void operation2() = 0;
};

class ConcreteTemplateMethodClass : public TemplateMethodClass {
public:
	void operation1() {
		std::cout << "operation 1" << std::endl;
	}

	void operation2() {
		std::cout << "operation 2" << std::endl;
	}
};

int main() {
	TemplateMethodClass *t = new ConcreteTemplateMethodClass();

	t->templateMethod();

	delete t;

	return 0;
}