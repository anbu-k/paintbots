// @author Anbu Krishnan
#include "PlainDisplay.h"
#include "GameBoard.h"
#include <iostream>

int main() {
    GameBoard* gameBoard = GameBoard::getInstance("xyzzy"); // Create the GameBoard singleton
    PlainDisplay display(gameBoard);                       // Create PlainDisplay instance

    // Display the board
    std::cout << "Initial Board:" << std::endl;
    display.display();

    // Simulate some changes
    gameBoard->setSquareColor(0, 0, Color::RED);
    gameBoard->notifySquareChange(0, 0);

    gameBoard->setSquareColor(1, 1, Color::BLUE);
    gameBoard->notifySquareChange(1, 1);

    // Display updated board
    std::cout << "\nUpdated Board:" << std::endl;
    display.display();

    return 0;
}
