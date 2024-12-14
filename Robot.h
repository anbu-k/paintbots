// @author Anbu Krishnan - anbu@iastate.edu
#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class IRobotAgent;

class Robot
{
public:
    // default constructor
    Robot();

    // robot colors
    enum class RobotColor
    {
        RED,
        BLUE
    };

    // robot movements
    enum class RobotMove
    {
        ROTATELEFT,
        ROTATERIGHT,
        FORWARD,
        NONE
    };

    // robot move request
    struct RobotMoveRequest
    {
        RobotColor robot;
        RobotMove move;
        bool shoot;

        RobotMoveRequest(RobotColor robot = RobotColor::RED, RobotMove move = RobotMove::NONE, bool shoot = false)
            : robot(robot), move(move), shoot(shoot) {}
    };

    // initializes a robot with default settings
    Robot(RobotColor color = RobotColor::RED);

    // sets and gets the robots behavior strategy
    void setRobotAgent(IRobotAgent *agent);
    IRobotAgent *getRobotAgent() const;

    // sets and gets the robots color
    void setColor(RobotColor color);
    RobotColor getRobotColor() const;

    // manages robots position on the board
    int getRow() const;
    int getCol() const;
    void setPosition(int row, int col);

private:
    RobotColor color;
    IRobotAgent *robotAgent;
    int row, col;
};

#endif
