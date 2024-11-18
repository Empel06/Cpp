#include "Question.h"
#include <cstdlib>
#include <ctime>

Question::Question() : num1(0), num2(0), correctAnswer(0), operation('+') {}

void Question::generateQuestion() {
    srand(time(0)); // Zet een seed voor random getallen

    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    int op = rand() % 4; // Kies een willekeurige operator

    switch (op) {
    case 0: operation = '+'; correctAnswer = num1 + num2; break;
    case 1: operation = '-'; correctAnswer = num1 - num2; break;
    case 2: operation = '*'; correctAnswer = num1 * num2; break;
    case 3: operation = '/';
        while (num2 == 0) num2 = rand() % 100 + 1; // Zorg ervoor dat we niet delen door 0
        correctAnswer = num1 / num2; break;
    }

    questionStr = std::to_string(num1) + " " + operation + " " + std::to_string(num2);
}

std::string Question::getQuestion() const {
    return questionStr;
}

bool Question::checkAnswer(int answer) const {
    return answer == correctAnswer;
}
