#include <iostream>
#include <string>

class Colleague;

class Mediator {
public:
	virtual void send(std::string msg, Colleague* Colleague) = 0;
};

class Colleague {
protected:
	Mediator *mediator;

public:
	Colleague(Mediator *mediator) : mediator(mediator) {}

	virtual void send(std::string msg) {
		this->mediator->send(msg, this);
	}

	virtual void notify(std::string msg) = 0;
};

class ConcreteColleague1 : public Colleague {
public:
	ConcreteColleague1(Mediator *mediator) : Colleague(mediator) {}

	void notify(std::string msg) {
		std::cout << "Сообещение 1-ому: " << msg << std::endl;
	}
};

class ConcreteColleague2 : public Colleague {
public:
	ConcreteColleague2(Mediator *mediator) : Colleague(mediator) {}

	void notify(std::string msg) {
		std::cout << "Сообещение 2-ому: " << msg << std::endl;
	}
};

class ConcreteMediator : public Mediator {
public:
	ConcreteColleague1 *concreteColleague1;
	ConcreteColleague2 *concreteColleague2;

	void send(std::string msg, Colleague *colleague) {
		if(concreteColleague1 == colleague) {
			concreteColleague2->notify(msg);
		} else if(concreteColleague2 == colleague) {
			concreteColleague1->notify(msg);
		}
	}
};

int main() {
	ConcreteMediator *mediator = new ConcreteMediator();

	Colleague *colleague1 = new ConcreteColleague1(mediator);
	Colleague *colleague2 = new ConcreteColleague2(mediator);

	mediator->concreteColleague1 = dynamic_cast<ConcreteColleague1 *>(colleague1);
	mediator->concreteColleague2 = dynamic_cast<ConcreteColleague2 *>(colleague2);

	colleague1->send("Привет, 2-ой!");
	colleague2->send("Привет, привет, 1-ой!");

	delete colleague1;
	delete colleague2;
	delete mediator;

	return 0;
}