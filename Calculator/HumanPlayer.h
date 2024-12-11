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

    void decrementLives() override;
    int getLives() const override;
    void setLives(int lives) override;

private:
    std::string name;
    int score;
    int lives;
    Question currentQuestion;
};

#endif // HUMANPLAYER_H
