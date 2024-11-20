// @author Anbu Krishnan - anbu@iastate.edu
#include "PlainDisplay.h"
#include "GameBoard.h"
#include <iostream>

// Constructor
PlainDisplay::PlainDisplay(GameBoard *gameBoard) : gameBoard(gameBoard)
{
    gameBoard->registerObserver(this);
}

// Destructor
PlainDisplay::~PlainDisplay()
{
    gameBoard->removeObserver(this);
}

// Update method for the observer
void PlainDisplay::update(std::string *message)
{
    std::cout << "Update received: " << *message << std::endl;
    delete message;
    display();
}

// Display the ASCII board
void PlainDisplay::display()
{
    for (int row = 0; row < 15; ++row)
    {
        for (int col = 0; col < 15; ++col)
        {
            InternalBoardSquare &square = gameBoard->getSquare(row, col);

            char color = (square.getSquareColor() == Color::RED) ? 'R' : (square.getSquareColor() == Color::BLUE) ? 'B'
                                                                                                                  : 'W';
            char robot = square.redRobotPresent() ? 'R' : square.blueRobotPresent() ? 'B'
                                                                                    : '-';
            char rock = (square.getSquareType() == SquareType::ROCK) ? 'X' : '-';
            char fog = (square.getSquareType() == SquareType::FOG) ? 'X' : '-';

            std::cout << color << robot << rock << fog << " ";
        }
        std::cout << std::endl;
    }
}
