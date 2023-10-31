#include <iostream>
using namespace std;

// Define the abstract base classes for Hero and Enemy.
class Hero {
public:
	virtual void attack() = 0;
	virtual ~Hero() {} // Define a virtual destructor for proper cleanup.
};

class Enemy {
public:
	virtual void attack() = 0;
	virtual ~Enemy() {} // Define a virtual destructor for proper cleanup.
};

// Create specific hero and enemy classes.
class Knight : public Hero {
public:
	void attack() override {
		cout << "Knight attacks with a sword." << endl;
	}
};

class Archer : public Hero {
public:
	void attack() override {
		cout << "Archer attacks with a bow and arrows." << endl;
	}
};

class Goblin : public Enemy {
public:
	void attack() override {
		cout << "Goblin attacks with a club." << endl;
	}
};

class Witch : public Enemy {
public:
	void attack() override {
		cout << "Witch attacks with magic spells." << endl;
	}
};

// Define the abstract factory interface for creating heroes and enemies.
class GameFactory {
public:
	virtual Hero* createHero() = 0;
	virtual Enemy* createEnemy() = 0;
	virtual ~GameFactory() {} // Define a virtual destructor for proper cleanup.
};

// Implement specific factories for the fantasy and science fiction worlds.
class FantasyGameFactory : public GameFactory {
public:
	Hero* createHero() override {
		return new Knight();
	}

	Enemy* createEnemy() override {
		return new Goblin();
	}
};

class SciFiGameFactory : public GameFactory {
public:
	Hero* createHero() override {
		return new Archer();
	}

	Enemy* createEnemy() override {
		return new Witch();
	}
};

// Function to test the factory and create heroes and enemies.
void testFactory(GameFactory* factory) {
	Hero* hero = factory->createHero();
	Enemy* enemy = factory->createEnemy();

	cout << "Heroes and Enemies:" << endl;
	hero->attack();
	enemy->attack();

	delete hero;  // Clean up the created hero object.
	delete enemy; // Clean up the created enemy object.
}

int main() {
	// Create instances of specific factories for fantasy and science fiction worlds.
	GameFactory* fantasyFactory = new FantasyGameFactory();
	GameFactory* sciFiFactory = new SciFiGameFactory();

	cout << "Fantasy World:" << endl;
	testFactory(fantasyFactory); // Test and create heroes and enemies in the fantasy world.

	cout << "\nScience Fiction World:" << endl;
	testFactory(sciFiFactory); // Test and create heroes and enemies in the science fiction world.

	// Clean up the factory instances.
	delete fantasyFactory;
	delete sciFiFactory;

	return 0;
}
