#include <iostream>
#include <ctime>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seeding voor random generator

    std::string player1Name, player2Name;
    std::cout << "Enter name for Player 1: ";
    std::cin >> player1Name;

    PlayerBase* player1 = new HumanPlayer(player1Name);

    std::cout << "Do you want to play against a computer? (y/n): ";
    char choice;
    std::cin >> choice;

    PlayerBase* player2;
    if (choice == 'y') {
        player2 = new ComputerPlayer("Computer");
    } else {
        std::cout << "Enter name for Player 2: ";
        std::cin >> player2Name;
        player2 = new HumanPlayer(player2Name);
    }

    Game game(player1, player2);

    int level;
    std::cout << "Select difficulty level (1: Easy, 2: Medium, 3: Hard): ";
    std::cin >> level;

    // Stel het aantal levens in op basis van moeilijkheidsgraad
    int lives = (level == 1) ? 15 : (level == 2) ? 10 : 7;

    player1->getCurrentQuestion().setLevel(level);
    player2->getCurrentQuestion().setLevel(level);

    dynamic_cast<HumanPlayer*>(player1)->setLives(lives);
    if (choice != 'y') {
        dynamic_cast<HumanPlayer*>(player2)->setLives(lives);
    }

    game.startGame();

    delete player1;
    delete player2;

    return 0;
}
