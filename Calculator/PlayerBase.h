#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include <string>
#include "Question.h"

class PlayerBase {
public:
    virtual ~PlayerBase() = default;

    virtual void incrementScore() = 0;
    virtual int getScore() const = 0;
    virtual std::string getName() const = 0;
    virtual Question& getCurrentQuestion() = 0;
    virtual int getAnswer() const = 0; // Virtuele functie voor polymorfisme
};

#endif // PLAYERBASE_H
