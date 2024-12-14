// @author Anbu Krishnan
#include "RandomRobot.h"
#include <cstdlib>

RandomRobot::RandomRobot() = default;  // Default constructor
RandomRobot::~RandomRobot() = default; // Default destructor

// random robot name
std::string RandomRobot::getRobotName()
{
    return "RandomRobot";
}

// robot creator
std::string RandomRobot::getRobotCreator()
{
    return "Anbu Krishnan";
}

// gets move
Robot::RobotMoveRequest *RandomRobot::getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs)
{
    Robot::RobotMoveRequest *request = new Robot::RobotMoveRequest();
    request->robot = color;
    request->move = static_cast<Robot::RobotMove>(std::rand() % 4);
    request->shoot = false;
    return request;
}

// sets color
void RandomRobot::setRobotColor(Robot::RobotColor c)
{
    color = c;
}
