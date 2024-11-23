// @author Anbu Krishnan - anbu@iastate.edu
#ifndef PLAINDISPLAY_H
#define PLAINDISPLAY_H

#include "ObserverPattern.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

//  this class is an observer for the GameBoard class + it outputs the state of the game board in ASCII
class PlainDisplay : public Observer<std::string>
{
private:
    GameBoard *gameBoard;

public:
    PlainDisplay(GameBoard *gameBoard);  // Constructor + initializes the PlainDisplay and registers it as an observer for the GameBoard
    ~PlainDisplay(); // Destructor + unregisters the PlainDisplay from the GameBoard                   

    void update(std::string *message) override; // Update method
    void display();                             // Displays ASCII board
};

#endif
