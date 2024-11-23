// @author Anbu Krishnan
#include "PlainDisplay.h"
#include "GameBoard.h"
#include <iostream>

int main() {
    GameBoard* gameBoard = GameBoard::getInstance("xyzzy"); // Creates the GameBoard singleton
    PlainDisplay display(gameBoard);                       // Creates a PlainDisplay instance

    // Displays the board
    std::cout << "Initial Board:" << std::endl;
    display.display();

    // Simulates some changes
    gameBoard->setSquareColor(0, 0, Color::RED);
    gameBoard->notifySquareChange(0, 0);

    gameBoard->setSquareColor(1, 1, Color::BLUE);
    gameBoard->notifySquareChange(1, 1);

    // Displays updated board
    std::cout << "\nUpdated Board:" << std::endl;
    display.display();

    return 0;
}
