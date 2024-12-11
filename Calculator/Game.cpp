#include "Game.h"
#include "ComputerPlayer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HumanPlayer.h"

Game::Game(PlayerBase* player1, PlayerBase* player2)
    : player1(player1), player2(player2), currentPlayer(player1), questionCount(0) {
    srand(static_cast<unsigned int>(time(0))); // Willekeurigheid initialiseren
}

void Game::startGame() {
    while (questionCount < 30 && player1->getLives() > 0 && player2->getLives() > 0) {
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

        // De andere speler verliest een leven
        PlayerBase* otherPlayer = (currentPlayer == player1) ? player2 : player1;
        otherPlayer->decrementLives(); // Verlies een leven van de tegenstander

        std::cout << otherPlayer->getName() << " lost a life! Remaining lives: "
                  << otherPlayer->getLives() << std::endl;

        if (otherPlayer->getLives() == 0) {
            std::cout << otherPlayer->getName() << " has no lives left! "
                      << currentPlayer->getName() << " wins the game!" << std::endl;
            exit(0);
        }

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

    int score1 = player1->getScore();
    int score2 = player2->getScore();

    if (score1 > score2) {
        std::cout << player1->getName() << " wins!" << std::endl;
    } else if (score2 > score1) {
        std::cout << player2->getName() << " wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    // Als de computer speler is, geef dan het aantal levens weer
    ComputerPlayer* computerPlayer = dynamic_cast<ComputerPlayer*>(player2);
    if (computerPlayer) {
        std::cout << "You Lost! Computer lives left: " << computerPlayer->getLives() << std::endl; // Toon levens van de computer
    }
}
