// @author Anbu Krishnan - anbu@iastate.edu
#ifndef ANTI_RANDOM_H
#define ANTI_RANDOM_H

#include "IRobotAgent.h"
#include "Robot.h"
#include <string>

// strategy for the robot that beats RandomRobot
class AntiRandom : public IRobotAgent
{
private:
    Robot::RobotColor color;

public:
    AntiRandom();                                                                                    // constructor
    ~AntiRandom();                                                                                   // destructor
    std::string getRobotName() override;                                                             // returns BeatRandom
    std::string getRobotCreator() override;                                                          // returns creator name
    Robot::RobotMoveRequest *getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs) override; // next move based on srs and lrs
    void setRobotColor(Robot::RobotColor c) override;                                                // sets red or blue
};

#endif
