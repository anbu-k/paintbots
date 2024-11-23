// @author Anbu Krishnan - anbu@iastate.edu
#include "GameBoard.h"
#include <stdexcept>
#include <cstdlib> // For rand()
#include <iostream>

// Static initialization
GameBoard *GameBoard::uniqueInstance = nullptr;

// Default constructor
GameBoard::GameBoard()
{
    initializeDefaultBoard();
}

// Constructor with Config object
GameBoard::GameBoard(const Config &config)
{
    initializeConfigBoard(config);
}

// default initialization
GameBoard *GameBoard::getInstance(const std::string &password)
{
    if (password != "xyzzy")
    {
        return nullptr;
    }

    if (uniqueInstance == nullptr)
    {
        uniqueInstance = new GameBoard();
    }
    return uniqueInstance;
}

// configuration based initialization
GameBoard *GameBoard::getInstance(const std::string &password, const Config &config)
{
    if (password != "xyzzy")
    {
        return nullptr;
    }

    if (uniqueInstance == nullptr)
    {
        uniqueInstance = new GameBoard(config);
    }
    return uniqueInstance;
}

// Accesses a square on the board
InternalBoardSquare &GameBoard::getSquare(int row, int col)
{
    if (row < 0 || row >= 15 || col < 0 || col >= 15)
    {
        throw std::out_of_range("Row or column out of bounds");
    }
    return board[row][col];
}

// Initializes the board with default settings
void GameBoard::initializeDefaultBoard()
{
    board = std::vector<std::vector<InternalBoardSquare>>(15, std::vector<InternalBoardSquare>(15));
    redRobotRow = 0;
    redRobotCol = 0;
    blueRobotRow = 14;
    blueRobotCol = 14;
}

// Initializes the board based on configuration
void GameBoard::initializeConfigBoard(const Config &config)
{
    initializeDefaultBoard();

    int rockCount = config.getRockLowerBound();
    int fogCount = config.getFogLowerBound();

    // Place rocks
    for (int i = 0; i < rockCount; ++i)
    {
        int row = rand() % 15;
        int col = rand() % 15;
        board[row][col].setSquareType(SquareType::ROCK);
        notifySquareChange(row, col);
    }

    // Place fog
    for (int i = 0; i < fogCount; ++i)
    {
        int row = rand() % 15;
        int col = rand() % 15;
        board[row][col].setSquareType(SquareType::FOG);
        notifySquareChange(row, col);
    }
}

// performs the request move on the designated robot
bool GameBoard::MoveRobot(RobotMoveRequest &mr)
{
    int &robotRow = (mr.robot == RobotColor::XRED) ? redRobotRow : blueRobotRow;
    int &robotCol = (mr.robot == RobotColor::XRED) ? redRobotCol : blueRobotCol;

    moveRobot(mr, robotRow, robotCol);

    // Updates the square the robot moves off of
    board[robotRow][robotCol].setSquareColor((mr.robot == RobotColor::XRED) ? Color::RED : Color::BLUE);
    notifyRobotMove(mr);
    return true;  // always returns true since a move can always be made
}

// Checks if paint blob hits, returns true if the robot specified in RobotMoveRequest structure would hit the other robot if it fired
bool GameBoard::PaintBlobHit(RobotMoveRequest &mr)
{
    // Determines the target robots position
    int targetRow = (mr.robot == RobotColor::XRED) ? blueRobotRow : redRobotRow;
    int targetCol = (mr.robot == RobotColor::XRED) ? blueRobotCol : redRobotCol;

    // returns true if the square at the target position is not a ROCK, and false otherwise
    return !(board[targetRow][targetCol].getSquareType() == SquareType::ROCK);
}

//  returns the number of blue squares on the board 
int GameBoard::blueScore() const
{
    int score = 0;
    for (const auto &row : board)
    {
        for (const auto &square : row)
        {
            if (square.getSquareColor() == Color::BLUE)
            {
                ++score;
            }
        }
    }
    return score;
}

 // Sets the square color in the board
void GameBoard::setSquareColor(int row, int col, Color c)
{
    if (row >= 0 && row < 15 && col >= 0 && col < 15)
    {
        board[row][col].setSquareColor(c);
        notifySquareChange(row, col);
    }
}

// Sets the specified robot to pain a specific color
void GameBoard::setRobotPaintColor(RobotColor robot, Color c)
{
    if (robot == RobotColor::XRED)
    {
        board[redRobotRow][redRobotCol].setSquareColor(c);
    }
    else
    {
        board[blueRobotRow][blueRobotCol].setSquareColor(c);
    }
    notifyScoreChange();
}

// returns the number of red squares on the board
int GameBoard::redScore() const
{
    int score = 0;
    for (const auto &row : board)
    {
        for (const auto &square : row)
        {
            if (square.getSquareColor() == Color::RED)
            {
                ++score;
            }
        }
    }
    return score;
}

// Notifies observers of a square change
void GameBoard::notifySquareChange(int row, int col)
{
    notifyObservers(new std::string("Square changed at (" + std::to_string(row) + ", " + std::to_string(col) + ")"));
}

// Notifies observers of any robot movement
void GameBoard::notifyRobotMove(RobotMoveRequest &mr)
{
    notifyObservers(new std::string("Robot moved: " + std::string((mr.robot == RobotColor::XRED) ? "Red" : "Blue")));
}

// Notifies observers of a score change
void GameBoard::notifyScoreChange()
{
    notifyObservers(new std::string("Score updated. Red: " + std::to_string(redScore()) + ", Blue: " + std::to_string(blueScore())));
}

// Helper to move robot based on the RobotMove direction
void GameBoard::moveRobot(RobotMoveRequest &mr, int &robotRow, int &robotCol)
{
    switch (mr.move)
    {
    case RobotMove::FORWARD:
        robotRow = std::max(0, std::min(14, robotRow + 1));
        break;
    case RobotMove::ROTATELEFT:
    case RobotMove::ROTATERIGHT:
    case RobotMove::NONE:
        break;
    }
}