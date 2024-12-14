// @author Anbu Krishnan - anbu@iastate.edu
#ifndef ROBOTAGENTROSTER_H
#define ROBOTAGENTROSTER_H

#include <vector>
#include <string>
#include <algorithm>
#include "IRobotAgent.h"
#include "LazyRobot.h"
#include "RandomRobot.h"
#include "AntiRandom.h"

// manages robot agents
class RobotAgentRoster
{
private:
    static RobotAgentRoster *instance; // singleton instance of RobotAgentRoster
    std::vector<IRobotAgent *> agents; // list of pointers to IRobotAgent objects

    RobotAgentRoster() = default; // priv constructor for the singleton pattern

public:
    static RobotAgentRoster *getInstance(); // returns the singleton instance of the RobotAgentRoster

    void add(IRobotAgent *agent); // adds a robot agent to the roster

    void initialize(); // initializes the roster with default robot agents

    IRobotAgent *operator[](size_t index) const; // overload operator to access a robot agent by index

    IRobotAgent *operator[](const std::string &name) const; // overload operator to access a robot agent by name
};

#endif
