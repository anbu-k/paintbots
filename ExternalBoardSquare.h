// @author Anbu Krishnan - anbu@iastate.edu
#ifndef EXTERNALBOARDSQUARE_H
#define EXTERNALBOARDSQUARE_H

#include "BoardSquare.h"
#include "InternalBoardSquare.h"

class ExternalBoardSquare {
public:
    // Constructor: Takes an InternalBoardSquare and copies values
    ExternalBoardSquare(const InternalBoardSquare& internalSquare);

    // Methods to access data, without modifying the original square
    Color getSquareColor() const;
    bool redRobotPresent() const;
    bool blueRobotPresent() const;
    Direction robotDirection() const;
    SquareType getSquareType() const;

private:
    // Member variables copied from InternalBoardSquare
    Color squareColor;
    bool redRobotPresentFlag;
    bool blueRobotPresentFlag;
    Direction robotDirectionValue;
    SquareType squareType;
};

#endif // EXTERNALBOARDSQUARE_H
