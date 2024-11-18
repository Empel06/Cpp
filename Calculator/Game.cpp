#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(PlayerBase* player1, PlayerBase* player2)
    : player1(player1), player2(player2), currentPlayer(player1), questionCount(0) {
    srand(static_cast<unsigned int>(time(0))); // Willekeurigheid initialiseren
}

void Game::startGame() {
    while (questionCount < 10) {
        askQuestion();
    }
    displayScores();
}

void Game::askQuestion() {
    Question& currentQuestion = currentPlayer->getCurrentQuestion();
    currentQuestion.generateQuestion();
    std::cout << currentPlayer->getName() << ", your question is: " << currentQuestion.getQuestion() << std::endl;

    int answer = currentPlayer->getAnswer();

    if (checkAnswer(answer)) {
        std::cout << "Correct!" << std::endl;
        currentPlayer->incrementScore();
    } else {
        std::cout << "Wrong answer!" << std::endl;
    }

    switchTurn();
    questionCount++;
}

bool Game::checkAnswer(int answer) {
    return currentPlayer->getCurrentQuestion().checkAnswer(answer);
}

void Game::switchTurn() {
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

void Game::displayScores() {
    std::cout << "Final scores: " << std::endl;
    std::cout << player1->getName() << ": " << player1->getScore() << std::endl;
    std::cout << player2->getName() << ": " << player2->getScore() << std::endl;
}
