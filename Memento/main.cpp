#include <iostream>
#include <stack>

class HeroMemento {
public:
	int patrons;
	int lives;

	HeroMemento(int patrons, int lives) : patrons(patrons), lives(lives) {}

	HeroMemento clone() {
		return HeroMemento(this->patrons, this->lives);
	}
};

class Hero {
private:
	int patrons;
	int lives;

public:
	Hero() : lives(10), patrons(5) {}

	void shoot() {
		if(patrons > 0) {
			patrons--;
			std::cout << "Делаем выстрел осталось патрон: " << patrons << std::endl;
		} else {
			std::cout << "Патронов нет" << std::endl;
		}
	}

	HeroMemento saveState() {
		std::cout << "Game is saving \n\tlives: " << lives << "\n\t patrons: " << patrons << std::endl;

		return HeroMemento(patrons, lives);
	}

	void restoreState(const HeroMemento& state) {
		patrons = state.patrons;
		lives = state.lives;
	}
};

class GameHistory {
public:
	std::stack<HeroMemento> history;

	void add(HeroMemento state) {
		history.push(state);
	}

	HeroMemento get() {
		HeroMemento t = history.top().clone();
		
		history.pop();
		
		return t;
	}
};

int main() {
	Hero hero;
	hero.shoot();

	GameHistory gameHistory;

	gameHistory.add(hero.saveState());

	hero.shoot();

	hero.restoreState(gameHistory.get());

	hero.shoot();

	return 0;
}