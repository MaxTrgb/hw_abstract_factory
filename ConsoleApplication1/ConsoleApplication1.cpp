#include <iostream>
using namespace std;

class Hero {
public:
    virtual void attack() = 0;
};

class Enemy {
public:
    virtual void attack() = 0;
};

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

class GameFactory {
public:
    virtual Hero* createHero() = 0;
    virtual Enemy* createEnemy() = 0;
};

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

int main() {
    GameFactory* fantasyFactory = new FantasyGameFactory();

    Hero* fantasyHero = fantasyFactory->createHero();
    Enemy* fantasyEnemy = fantasyFactory->createEnemy();

    cout << "Fantasy World:" << endl;
    fantasyHero->attack();
    fantasyEnemy->attack();

    GameFactory* sciFiFactory = new SciFiGameFactory();

    Hero* sciFiHero = sciFiFactory->createHero();
    Enemy* sciFiEnemy = sciFiFactory->createEnemy();

    cout << "\nScience Fiction World:" << endl;
    sciFiHero->attack();
    sciFiEnemy->attack();

    delete fantasyHero;
    delete fantasyEnemy;
    delete sciFiHero;
    delete sciFiEnemy;

    return 0;
}
