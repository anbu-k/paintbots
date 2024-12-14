// @author Anbu Krishnan - anbu@iastate.edu
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>
#include "GameBoard.h"
#include "RobotAgentRoster.h"
#include "PlainDisplay.h"

class GameLogic
{
private:
    GameBoard *board;
    bool pauseMode;

    void pause();

public:
    GameLogic();
    // loads board config and creates a board
    void playGame(const std::string &boardConfig, const std::string &robotConfig);
    // True or false
    void setPause(bool pausemode);
    // max num of turns
    int turnLimit;
};

#endif
