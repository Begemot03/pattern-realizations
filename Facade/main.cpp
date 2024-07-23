#include <iostream>

class TextEditor {
public:
	void createFile() {
		std::cout << "creating file..." << std::endl;
	}

	void saveFile() {
		std::cout << "file saving..." << std::endl;
	}
};

class Compiller {
public:
	void compile() {
		std::cout << "compilling code..." << std::endl;
	}
};

class CLR {
public:
	void execute() {
		std::cout << "running program" << std::endl;
	}

	void stop() {
		std::cout << "stop program" << std::endl;
	}
};

class VisualStudioFacade {
private:
	TextEditor textEditor;
	Compiller compiller;
	CLR clr;
public:
	void start() {
		textEditor.createFile();
		textEditor.saveFile();
		compiller.compile();
		clr.execute();
	}

	void stop() {
		clr.stop();
	}
};

class Programmer {
public:
	void createApp(VisualStudioFacade f) {
		f.start();
		f.stop();
	}
};

int main() {
	VisualStudioFacade f;
	Programmer p;

	p.createApp(f);

	return 0;
}