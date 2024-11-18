#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "PlayerBase.h"
#include <cstdlib>

class ComputerPlayer : public PlayerBase {
public:
    ComputerPlayer(const std::string& name);
    void incrementScore() override;
    int getScore() const override;
    std::string getName() const override;
    Question& getCurrentQuestion() override;
    int getAnswer() const override;
    void decrementLives();
    int getLives() const;

private:
    std::string name;
    int score;
    int lives;
    Question currentQuestion;
};

#endif // COMPUTERPLAYER_H
