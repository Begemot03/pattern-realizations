#include <iostream>

class Language {
public:
	virtual void execute() = 0;
	virtual void build() = 0;

	virtual ~Language() {
		std::cout << "Goobay programmer language" << std::endl;
	}
};

class CPPLang : public Language {
public:
	void execute() {
		std::cout << "Running binary file" << std::endl;
	}

	void build() {
		std::cout << "Glang traslate .cpp file to binary file" << std::endl;
	}
};

class CSharpLang : public Language {
public:
	void execute() {
		std::cout << "CLS running exe file" << std::endl;
	}

	void build() {
		std::cout << "Rosyn compiling exe file from c# file" << std::endl;
	}
};

class Programmer {
protected:
	Language *lang;

public:
	Programmer(Language *l) : lang(l) {}

	virtual ~Programmer() {
		delete lang;
	}

	virtual void earn() = 0;
	virtual void work() {
		lang->build();
		lang->execute();
	}

	virtual	void setLang(Language *l) {
		delete this->lang;
		this->lang = l;
	}
};

class FreelanceProgrammer : public Programmer {
public:
	FreelanceProgrammer(Language *l) : Programmer(l) {}

	void earn() {
		std::cout << "Get money after what" << std::endl;
	}
};

int main() {
	Programmer *frp = new FreelanceProgrammer(new CPPLang());
	frp->work();
	frp->earn();

	frp->setLang(new CSharpLang);
	frp->work();
	frp->earn();

	delete frp;

	return 0;
}