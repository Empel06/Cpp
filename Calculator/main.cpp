#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::string player1Name, player2Name;
    std::cout << "Enter name for Player 1: ";
    std::cin >> player1Name;

    PlayerBase* player1 = new HumanPlayer(player1Name);

    std::cout << "Do you want to play against a computer? (y/n): ";
    char choice;
    std::cin >> choice;

    PlayerBase* player2 = (choice == 'y') ? static_cast<PlayerBase*>(new ComputerPlayer("Computer")) : new HumanPlayer(player2Name);
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

    player1->getCurrentQuestion().setLevel(level);
    player2->getCurrentQuestion().setLevel(level);

    game.startGame();

    delete player1;
    delete player2;

    return 0;
}
