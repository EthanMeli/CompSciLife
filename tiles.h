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
    virtual QString getType() { return "Tile"; }
};

// Tile Types
class EmptyTile : public Tile {
public:
    void activate(Player& player) override;
    QString getType() override { return "EmptyTile"; }
};

class MoneyTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::green; }
    QString getType() override { return "MoneyTile"; }
};

class PowerupTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return QColorConstants::Svg::purple; }
    QString getType() override { return "PowerupTile"; }
};

class MoveForwardTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::yellow; }
    QString getType() override { return "MoveForwardTile"; }
};

class MoveBackwardTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::red; }
    QString getType() override { return "MoveBackwardTile"; }
};

class LifeEventTile : public Tile {
public:
    void activate(Player& player) override;
    QColor getColor() override { return Qt::blue; }
    QString getType() override { return "LifeEventTile"; }
};

// Factory
class TileFactory {
public:
    static Tile* createTile(TileType type);
};

#endif // TILES_H
