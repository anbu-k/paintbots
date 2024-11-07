// @author Anbu Krishnan - anbu@iastate.edu
#include "InternalBoardSquare.h"

// Constructor
InternalBoardSquare::InternalBoardSquare(SquareType type, Color color)
    : squareType(type), squareColor(color), redRobotPresent(false), blueRobotPresent(false), robotDirection(Direction::NORTH) {}

// Getters
SquareType InternalBoardSquare::getSquareType() const {
    return squareType;
}

Color InternalBoardSquare::getSquareColor() const {
    return squareColor;
}

bool InternalBoardSquare::isRedRobotPresent() const {
    return redRobotPresent;
}

bool InternalBoardSquare::isBlueRobotPresent() const {
    return blueRobotPresent;
}

Direction InternalBoardSquare::getRobotDirection() const {
    return robotDirection;
}

// Setters
void InternalBoardSquare::setSquareType(SquareType type) {
    squareType = type;
}

void InternalBoardSquare::setSquareColor(Color color) {
    squareColor = color;
}

void InternalBoardSquare::setRedRobotPresent(bool isPresent) {
    redRobotPresent = isPresent;
}

void InternalBoardSquare::setBlueRobotPresent(bool isPresent) {
    blueRobotPresent = isPresent;
}

void InternalBoardSquare::setRobotDirection(Direction direction) {
    robotDirection = direction;
}
