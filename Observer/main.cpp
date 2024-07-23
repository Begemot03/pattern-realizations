#include <iostream>
#include <algorithm>
#include <random>
#include <list>
#include <string>

struct StokeInfo
{
	int USD;
	int EURO;
};

class Observer
{
public:
	virtual void update(StokeInfo) = 0;
};

class Observable
{
public:
	virtual void registerObserver(Observer *o) = 0;
	virtual void removeObserver(Observer *o) = 0;
	virtual void notifyObservers() = 0;

protected:
	std::list<Observer *> observers;
};

class Stoke : public Observable
{
public:
	void registerObserver(Observer *o)
	{
		this->observers.push_back(o);

		std::cout << "Добавление: " << o << std::endl;
	}

	void removeObserver(Observer *o)
	{
		this->observers.remove(o);

		std::cout << "Удаление: " << o << std::endl;

		delete o;

		std::cout << "Теперь: " << o << std::endl;
	}

	void notifyObservers()
	{
		std::for_each(this->observers.cbegin(), this->observers.cend(), [=](Observer *o)
					  { std::cout << "Оповещение: " << o << std::endl; o->update(sInfo); });
	}

	void Market()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> euroDistr(30, 50);
		std::uniform_int_distribution<int> usdDistr(20, 40);

		this->sInfo.EURO = euroDistr(gen);
		this->sInfo.USD = usdDistr(gen);

		this->notifyObservers();
	}

	~Stoke()
	{
		std::for_each(this->observers.cbegin(), this->observers.cend(), [](Observer *o)
					  { std::cout << "Разрушение биржи: " << o << std::endl; 
					  if(!o)
					  	delete o; });
	}

private:
	StokeInfo sInfo;
};

class Broker : public Observer
{
public:
	std::string name;
	Observable *stoke;

	Broker(std::string name, Observable *o) : name(name), stoke(o)
	{
		stoke->registerObserver(this);
	}

	void update(StokeInfo sInfo)
	{
		if (sInfo.USD > 30)
		{
			std::cout << "Брокер " << name << " продает доллары; Курс доллара: " << sInfo.USD << std::endl;
		}
		else
		{
			std::cout << "Брокер " << name << " покупает доллары; Курс доллара: " << sInfo.USD << std::endl;
		}
	}

	void stopTrade()
	{
		stoke->removeObserver(this);
		stoke = 0;
	}

	~Broker()
	{
		if (!stoke)
			delete stoke;
	}
};

class Bank : public Observer
{
public:
	std::string name;
	Observable *stoke;

	Bank(std::string name, Observable *o) : name(name), stoke(o)
	{
		stoke->registerObserver(this);
	}

	void update(StokeInfo sInfo)
	{
		if (sInfo.EURO > 40)
		{
			std::cout << "Банк " << name << " продает евро; Курс евро: " << sInfo.EURO << std::endl;
		}
		else
		{
			std::cout << "Банк " << name << " покупает евро; Курс евро: " << sInfo.EURO << std::endl;
		}
	}

	void stopTrade()
	{
		stoke->removeObserver(this);
		stoke = 0;
	}

	~Bank()
	{
		if (!stoke)
			delete stoke;
	}
};

int main()
{
	Stoke *stoke = new Stoke();
	Bank *bank = new Bank("Тинькофф банк", stoke);
	Broker *broker = new Broker("Петров Андрей", stoke);

	stoke->Market();

	broker->stopTrade();

	stoke->Market();

	delete stoke;

	return 0;
}