#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(const std::string& name) : name(name), score(0), lives(10) {}

void ComputerPlayer::incrementScore() {
    score++;
}

int ComputerPlayer::getScore() const {
    return score;
}

std::string ComputerPlayer::getName() const {
    return name;
}

Question& ComputerPlayer::getCurrentQuestion() {
    return currentQuestion;
}

int ComputerPlayer::getAnswer() const {
    return rand() % 200; // Willekeurig antwoord voor de computer
}

void ComputerPlayer::setLives(int lives) {
    // Geen functionaliteit nodig voor de computer, laat leeg.
}

void ComputerPlayer::decrementLives(){
    if (lives > 0){
        lives--;
    }
}

int ComputerPlayer::getLives() const {
    return lives;
}
