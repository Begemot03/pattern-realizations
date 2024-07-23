#include <iostream>
#include <string>

class Product
{
public:
	std::string str;

	void add(std::string s)
	{
		str += s;
	}
};

class Builder
{
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	virtual Product getResult() = 0;
};

class ConcreteBuilder : public Builder
{
public:
	Product p;

	ConcreteBuilder() : p(Product()) {}

	void buildPartA()
	{
		p.add("a");
	}

	void buildPartB()
	{
		p.add("b");
	}

	void buildPartC()
	{
		p.add("c");
	}

	Product getResult()
	{
		return p;
	}
};

class Director
{
public:
	Builder *b;

	Director(Builder *b) : b(b) {}

	void construct()
	{
		b->buildPartA();
		b->buildPartB();
		b->buildPartC();
	}

	~Director()
	{
		delete b;
	}
};

int main()
{
	Builder *builder = new ConcreteBuilder();
	Director director(builder);
	director.construct();
	Product p = builder->getResult();

	std::cout << p.str << std::endl;

	return 0;
}