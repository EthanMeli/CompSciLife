#include "gamelogic.h"
#include <QDebug>
#include <random>

// ------------------------- POWER UP METHODS -------------------------

/**
 * @brief Applies the Job Promotion power up.
 * @param player The player using the power up.
 * Moves the player forward by 3 spaces and notifies them.
 */
// TODO: Move a certain amount of tiles forward and receive a 50% paycheck for being the best intern in your company.
void MovePower::apply(Player& player) {
    player.moveForward(3);
    player.notify("Used Jon Promotion! Advanced 3 spaces.");
}

/**
 * @brief Gets the name of the power up.
 * @return The name of the power up.
 */
// Returns the name of the power.
QString MovePower::name() const {
    return "Job Promotion";
}

/**
 * @brief Applies the Bank Account Hack power up.
 * @param player The player using the power up.
 * Adds $50 to the player's money.
 */
// TODO: Will be revised later so that a percentage of money is taken.
void StealPower::apply(Player& player) {
    player.addMoney(50); // Placeholder effect for stealing
    player.notify("Used Bank Account Hack! Gained $50.");
}
QString StealPower::name() const {
    return "Bank Account Hack";
}

/**
 * @brief Applies the Energy Drink power up.
 * @param player The player using the power up.
 * Adds $100 to the player's money.
 */
// TODO: Change this placeholder power up into the Energy Drink power up that skips opponent's turn
void MoneyPower::apply(Player& player) {
    player.addMoney(100);
    player.notify("Used Energy Drink! Gained $100.");
}
QString MoneyPower::name() const {
    return "Energy Drink";
}

// ------------------------- PLAYER METHODS -------------------------

/**
 * @brief Constructs a new Player.
 * @param name The name of the player.
 */
Player::Player(QString name) : name(name) {}

/**
 * @brief Adds money to the player's total.
 * @param amount The amount to add.
 */
void Player::addMoney(int amount) {
    money += amount;
}

/**
 * @brief Modifies the player's income multiplier.
 * @param percent The percent change to apply.
 */
void Player::modifyIncome(float percent) {
    incomeMultiplier += percent;
}

/**
 * @brief Moves the player forward by a number of steps.
 * @param steps The number of steps to move forward.
 */
void Player::moveForward(int steps) {
    position += steps;
}

/**
 * @brief Moves the player backward by a number of steps, but not below 0.
 * @param steps The number of steps to move backward.
 */
void Player::moveBackward(int steps) {
    position = std::max(0, position - steps);
}

/**
 * @brief Gives the player a random power up.
 * No parameters or return value.
 */
void Player::giveRandomPowerup() {
    int r = rand() % 3;
    switch (r) {
    case 0:
        powerups.push_back(std::make_unique<MovePower>());
        notify("Gained Power-Up: Move Power!");
        break;
    case 1:
        powerups.push_back(std::make_unique<StealPower>());
        notify("Gained Power-Up: Steal Power!");
        break;
    case 2:
        powerups.push_back(std::make_unique<MoneyPower>());
        notify("Gained Power-Up: Money Power!");
        break;
    }
}

/**
 * @brief Gets the list of power ups the player has.
 * @return A const reference to the player's power up vector.
 */
const std::vector<std::unique_ptr<PowerUp>>& Player::getPowerups() const {
    return powerups;
}

/**
 * @brief Uses the power up at a given index.
 * @param index The index of the power up to use.
 */
void Player::usePowerup(int index) {
    if (index >= 0 && index < static_cast<int>(powerups.size())) {
        powerups[index]->apply(*this);
        powerups.erase(powerups.begin() + index);
    }
}

/**
 * @brief Prints a message to the debug console.
 * @param message The message to display.
 */
void Player::notify(const QString& message) {
    qDebug() << name << ":" << message;
}
