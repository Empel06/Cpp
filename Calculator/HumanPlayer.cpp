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
    while (true) {
        std::cout << "Enter answer:";
        std::cin >> answer;

        if (std::cin.fail()){
            std::cin.clear(); // Reset de cin foutstatus
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Verwijder de ongeldige invoer
            std::cout << "Invalid input. Please enter a number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Verwijder de rest van de invoer
            break;
        }
    }
    return answer;
}
