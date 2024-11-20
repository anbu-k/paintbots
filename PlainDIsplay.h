// @author Anbu Krishnan - anbu@iastate.edu
#ifndef PLAINDISPLAY_H
#define PLAINDISPLAY_H

#include "ObserverPattern.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

class PlainDisplay : public Observer<std::string> {
private:
    GameBoard* gameBoard;

public:
    PlainDisplay(GameBoard* gameBoard); // Constructor
    ~PlainDisplay();                    // Destructor

    void update(std::string* message) override; // Update method
    void display();                              // Display ASCII board
};

#endif // PLAINDISPLAY_H
