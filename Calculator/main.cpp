#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main() {
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
    game.startGame();

    delete player1;
    delete player2;

    return 0;
}
