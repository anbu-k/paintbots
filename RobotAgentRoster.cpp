// @author Anbu Krishnan - anbu@iastate.edu
#include "RobotAgentRoster.h"
#include "LazyRobot.h"
#include "RandomRobot.h"
#include "AntiRandom.h"

// static instance of RobotAgentRoster initialized to nullptr
RobotAgentRoster *RobotAgentRoster::instance = nullptr;

// singleton method to get the single instance of RobotAgentRoster
RobotAgentRoster *RobotAgentRoster::getInstance()
{
    if (!instance)
    {
        instance = new RobotAgentRoster();
    }
    return instance;
}

// adds a robot to the roster
void RobotAgentRoster::add(IRobotAgent *agent)
{
    agents.push_back(agent);
}

// initializes the roster
void RobotAgentRoster::initialize()
{
    add(new LazyRobot());
    add(new RandomRobot());
    add(new AntiRandom());
}

// overload operator that accesses agents by index
IRobotAgent *RobotAgentRoster::operator[](size_t index) const
{
    return (index < agents.size()) ? agents[index] : nullptr;
}

// overload operator that accesses agents by their name
IRobotAgent *RobotAgentRoster::operator[](const std::string &name) const
{
    auto it = std::find_if(agents.begin(), agents.end(), [&name](IRobotAgent *agent)
                           { return agent->getRobotName() == name; });
    return (it != agents.end()) ? *it : nullptr;
}