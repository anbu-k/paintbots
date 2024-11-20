// @author Anbu Krishnan - anbu@iastate.edu
#include "GameBoard.h"
#include <stdexcept>
#include <cstdlib> // For rand()
#include <iostream>

// Static instance initialization
GameBoard *GameBoard::uniqueInstance = nullptr;

// Default constructor
GameBoard::GameBoard()
{
    initializeDefaultBoard();
}

// Constructor with Config object
GameBoard::GameBoard(const Config &config)
{
    initializeBoardFromConfig(config);
}

// Static method to get instance with default initialization
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

// Access a square on the board
InternalBoardSquare &GameBoard::getSquare(int row, int col)
{
    if (row < 0 || row >= 15 || col < 0 || col >= 15)
    {
        throw std::out_of_range("Row or column out of bounds");
    }
    return board[row][col];
}

// Initialize the board with default settings
void GameBoard::initializeDefaultBoard()
{
    board = std::vector<std::vector<InternalBoardSquare>>(15, std::vector<InternalBoardSquare>(15));
    // Default robot positions
    redRobotRow = 0;
    redRobotCol = 0;
    blueRobotRow = 14;
    blueRobotCol = 14;
}

// Initialize the board based on configuration
void GameBoard::initializeBoardFromConfig(const Config &config)
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

// Move robot on the board
bool GameBoard::MoveRobot(RobotMoveRequest &mr)
{
    int &robotRow = (mr.robot == RobotColor::RED) ? redRobotRow : blueRobotRow;
    int &robotCol = (mr.robot == RobotColor::RED) ? redRobotCol : blueRobotCol;

    moveRobot(mr, robotRow, robotCol);

    // Update the square the robot moves off of
    board[robotRow][robotCol].setSquareColor((mr.robot == RobotColor::RED) ? Color::RED : Color::BLUE);
    notifyRobotMove(mr);
    return true; // Always returns true for now
}

// Check if paint blob hits
bool GameBoard::PaintBlobHit(RobotMoveRequest &mr)
{
    // Example implementation, assuming straight-line shooting
    int targetRow = (mr.robot == RobotColor::RED) ? blueRobotRow : redRobotRow;
    int targetCol = (mr.robot == RobotColor::RED) ? blueRobotCol : redRobotCol;

    // Check if any obstacles block the shot
    return !(board[targetRow][targetCol].getSquareType() == SquareType::ROCK);
}

// Score calculation
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

void GameBoard::setSquareColor(int row, int col, Color c)
{
    if (row >= 0 && row < 15 && col >= 0 && col < 15)
    {
        board[row][col].setSquareColor(c);
        notifySquareChange(row, col);
    }
}

void GameBoard::setRobotPaintColor(RobotColor robot, Color c)
{
    if (robot == RobotColor::RED)
    {
        board[redRobotRow][redRobotCol].setSquareColor(c);
    }
    else
    {
        board[blueRobotRow][blueRobotCol].setSquareColor(c);
    }
    notifyScoreChange();
}

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

// Notify observers of square change
void GameBoard::notifySquareChange(int row, int col)
{
    notifyObservers(new std::string("Square changed at (" + std::to_string(row) + ", " + std::to_string(col) + ")"));
}

// Notify observers of robot movement
void GameBoard::notifyRobotMove(RobotMoveRequest &mr)
{
    notifyObservers(new std::string("Robot moved: " + std::string((mr.robot == RobotColor::RED) ? "Red" : "Blue")));
}

// Notify observers of score change
void GameBoard::notifyScoreChange()
{
    notifyObservers(new std::string("Score updated. Red: " + std::to_string(redScore()) + ", Blue: " + std::to_string(blueScore())));
}

// Helper to move robot
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