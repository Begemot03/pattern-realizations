#include <iostream>
#include <map>
#include <string>

class Context {
public:
	std::map<std::string, int> variables;

	int getVariables(std::string name) {
		return variables[name];
	}

	void setVariables(std::string name, int v) {
		variables[name] = v;
	}
};

class Expression {
public:
	Expression *l;
	Expression *r;

	Expression() : l(NULL), r(NULL) {}
	Expression(Expression *l, Expression *r) : l(l), r(r) {}

	virtual int interpret(Context *) = 0;

	~Expression() {
		if(l != NULL) {
			std::cout << "Удаление левого операнда" << std::endl;

			delete l;
			l = NULL;
		}

		if(r != NULL) {
			std::cout << "Удаление правого операнда" << std::endl;

			delete r;
			r = NULL;
		}
	}
};

class NumberExpression : public Expression {
public:
	std::string name;

	NumberExpression(std::string name) : name(name) {}

	int interpret(Context *context) {
		if(context == NULL) return 0;

		return context->getVariables(name);
	}

	~NumberExpression() {
		std::cout << "Деструкторр оператора число" << std::endl;
	}
};

class AddExpression : public Expression {
public:
	AddExpression(Expression *l, Expression *r) : Expression(l, r) {}

	int interpret(Context *context) {
		if(context == NULL) return 0;

		return l->interpret(context) + r->interpret(context);
	}

	~AddExpression() {
		std::cout << "Деструкторр оператора плюс" << std::endl;
	}
};

class SubExpression : public Expression {
public:
	SubExpression(Expression *l, Expression *r) : Expression(l, r) {}

	int interpret(Context *context) {
		if(context == NULL) return 0;

		return l->interpret(context) - r->interpret(context);
	}

	~SubExpression() {
		std::cout << "Деструкторр оператора минус" << std::endl;
	}
};


int main() {
	Context *c = new Context();

	c->setVariables("x", 1);
	c->setVariables("y", 2);
	c->setVariables("z", 1);

	Expression *a = new AddExpression(
		new NumberExpression("x"), new NumberExpression("y")
	);

	Expression *s = new SubExpression(a, new NumberExpression("z"));


	int result = s->interpret(c);

	std::cout << "Ответ: " << result << std::endl;

	
	delete c;
	delete s;

	s = NULL;
	c = NULL;


	return 0;
}