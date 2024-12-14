// @author Anbu Krishnan - anbu@iastate.edu
#ifndef IROBOTAGENT_H
#define IROBOTAGENT_H

#include "Robot.h"
#include "ExternalBoardSquare.h"

class IRobotAgent
{
public:
    virtual ~IRobotAgent() = default;

    // virtual functions
    virtual std::string getRobotName() = 0;
    virtual std::string getRobotCreator() = 0;
    virtual Robot::RobotMoveRequest *getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs) = 0;
    virtual void setRobotColor(Robot::RobotColor c) = 0; // Sets the robot's color
};

#endif
