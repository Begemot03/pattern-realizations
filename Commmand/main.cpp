#include <iostream>

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class Receiver {
public:
	void operation() {
		std::cout << "operation..." << std::endl;
	}
};

class ConcreteCommand : public Command {
public:
	Receiver receiver;

	ConcreteCommand(Receiver r) : receiver(r) {}

	void execute() {
		this->receiver.operation();
	}

	void undo() {}
};

class Invoke {
public:
	Command *command;

	void setCommand(Command *c) {
		this->command = c;
	}

	void run() {
		this->command->execute();
	}

	void cancel() {
		this->command->undo();
	}
};

int main() {
	Receiver r;
	Command *c = new ConcreteCommand(r);
	Invoke i;

	i.setCommand(c);
	i.run();

	delete c;

	return 0;
}