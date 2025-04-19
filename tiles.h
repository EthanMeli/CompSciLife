#ifndef TILES_H
#define TILES_H

#include "gamelogic.h"

enum class TileType {
    EMPTY,
    MONEY,
    POWERUP,
    FORWARD,
    BACKWARD
};

class Tile {
    public:
        virtual ~Tile() {}
        //activation method so that player gets affected by the tile
};

// Derived Tiles
class MoneyTile : public Tile {
};

class PowerupTile : public Tile {
};

class MoveForwardTile : public Tile {
};

class MoveBackwardTile : public Tile {
};

// Factory
class TileFactory {
    public:
        static Tile* createTile(TileType type);
};

#endif // TILES_H
