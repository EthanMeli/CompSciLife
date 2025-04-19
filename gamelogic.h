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
