// @author Anbu Krishnan - anbu@iastate.edu
#include "AntiRandom.h"
#include "ExternalBoardSquare.h"

// default constructor
AntiRandom::AntiRandom() = default;
// defualt destructor
AntiRandom::~AntiRandom() = default;

// returns robot name
std::string AntiRandom::getRobotName()
{
    return "BeatRandom";
}

// returns creator name
std::string AntiRandom::getRobotCreator()
{
    return "Anbu Krishnan";
}

// determines the robots next move based on the surroundings
Robot::RobotMoveRequest *AntiRandom::getMove(ExternalBoardSquare **srs, ExternalBoardSquare **lrs)
{
    auto *request = new Robot::RobotMoveRequest();
    request->robot = color;

    // iterates through the short range scan
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            ExternalBoardSquare *square = srs[row * 5 + col];
            if (!square)
                continue;

            // checks for square that are not rocks and are painted the other color
            if (square->getSquareType() != SquareType::ROCK &&
                ((color == Robot::RobotColor::RED && square->getSquareColor() == Color::BLUE) ||
                 (color == Robot::RobotColor::BLUE && square->getSquareColor() == Color::RED)))
            {
                request->move = Robot::RobotMove::FORWARD;
                request->shoot = true;
                return request;
            }
        }
    }

    // default move if no target
    request->move = Robot::RobotMove::FORWARD;
    request->shoot = false;
    return request;
}

// sets robot color
void AntiRandom::setRobotColor(Robot::RobotColor c)
{
    color = c;
}
