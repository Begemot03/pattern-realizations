#include <iostream>

class WaterState;

class Water {
public:
	WaterState *state;

	Water(WaterState *s) : state(s) {}

	void heat();

	void frost();

	~Water();
};

class WaterState {
public:
	virtual void heat(Water *w) = 0;
	virtual void frost(Water *w) = 0;
};

class LiquidState : public WaterState {
public:
	void heat(Water*);
	void frost(Water*);
};

class SolidState : public WaterState {
public:
	void heat(Water*);
	void frost(Water*);
};

class GasState : public WaterState {
public:
	void heat(Water*);
	void frost(Water*);
};

void LiquidState::heat(Water *w) {
	std::cout << "Вода превращается в пар" << std::endl;
	delete w->state;
	w->state = new GasState();
}

void LiquidState::frost(Water *w) {
	std::cout << "Вода замораживается" << std::endl;
	delete w->state;
	w->state = new SolidState();
}

void SolidState::heat(Water *w) {
	std::cout << "Превращается в жидкость" << std::endl;
	delete w->state;
	w->state = new LiquidState();
}

void SolidState::frost(Water *w) {
	std::cout << "Вода и так заморажена" << std::endl;
}

void GasState::heat(Water *w) {
	std::cout << "Это уже газ" << std::endl;
}

void GasState::frost(Water *w) {
	std::cout << "Замораживаем газ" << std::endl;
	delete w->state;
	w->state = new LiquidState();
}

void Water::heat() {
	state->heat(this);
}

void Water::frost() {
	state->frost(this);
}

Water::~Water() {
	delete state;
}

int main() {
	WaterState *ws = new LiquidState();
	Water w(ws);

	w.frost();
	w.frost();
	w.heat();
	w.heat();

	return 0;
}