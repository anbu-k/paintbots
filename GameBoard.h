// @author Anbu Krishnan - anbu@iastate.edu
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "InternalBoardSquare.h"
#include "ExternalBoardSquare.h"
#include "Config.h"
#include "ObserverPattern.h"
#include "Robot.h" // for RobotColor and RobotMoveRequest
#include <vector>
#include <string>

class GameBoard : public Observable<std::string>
{
public:
    // Static methods for Singleton pattern
    static GameBoard *getInstance(const std::string &password);
    static GameBoard *getInstance(const std::string &password, const Config &config);

    // Deleted methods to prevent copying for singleton
    GameBoard(const GameBoard &) = delete;
    GameBoard &operator=(const GameBoard &) = delete;

    // Methods for game interaction
    InternalBoardSquare &getSquare(int row, int col);
    ExternalBoardSquare **getSurroundings(Robot::RobotColor color) const;
    bool MoveRobot(Robot::RobotMoveRequest &mr);
    bool PaintBlobHit(Robot::RobotMoveRequest &mr);
    bool isGameOver() const;
    bool isValidMove(Robot::RobotColor color, const Robot::RobotMoveRequest &move) const;
    int blueScore() const;
    int redScore() const;
    void setSquareColor(int row, int col, Color c);
    void setRobotPaintColor(Robot::RobotColor robot, Color c);
    void applyMove(Robot::RobotColor color, Robot::RobotMoveRequest &move);
    ExternalBoardSquare **getLongRangeScan();
    ExternalBoardSquare **getShortRangeScan(Robot::RobotColor rc);

    // Observer notification methods
    void notifySquareChange(int row, int col);
    void notifyRobotMove(Robot::RobotMoveRequest &mr);
    void notifyScoreChange();

    // returns winner
    std::string getWinner() const;

private:
    // Private constructors
    GameBoard();                     // Default constructor
    GameBoard(const Config &config); // Constructor with configuration

    // Private methods for initialization
    void initializeDefaultBoard();
    void initializeConfigBoard(const Config &config);

    // Singleton instance
    static GameBoard *uniqueInstance;

    std::vector<std::vector<InternalBoardSquare>> board;

    Robot redRobot;
    Robot blueRobot;

    // Helper
    void moveRobot(Robot::RobotMoveRequest &mr, Robot &robot);
};

#endif
