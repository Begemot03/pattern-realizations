#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Visitor;

class Element {
public:
	virtual void accept(Visitor *visitor) = 0;

	std::string someState;
};

class ElementA : public Element {
public:
	void accept(Visitor *visitor);

	void operationA() {
		std::cout << "Operation A" << std::endl;
	}
};

class ElementB : public Element {
public:
	void accept(Visitor *visitor);

	void operationB() {
		std::cout << "Operation B" << std::endl;
	}
};

class ObjectStucture {
private:
	std::list<Element *>  elements;
public:
	void add(Element *el) {
		elements.push_back(el);
	}

	void remove(Element *el) {
		elements.remove(el);

		delete el;
		el = NULL;
	}

	void accept(Visitor *visitor) {
		std::for_each(elements.cbegin(), elements.cend(), [=](Element *el) { el->accept(visitor); });
	}
};

class Visitor {
public:
	virtual void visitElementA(ElementA *el) = 0;
	virtual void visitElementB(ElementB *el) = 0;	
};

class ConcreteVisitor1 : public Visitor {
public:
	void visitElementA(ElementA *el) {
		el->operationA();
	}

	void visitElementB(ElementB *el) {
		el->operationB();
	}
};

class ConcreteVisitor2 : public Visitor {
public:
	void visitElementA(ElementA *el) {
		el->operationA();
	}

	void visitElementB(ElementB *el) {
		el->operationB();
	}
};

void ElementA::accept(Visitor *visitor) {
	visitor->visitElementA(this);
}

void ElementB::accept(Visitor *visitor) {
	visitor->visitElementB(this);
}

int main() {
	ObjectStucture structure;

	Element *elA = new ElementA();
	Element *elB = new ElementB();

	Visitor *v1 = new ConcreteVisitor1();
	Visitor *v2 = new ConcreteVisitor2();

	structure.add(elA);
	structure.add(elB);

	structure.accept(v1);
	structure.accept(v2);


	delete v1;
	delete v2;

	delete elA;
	delete elB;

	return 0;
}