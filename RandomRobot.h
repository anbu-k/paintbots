// @author Anbu Krishnan
#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "IRobotAgent.h"
#include "Robot.h"
#include "ExternalBoardSquare.h"
#include <string>

// strategy for RandomRobot
class RandomRobot : public IRobotAgent
{
private:
    Robot::RobotColor color; // color assigned to the robot

public:
    RandomRobot();  // default constructor
    ~RandomRobot(); // destructor

    std::string getRobotName() override;                                                             // returns RandomRobot
    std::string getRobotCreator() override;                                                          // returns creator name
    Robot::RobotMoveRequest *getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs) override; // next move based on srs and lrs
    void setRobotColor(Robot::RobotColor c) override;                                                // sets color
};

#endif
