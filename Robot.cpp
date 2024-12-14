// @author Anbu Krishnan - anbu@iastate.edu
#include "Robot.h"
#include <stdexcept>
#include "RobotAgentRoster.h"

// Initializes a red robot with the lazy strat
Robot::Robot(RobotColor color) : color(color), row(0), col(0)
{
    RobotAgentRoster *roster = RobotAgentRoster::getInstance();
    robotAgent = roster->operator[]("LazyRobot");

    if (!robotAgent)
    {
        throw std::runtime_error("LazyRobot strategy not found in the roster.");
    }

    robotAgent->setRobotColor(color);
}

// Set the robots behavior strategy
void Robot::setRobotAgent(IRobotAgent *agent)
{
    robotAgent = agent;

    if (robotAgent)
    {
        robotAgent->setRobotColor(color);
    }
}

// Gets the current behavior strategy
IRobotAgent *Robot::getRobotAgent() const
{
    return robotAgent;
}

// Sets the robots color
void Robot::setColor(RobotColor newColor)
{
    color = newColor;

    if (robotAgent)
    {
        robotAgent->setRobotColor(color);
    }
}

// Gets the robots color
Robot::RobotColor Robot::getRobotColor() const
{
    return color;
}

// Gets the robots current row position
int Robot::getRow() const
{
    return row;
}

// Gets the robots current column position
int Robot::getCol() const
{
    return col;
}

// Sets the robots position on the board
void Robot::setPosition(int newRow, int newCol)
{
    if (newRow < 0 || newRow >= 15 || newCol < 0 || newCol >= 15)
    {
        throw std::out_of_range("Position out of bounds");
    }
    row = newRow;
    col = newCol;
}
