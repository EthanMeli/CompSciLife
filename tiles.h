#ifndef TILES_H
#define TILES_H

#include "gamelogic.h"
#include <QGraphicsScene>

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
    virtual QColor getColor() { return Qt::white; }
};

// Tile Types
class EmptyTile : public Tile {
public:
    void activate(Player& player) override;
};

class MoneyTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::green; }
};

class PowerupTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return QColorConstants::Svg::purple; }
};

class MoveForwardTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::yellow; }
};

class MoveBackwardTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::red; }
};

class LifeEventTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::blue; }
};

// Factory
class TileFactory {
public:
    static Tile* createTile(TileType type);
};

#endif // TILES_H
