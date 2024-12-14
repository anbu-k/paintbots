// @author Anbu Krishnan - anbu@iastate.edu
#include "GameBoard.h"
#include <stdexcept>
#include <cstdlib> // For rand()
#include <iostream>
#include "Robot.h"

// Static initialization
GameBoard *GameBoard::uniqueInstance = nullptr;

// Default constructor
GameBoard::GameBoard() : redRobot(Robot::RobotColor::RED), blueRobot(Robot::RobotColor::BLUE)
{
    initializeDefaultBoard();
}

// Constructor with Config object
GameBoard::GameBoard(const Config &config) : redRobot(Robot::RobotColor::RED), blueRobot(Robot::RobotColor::BLUE)
{
    initializeConfigBoard(config);
}

// Default initialization
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

// Configuration initialization
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

// accesses a square on the board
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
    std::cout << "Initialized 15x15 board." << std::endl;

    // Places Red Robot
    int redRow = rand() % 15;
    int redCol = rand() % 15;
    redRobot.setPosition(redRow, redCol);
    board[redRow][redCol].setRedRobotPresent(true);

    // Places Blue Robot
    int blueRow = rand() % 15;
    int blueCol = rand() % 15;
    blueRobot.setPosition(blueRow, blueCol);
    board[blueRow][blueCol].setBlueRobotPresent(true);
}

// initializes the config board
void GameBoard::initializeConfigBoard(const Config &config)
{
    initializeDefaultBoard();

    int rockCount = rand() % (config.getRockUpperBound() - config.getRockLowerBound() + 1) + config.getRockLowerBound();
    int fogCount = rand() % (config.getFogUpperBound() - config.getFogLowerBound() + 1) + config.getFogLowerBound();

    // places rocks
    for (int i = 0; i < rockCount; ++i)
    {
        int row = rand() % 15;
        int col = rand() % 15;
        if (board[row][col].getSquareType() == SquareType::EMPTY)
        {
            board[row][col].setSquareType(SquareType::ROCK);
            notifySquareChange(row, col);
        }
    }

    // places fog
    for (int i = 0; i < fogCount; ++i)
    {
        int row = rand() % 15;
        int col = rand() % 15;
        if (board[row][col].getSquareType() == SquareType::EMPTY)
        {
            board[row][col].setSquareType(SquareType::FOG);
            notifySquareChange(row, col);
        }
    }
}

// Performs the request move on the designated robot
bool GameBoard::MoveRobot(Robot::RobotMoveRequest &mr)
{
    Robot &robot = (mr.robot == Robot::RobotColor::RED) ? redRobot : blueRobot;

    // Moves the robot
    moveRobot(mr, robot);

    // Updates the square the robot is on
    board[robot.getRow()][robot.getCol()].setSquareColor((mr.robot == Robot::RobotColor::RED) ? Color::RED : Color::BLUE);

    // Notifies observers of the move
    notifyRobotMove(mr);
    return true; // Always returns true since a move can always be made
}

// Checks if paint blob hits
bool GameBoard::PaintBlobHit(Robot::RobotMoveRequest &mr)
{
    Robot &opponent = (mr.robot == Robot::RobotColor::RED) ? blueRobot : redRobot;

    // Returns true if the target square is not a ROCK
    return !(board[opponent.getRow()][opponent.getCol()].getSquareType() == SquareType::ROCK);
}

// Returns the number of blue squares on the board
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

// executes the robots decisions
void GameBoard::applyMove(Robot::RobotColor color, Robot::RobotMoveRequest &move)
{
    Robot &robot = (color == Robot::RobotColor::RED) ? redRobot : blueRobot;

    moveRobot(move, robot);

    if (move.shoot)
    {
        int row = robot.getRow();
        int col = robot.getCol();
        setSquareColor(row, col, color == Robot::RobotColor::RED ? Color::RED : Color::BLUE);
        notifySquareChange(row, col);
    }
}

// checks for robots surroundings
ExternalBoardSquare **GameBoard::getSurroundings(Robot::RobotColor color) const
{
    int robotRow = (color == Robot::RobotColor::RED) ? redRobot.getRow() : blueRobot.getRow();
    int robotCol = (color == Robot::RobotColor::RED) ? redRobot.getCol() : blueRobot.getCol();

    // 5x5 for surroundings
    ExternalBoardSquare **surroundings = new ExternalBoardSquare *[5];
    for (int i = 0; i < 5; ++i)
    {
        surroundings[i] = new ExternalBoardSquare[5];
        for (int j = 0; j < 5; ++j)
        {
            int row = robotRow - 1 + i;
            int col = robotCol - 1 + j;

            if (row >= 0 && static_cast<size_t>(row) < board.size() &&
                col >= 0 && static_cast<size_t>(col) < board[0].size())
            {
                surroundings[i][j] = ExternalBoardSquare(board[row][col]);
            }
            else
            {
                surroundings[i][j] = ExternalBoardSquare();
            }
        }
    }
    return surroundings;
}

// checks for valid move
bool GameBoard::isValidMove(Robot::RobotColor color, const Robot::RobotMoveRequest &move) const
{
    int row = (color == Robot::RobotColor::RED) ? redRobot.getRow() : blueRobot.getRow();
    int col = (color == Robot::RobotColor::RED) ? redRobot.getCol() : blueRobot.getCol();

    switch (move.move)
    {
    case Robot::RobotMove::FORWARD:
        if (row + 1 >= 0 && static_cast<size_t>(row + 1) < board.size() &&
            board[row + 1][col].getSquareType() != SquareType::ROCK)
        {
            return true;
        }
        break;
    case Robot::RobotMove::ROTATELEFT:
    case Robot::RobotMove::ROTATERIGHT:
    case Robot::RobotMove::NONE:
        return true; // Rotation or no move is always valid
    }
    return false;
}

// returns the winner
std::string GameBoard::getWinner() const
{
    int redScore = this->redScore();
    int blueScore = this->blueScore();

    if (redScore > blueScore)
    {
        return "Red Robot";
    }
    else if (blueScore > redScore)
    {
        return "Blue Robot";
    }
    else
    {
        return "It's a tie!";
    }
}

// Sets the specified robot to paint a specific color
void GameBoard::setRobotPaintColor(Robot::RobotColor robot, Color c)
{
    Robot &targetRobot = (robot == Robot::RobotColor::RED) ? redRobot : blueRobot;
    board[targetRobot.getRow()][targetRobot.getCol()].setSquareColor(c);
    notifyScoreChange();
}

// game over check
bool GameBoard::isGameOver() const
{
    // checks if either robot reaches a score of 100
    if (redScore() >= 100 || blueScore() >= 100)
    {
        return true;
    }

    return false;
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

// short range scan
ExternalBoardSquare **GameBoard::getShortRangeScan(Robot::RobotColor rc)
{
    int robotRow = (rc == Robot::RobotColor::RED) ? redRobot.getRow() : blueRobot.getRow();
    int robotCol = (rc == Robot::RobotColor::RED) ? redRobot.getCol() : blueRobot.getCol();

    ExternalBoardSquare **shortRange = new ExternalBoardSquare *[5]; // 5x5 grid
    for (int i = 0; i < 5; ++i)
    {
        shortRange[i] = new ExternalBoardSquare[5];
        for (int j = 0; j < 5; ++j)
        {
            int row = robotRow - 2 + i; // Centered at the robot's position
            int col = robotCol - 2 + j;

            if (row >= 0 && static_cast<size_t>(row) < board.size() &&
                col >= 0 && static_cast<size_t>(col) < board[0].size())
            {
                shortRange[i][j] = ExternalBoardSquare(board[row][col]);
            }
            else
            {
                shortRange[i][j] = ExternalBoardSquare(); // Default for out-of-bounds
            }
        }
    }
    return shortRange;
}

// long range scan 15x15
ExternalBoardSquare **GameBoard::getLongRangeScan()
{
    ExternalBoardSquare **longRangeScan = new ExternalBoardSquare *[15];
    for (int i = 0; i < 15; ++i)
    {
        longRangeScan[i] = new ExternalBoardSquare[15];
        for (int j = 0; j < 15; ++j)
        {
            longRangeScan[i][j] = ExternalBoardSquare(board[i][j]); // Convert Internal to External
        }
    }
    return longRangeScan;
}

// Notifies observers of a square change
void GameBoard::notifySquareChange(int row, int col)
{
    notifyObservers(new std::string("Square changed at (" + std::to_string(row) + ", " + std::to_string(col) + ")"));
}

// Notifies observers of any robot movement
void GameBoard::notifyRobotMove(Robot::RobotMoveRequest &mr)
{
    notifyObservers(new std::string("Robot moved: " + std::string((mr.robot == Robot::RobotColor::RED) ? "Red" : "Blue")));
}

// Notifies observers of a score change
void GameBoard::notifyScoreChange()
{
    notifyObservers(new std::string("Score updated. Red: " + std::to_string(redScore()) + ", Blue: " + std::to_string(blueScore())));
}

// Helper to move robot based on the RobotMove direction
void GameBoard::moveRobot(Robot::RobotMoveRequest &mr, Robot &robot)
{
    switch (mr.move)
    {
    case Robot::RobotMove::FORWARD:
        robot.setPosition(std::max(0, std::min(14, robot.getRow() + 1)), robot.getCol());
        break;
    case Robot::RobotMove::ROTATELEFT:
    case Robot::RobotMove::ROTATERIGHT:
    case Robot::RobotMove::NONE:
        break;
    }
}
