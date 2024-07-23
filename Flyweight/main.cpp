#include <iostream> 
#include <map>
#include <string>

class House {
protected:
	int stages;
public:
	virtual void build(int, int) = 0;
};

class PanelHouse : public House {
public:
	PanelHouse() {
		stages = 16;
	}

	void build(int longe, int lat) {
		std::cout << "Building panel house long: " << longe << " lat: " << lat << std::endl;
	}
};

class BrickHouse : public House {
public:
	BrickHouse() {
		stages = 5;
	}

	void build(int longe, int lat) {
		std::cout << "Building brick house long: " << longe << " lat: " << lat << std::endl;
	}
};

class HouseFactory {
private:
	std::map<std::string, House *> houses;
public:
	HouseFactory() {
		houses["Panel"] = new PanelHouse();
		houses["Brick"] = new BrickHouse();
	}

	House * getHouse(std::string name) {
		if(houses.find(name) != houses.end()) {
			return houses[name];
		} else {
			return NULL;
		}
	}

	~HouseFactory() {
		delete houses["Panel"];
		delete houses["Brick"];
	}
};


int main() {
	int longe = 5;
	int lat = 5;

	HouseFactory f;

	for(int i = 0; i < 5; i++) {
		House *h = f.getHouse("Panel");
		if(h != NULL) {
			h->build(longe, lat);
		}
		longe++;
		lat++;
	}

	for(int i = 0; i < 5; i++) {
		House *h = f.getHouse("Brick");
		if(h != NULL) {
			h->build(longe, lat);
		}
		longe++;
		lat++;
	}

	return 0;
}