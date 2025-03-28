// @author Anbu Krishnan - anbu@iastate.edu
#ifndef EXTERNALBOARDSQUARE_H
#define EXTERNALBOARDSQUARE_H

#include "BoardSquare.h"
#include "InternalBoardSquare.h"

class ExternalBoardSquare : public BoardSquare
{
public:
    ExternalBoardSquare()
        : BoardSquare(Color::WHITE, SquareType::EMPTY, false, false, Direction::NORTH) {}

    // Constructor: Copies values from an InternalBoardSquare
    ExternalBoardSquare(const InternalBoardSquare &internalSquare)
        : BoardSquare(
              internalSquare.getSquareColor(),
              internalSquare.getSquareType(),
              internalSquare.redRobotPresent(),
              internalSquare.blueRobotPresent(),
              internalSquare.robotDirection()) {}
};

#endif