#include "tiles.h"
#include "moneypopupdialog.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Creates and returns a new tile based on the specified type.
 * @param type The type of tile to create (enum: TileType).
 * @return Pointer to a dynamically allocated Tile object of the appropriate subclass.
 */
Tile* TileFactory::createTile(TileType type) {
    switch (type) {
        case TileType::EMPTY:     return new EmptyTile();
        case TileType::MONEY:     return new MoneyTile();
        case TileType::POWERUP:   return new PowerupTile();
        case TileType::FORWARD:   return new MoveForwardTile();
        case TileType::BACKWARD:  return new MoveBackwardTile();
        case TileType::LIFE_EVENT:return new LifeEventTile();
        default:                  return new EmptyTile();
    }
}

/**
 * @brief Activates the EmptyTile. Does nothing.
 * @param player Reference to the Player interacting with this tile.
 */
void EmptyTile::activate(Player& player) {
    // Contemplate life.
}

/**
 * @brief Activates the MoneyTile. Adds $100 to the player's balance.
 * @param player Reference to the Player interacting with this tile.
 */
void MoneyTile::activate(Player& player) {
    player.addMoney(100);

    MoneyPopupDialog popup;
    popup.exec();  // Modal dialog
}

/**
 * @brief Activates the PowerupTile. Grants the player a random power-up.
 * @param player Reference to the Player interacting with this tile.
 */
void PowerupTile::activate(Player& player) {
    player.giveRandomPowerup();
}

/**
 * @brief Activates the MoveForwardTile. Moves the player forward 1-5 steps.
 * @param player Reference to the Player interacting with this tile.
 */
void MoveForwardTile::activate(Player& player) {
    int steps = rand() % 5 + 1;
    player.moveForward(steps);
    switch (steps) {
        case 1: player.notify("Your parents send their support."); break;
        case 2: player.notify("You fixed all the bugs during an all-nighter!"); break;
        case 3: player.notify("Stack Exchange came through with perfect docs."); break;
        case 4: player.notify("You're typing faster than light!"); break;
        case 5: player.notify("It worked on the first try?!"); break;
    }
}

/**
 * @brief Activates the MoveBackwardTile. Moves the player backward 1-5 steps.
 * @param player Reference to the Player interacting with this tile.
 */
void MoveBackwardTile::activate(Player& player) {
    int steps = rand() % 5 + 1;
    player.moveBackward(steps);
    switch (steps) {
        case 1: player.notify("You did your partner’s part of the group project."); break;
        case 2: player.notify("You missed the project meeting!"); break;
        case 3: player.notify("You got sick, and your prof said 'tough luck'."); break;
        case 4: player.notify("Endless bugs... try reinstalling VSCode?"); break;
        case 5: player.notify("You deleted System32. RIP. Also lost $50.");
                player.addMoney(-50); break;
    }
}

/**
 * @brief Activates the LifeEventTile. Simulates a life event like exams or interviews with random outcomes (Depends on Dice Roll).
 * @param player Reference to the Player interacting with this tile.
 */
void LifeEventTile::activate(Player& player) {
    int roll = rand() % 6 + 1;

    if (roll <= 2) {
        player.notify("You had a job interview!");
        if (roll == 1) {
            player.notify("You failed. Nothing happens.");
        } else {
            player.notify("You're the new CEO! +30% income.");
            player.modifyIncome(0.30f);
        }
    } else if (roll <= 4) {
        player.notify("Final Exam for CSCI 3010...");
        if (roll == 3) {
            player.notify("You failed. Move back 2 steps.");
            player.moveBackward(2);
        } else {
            player.notify("Reported for potential cheating. Move back 1 step.");
            player.moveBackward(1);
        }
    } else {
        player.notify("Your project is due at 11:59PM!");
        if (roll == 5) {
            player.notify("You turned it in at 11:58PM. Nothing happens.");
        } else {
            player.notify("You turned it in 5 months ago. Move forward 2 steps.");
            player.moveForward(2);
        }
    }
}
