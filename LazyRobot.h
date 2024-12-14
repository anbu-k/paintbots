// @author Anbu Krishnan - anbu@iastate.edu
#ifndef LAZYROBOT_H
#define LAZYROBOT_H

#include "IRobotAgent.h"
#include "Robot.h"
#include "ExternalBoardSquare.h"
#include <string>

// strategy for LazyRobot
class LazyRobot : public IRobotAgent
{
private:
    Robot::RobotColor color; // robots color

public:
    LazyRobot();                                                                                     // default construtor
    ~LazyRobot();                                                                                    // destructor
    std::string getRobotName() override;                                                             // returns LazyRobot
    std::string getRobotCreator() override;                                                          // return creator name
    Robot::RobotMoveRequest *getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs) override; // next move based on srs and lrs
    void setRobotColor(Robot::RobotColor c) override;                                                // sets color
};

#endif
