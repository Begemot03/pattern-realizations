#include <iostream>
#include <string>

class Pizza {
public:
	std::string name;

	Pizza(std::string s) : name(s) {}

	virtual int getCost() = 0;
};

class ItalianPizza : public Pizza {
public:
	ItalianPizza() : Pizza("italian pizza") {}

	int getCost() {
		return 8;
	}
};

class BulgerianPizza : public Pizza {
public:
	BulgerianPizza() : Pizza("bulgerain pizza") {}

	int getCost() {
		return 10;
	}
};

class PizzaDecorator : public Pizza {
protected:
	Pizza *pizza;

public:
	PizzaDecorator(std::string s, Pizza *pizza) : Pizza(s), pizza(pizza) {}
};

class TomatoPizza : public PizzaDecorator {
public:
	TomatoPizza(Pizza *p) : PizzaDecorator(p->name + " with tomato", p) {}

	int getCost() {
		return pizza->getCost() + 3;
	}
};

class ChessPizza : public PizzaDecorator {
public:
	ChessPizza(Pizza *p) : PizzaDecorator(p->name + " with chess", p) {}

	int getCost() {
		return pizza->getCost() + 5;
	}
};

int main() {
	Pizza *bulgerianPizza = new BulgerianPizza();

	Pizza *bulgerianPizzaWithChess = new ChessPizza(bulgerianPizza);

	Pizza *bulgerianPizzaWithChessWithTomato = new TomatoPizza(bulgerianPizzaWithChess);

	std::cout << bulgerianPizzaWithChessWithTomato->name << "\n\tcost: " << bulgerianPizzaWithChessWithTomato->getCost() << std::endl;

	delete bulgerianPizzaWithChessWithTomato;
	delete bulgerianPizzaWithChess;
	delete bulgerianPizza;

	return 0;
}