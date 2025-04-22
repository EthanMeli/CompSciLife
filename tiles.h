#ifndef TILES_H
#define TILES_H

#include "gamelogic.h"

enum class TileType {
    EMPTY,
    MONEY,
    POWERUP,
    FORWARD,
    BACKWARD,
    LIFE_EVENT
};

class Tile {
public:
    virtual ~Tile() {}
    virtual void activate(Player& player) = 0;
};

// Tile Types
class EmptyTile : public Tile {
public:
    void activate(Player& player) override;
};

class MoneyTile : public Tile {
public:
    void activate(Player& player) override;
};

class PowerupTile : public Tile {
public:
    void activate(Player& player) override;
};

class MoveForwardTile : public Tile {
public:
    void activate(Player& player) override;
};

class MoveBackwardTile : public Tile {
public:
    void activate(Player& player) override;
};

class LifeEventTile : public Tile {
public:
    void activate(Player& player) override;
};

// Factory
class TileFactory {
public:
    static Tile* createTile(TileType type);
};

#endif // TILES_H
