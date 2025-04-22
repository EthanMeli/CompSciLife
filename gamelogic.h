#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QString>
#include <vector>
#include <memory>

class PowerUp;
class Tile;

class Player {
public:
    Player(QString name);

    void addMoney(int amount);
    void modifyIncome(float percent);
    void moveForward(int steps);
    void moveBackward(int steps);
    void giveRandomPowerup();
    void notify(const QString& message);

private:
    QString name;
    int position = 0;
    int money = 0;
    float incomeMultiplier = 1.0f;
    std::vector<std::unique_ptr<PowerUp>> powerups;
};

class PowerUp {
    public:
        virtual ~PowerUp() {}
};

// Example power up subclasses, fully implement later
class MovePower : public PowerUp {
    public:
};

class StealPower : public PowerUp {
    public:
};

class MoneyPower : public PowerUp {
    public:
};

class Board {
    public:

    private:
        std::vector<Tile*> tiles;
};

// Singleton LifeManager
class LifeManager {
public:
    static LifeManager* instance();

private:
    LifeManager();
    static LifeManager* _instance;
};
#endif // GAMELOGIC_H
