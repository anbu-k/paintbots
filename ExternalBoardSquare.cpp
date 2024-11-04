// @author Anbu Krishnan - anbu@iastate.edu
#include "ExternalBoardSquare.h"

// Constructor: Copies values from the given InternalBoardSquare
ExternalBoardSquare::ExternalBoardSquare(const InternalBoardSquare& internalSquare) {
    squareColor = internalSquare.getSquareColor();
    redRobotPresentFlag = internalSquare.isRedRobotPresent();
    blueRobotPresentFlag = internalSquare.isBlueRobotPresent();
    robotDirectionValue = internalSquare.getRobotDirection();
    squareType = internalSquare.getSquareType();
}

// Methods to access data
Color ExternalBoardSquare::getSquareColor() const {
    return squareColor;
}

bool ExternalBoardSquare::redRobotPresent() const {
    return redRobotPresentFlag;
}

bool ExternalBoardSquare::blueRobotPresent() const {
    return blueRobotPresentFlag;
}

Direction ExternalBoardSquare::robotDirection() const {
    return robotDirectionValue;
}

SquareType ExternalBoardSquare::getSquareType() const {
    return squareType;
}
