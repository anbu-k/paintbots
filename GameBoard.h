// @author Anbu Krishnan - anbu@iastate.edu
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "InternalBoardSquare.h"
#include "ExternalBoardSquare.h"
#include "Config.h"
#include "ObserverPattern.h"
#include <vector>
#include <string>

// Enumeration for robot colors and moves
enum class RobotColor { RED, BLUE };
enum class RobotMove { ROTATELEFT, ROTATERIGHT, FORWARD, NONE };

// Struct for RobotMoveRequest
struct RobotMoveRequest {
    RobotColor robot;
    RobotMove move;
    bool shoot;
};

class GameBoard : public Observable<std::string> { // Subclass Observable
public:
    // Static methods for Singleton pattern
    static GameBoard* getInstance(const std::string& password);
    static GameBoard* getInstance(const std::string& password, const Config& config);

    // Deleted methods to prevent copying
    GameBoard(const GameBoard&) = delete;
    GameBoard& operator=(const GameBoard&) = delete;

    // Methods for game interaction
    InternalBoardSquare& getSquare(int row, int col);
    bool MoveRobot(RobotMoveRequest& mr);
    bool PaintBlobHit(RobotMoveRequest& mr);
    int blueScore() const;
    int redScore() const;
    void setSquareColor(int row, int col, Color c);
    void setRobotPaintColor(RobotColor robot, Color c);
    ExternalBoardSquare** getLongRangeScan();
    ExternalBoardSquare** getShortRangeScan(RobotColor rc);

    // Getter methods for robot positions
    int getRedRobotRow() const { return redRobotRow; }
    int getRedRobotCol() const { return redRobotCol; }
    int getBlueRobotRow() const { return blueRobotRow; }
    int getBlueRobotCol() const { return blueRobotCol; }

    // Observer notification methods
    void notifySquareChange(int row, int col);
    void notifyRobotMove(RobotMoveRequest& mr);
    void notifyScoreChange();

private:
    // Private constructor(s)
    GameBoard(); // Default constructor
    GameBoard(const Config& config); // Constructor with configuration

    // Private methods for initialization
    void initializeDefaultBoard();
    void initializeBoardFromConfig(const Config& config);

    // Singleton instance
    static GameBoard* uniqueInstance;

    std::vector<std::vector<InternalBoardSquare>> board;

    // Robot positions
    int redRobotRow;
    int redRobotCol;
    int blueRobotRow;
    int blueRobotCol;

    // Helper method for robot movement
    void moveRobot(RobotMoveRequest& mr, int& robotRow, int& robotCol);
};

#endif // GAMEBOARD_H
