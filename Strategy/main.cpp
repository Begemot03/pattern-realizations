#include <iostream>

class Strategy
{
public:
	virtual void algorithm() = 0;
};

class ConcreteStrategy1 : public Strategy
{
public:
	void algorithm()
	{
		std::cout << "strategy 1" << std::endl;
	}
};

class ConcreteStrategy2 : public Strategy
{
public:
	void algorithm()
	{
		std::cout << "strategy 2" << std::endl;
	}
};

class Context
{
public:
	Strategy *contextStrategy;

	Context(Strategy *s) : contextStrategy(s) {}

	void executeAlgorithm()
	{
		this->contextStrategy->algorithm();
	}

	~Context()
	{
		delete this->contextStrategy;
	}
};

int main()
{
	Context context(new ConcreteStrategy1());

	context.executeAlgorithm();

	return 0;
}