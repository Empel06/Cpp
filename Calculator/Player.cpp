#include "Player.h"

Player::Player(const std::string& name) : name(name), score(0) {}

void Player::incrementScore() {
    score++;
}

int Player::getScore() const {
    return score;
}

std::string Player::getName() const {
    return name;
}

Question& Player::getCurrentQuestion() {
    return currentQuestion;
}
