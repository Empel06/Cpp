#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Question.h"

class Player {
public:
    Player(const std::string& name);
    void incrementScore();
    int getScore() const;
    std::string getName() const;
    Question& getCurrentQuestion();

private:
    std::string name;
    int score;
    Question currentQuestion;
};

#endif // PLAYER_H
