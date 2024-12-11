#include "Question.h"
#include <cstdlib>
#include <ctime>

Question::Question() : num1(0), num2(0), correctAnswer(0), operation('+') {}

void Question::setLevel(int level) {
    this->level = level;
}

void Question::generateQuestion() {
    // srand(static_cast<unsigned int>(time(0))); // Zorg dat de random generator seed heeft

    if (level == 1) {
        operation = (rand() % 2 == 0) ? '+' : '-';
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Bereken het juiste antwoord
        if (operation == '+') {
            correctAnswer = num1 + num2;
        } else {
            correctAnswer = num1 - num2;
        }
    } else if (level == 2) {
        // Logica voor medium niveau
        int op = rand() % 4;
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        switch (op) {
        case 0: operation = '+'; correctAnswer = num1 + num2; break;
        case 1: operation = '-'; correctAnswer = num1 - num2; break;
        case 2: operation = '*'; correctAnswer = num1 * num2; break;
        case 3: operation = '/';
            while (num2 == 0 || num1 % num2 != 0) num2 = rand() % 100 + 1;
            correctAnswer = num1 / num2; break;
        }
    } else {
        // Logica voor moeilijk niveau
        int op = rand() % 4;
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        switch (op) {
        case 0: operation = '+'; correctAnswer = num1 + num2; break;
        case 1: operation = '-'; correctAnswer = num1 - num2; break;
        case 2: operation = '*'; correctAnswer = num1 * num2; break;
        case 3: operation = '/';
            while (num2 == 0 || num1 % num2 != 0) num2 = rand() % 100 + 1;
            correctAnswer = num1 / num2; break;
        }
    }

    questionStr = std::to_string(num1) + " " + operation + " " + std::to_string(num2);
}


std::string Question::getQuestion() const {
    return questionStr;
}

bool Question::checkAnswer(int answer) const {
    return answer == correctAnswer;
}
