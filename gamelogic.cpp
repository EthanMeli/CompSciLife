#include "gamelogic.h"
#include <QDebug>

Player::Player(QString name) : name(name) {}

void Player::addMoney(int amount) {
    money += amount;
}

void Player::modifyIncome(float percent) {
    incomeMultiplier += percent;
}

void Player::moveForward(int steps) {
    position += steps;
}

void Player::moveBackward(int steps) {
    position = std::max(0, position - steps);
}

void Player::giveRandomPowerup() {
    // Temporary placeholder logic
    powerups.push_back(std::make_unique<MovePower>());
}

void Player::notify(const QString& message) {
    qDebug() << name << ":" << message;
}
