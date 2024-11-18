#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name) : name(name), score(0) {}

void HumanPlayer::incrementScore() {
    score++;
}

int HumanPlayer::getScore() const {
    return score;
}

std::string HumanPlayer::getName() const {
    return name;
}

Question& HumanPlayer::getCurrentQuestion() {
    return currentQuestion;
}

int HumanPlayer::getAnswer() const {
    int answer;
    std::cin >> answer;
    return answer;
}
