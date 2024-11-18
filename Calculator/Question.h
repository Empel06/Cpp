#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    Question();
    void generateQuestion();
    std::string getQuestion() const;
    bool checkAnswer(int answer) const;

private:
    int num1, num2, correctAnswer;
    char operation;
    std::string questionStr;
};

#endif // QUESTION_H

