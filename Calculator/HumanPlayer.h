#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "PlayerBase.h"
#include <iostream>
#include <limits>

class HumanPlayer : public PlayerBase {
public:
    HumanPlayer(const std::string& name);
    void incrementScore() override;
    int getScore() const override;
    std::string getName() const override;
    Question& getCurrentQuestion() override;
    int getAnswer() const override;

private:
    std::string name;
    int score;
    Question currentQuestion;
};

#endif // HUMANPLAYER_H
