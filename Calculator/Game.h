#ifndef GAME_H
#define GAME_H

#include "PlayerBase.h" // Basisklasse gebruiken
#include "Question.h"

class Game {
public:
    Game(PlayerBase* player1, PlayerBase* player2); // Gebruik PlayerBase*
    void startGame();
    void askQuestion();
    bool checkAnswer(int answer);
    void switchTurn();
    void displayScores();

private:
    PlayerBase* player1; // Verwijzing naar PlayerBase*
    PlayerBase* player2;
    PlayerBase* currentPlayer;
    int questionCount;
};

#endif // GAME_H

