// @author Anbu Krishnan - anbu@iastate.edu
#include "GameLogic.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>

GameLogic::GameLogic() : board(nullptr), pauseMode(true), turnLimit(300) {}

// pauses game
void GameLogic::setPause(bool pause)
{
    pauseMode = pause;
}

// starts the game / game logic / checks if the config files are valid
void GameLogic::playGame(const std::string &boardConfig, const std::string &robotConfig)
{
    // loads robot names from robotConfig.txt file
    std::ifstream robotFile(robotConfig);
    std::string redRobotName, blueRobotName;
    std::getline(robotFile, redRobotName);
    std::getline(robotFile, blueRobotName);

    // gets robot agents
    RobotAgentRoster *roster = RobotAgentRoster::getInstance();
    IRobotAgent *redAgent = (*roster)[redRobotName];
    IRobotAgent *blueAgent = (*roster)[blueRobotName];

    if (!redAgent || !blueAgent)
    {
        std::cerr << "Invalid robot names in configuration file: "
                  << redRobotName << " or " << blueRobotName << std::endl;
        return;
    }

    // initializes game board
    Config config(boardConfig);
    board = GameBoard::getInstance("xyzzy", config);
    if (!board)
    {
        std::cerr << "Error: Invalid password or failed to initialize GameBoard." << std::endl;
        return;
    }

    PlainDisplay display(board);

    // sets robot colors for strategies
    redAgent->setRobotColor(Robot::RobotColor::RED);
    blueAgent->setRobotColor(Robot::RobotColor::BLUE);

    int turnCount = 0;

    while (!board->isGameOver() && turnCount < turnLimit)
    {
        ++turnCount;

        // gets moves from both robots
        auto *redMove = redAgent->getMove(board->getShortRangeScan(Robot::RobotColor::RED),
                                          board->getLongRangeScan());
        auto *blueMove = blueAgent->getMove(board->getShortRangeScan(Robot::RobotColor::BLUE),
                                            board->getLongRangeScan());

        // Red Robots move
        if (board->isValidMove(Robot::RobotColor::RED, *redMove))
        {
            board->applyMove(Robot::RobotColor::RED, *redMove);
        }
        else
        {
            std::cerr << "Red Robot attempted an invalid move!" << std::endl;
            break;
        }

        // Blue robots move
        if (board->isValidMove(Robot::RobotColor::BLUE, *blueMove))
        {
            board->applyMove(Robot::RobotColor::BLUE, *blueMove);
        }
        else
        {
            std::cerr << "Blue Robot attempted an invalid move!" << std::endl;
            break;
        }

        // paint blob shooting
        if (redMove->shoot && board->PaintBlobHit(*redMove))
        {
            board->setRobotPaintColor(Robot::RobotColor::BLUE, Color::RED);
        }
        if (blueMove->shoot && board->PaintBlobHit(*blueMove))
        {
            board->setRobotPaintColor(Robot::RobotColor::RED, Color::BLUE);
        }

        //  updated board
        display.display();

        // clean up move requests
        delete redMove;
        delete blueMove;

        if (pauseMode)
            pause();
    }

    // winner
    std::cout << "Game Over after " << turnCount << " turns! Winner: " << board->getWinner() << std::endl;
}

// pauses game
void GameLogic::pause()
{
    std::cout << "Press Enter to continue...";
    std::cin.get();
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <boardconfig> <robotconfig>" << std::endl;
        return 1;
    }

    RobotAgentRoster *roster = RobotAgentRoster::getInstance();
    roster->initialize(); // Registers all robot agents

    GameLogic game;
    game.setPause(true); // Turns on pause mode
    game.playGame(argv[1], argv[2]);

    return 0;
}
