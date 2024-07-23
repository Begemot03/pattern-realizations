#include <iostream>
#include <list>
#include <string>

class Component {
public:
	std::string name;

	Component(std::string name) : name(name) {}

	virtual void add(Component *c) = 0;
	virtual void remove(Component *c) = 0;
	virtual void display(int lvl = 0) = 0;

	virtual ~Component() {
		std::cout << "Deleting " << name << "..." << std::endl;
	}
};

class Directory : public Component {
private:
	std::list<Component *> children;
public:
	Directory(std::string name) : Component(name) {}

	void add(Component *c) {
		children.push_back(c);
	}

	void remove(Component *c) {
		children.remove(c);
		delete c;
	}

	void display(int lvl = 0) {
		for(int i = 0; i < lvl; i++)
			std::cout << "\t";
		std::cout << "|" << name << std::endl;

		for(std::list<Component *>::iterator it = children.begin(); it != children.end(); ++it) {
			(*it)->display(lvl+1);
		}
	}

	~Directory() {
		std::cout << "Deleting directory..." << std::endl;

		for(std::list<Component *>::iterator it = children.begin(); it != children.end(); ++it) {
			delete (*it);
		}
	}
};

class File : public Component {
public:
	File(std::string name) : Component(name) {}

	void add(Component *c) {}

	void remove(Component *c) {}

	void display(int lvl = 0) {
		for(int i = 0; i < lvl; i++)
			std::cout << "\t";
		std::cout << "|" << name << std::endl;
	}
};

int main() {
	Component *root = new Directory("/");
	Component *dir = new Directory("/temp");
	Component *dir1 = new Directory("/val");

	dir1->add(new File("dir1 1"));
	dir1->add(new File("dir1 2"));
	dir1->add(new File("dir1 3"));

	dir->add(dir1);

	dir->add(new File("uniq 1"));

	root->add(dir);

	root->add(new File("uniq 2"));
	root->add(new File("uniq 3"));
	root->add(new File("uniq 4"));

	root->display();

	std::cout << "\n\n\n\ndeleting root...";
	delete root;

	return 0;
}