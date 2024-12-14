// @author Anbu Krishnan - anbu@iastate.edu
#include "LazyRobot.h"

LazyRobot::LazyRobot() = default;
LazyRobot::~LazyRobot() = default;

// robot name
std::string LazyRobot::getRobotName()
{
    return "LazyRobot";
}
// creator
std::string LazyRobot::getRobotCreator()
{
    return "Anbu Krishnan";
}

// gets move
Robot::RobotMoveRequest *LazyRobot::getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs)
{
    auto *request = new Robot::RobotMoveRequest();
    request->robot = color;
    request->move = Robot::RobotMove::NONE;
    request->shoot = true;
    return request;
}

// sets color
void LazyRobot::setRobotColor(Robot::RobotColor c)
{
    color = c;
}
