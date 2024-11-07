// @author Anbu Krishnan - anbu@iastate.edu
#ifndef INTERNALBOARDSQUARE_H
#define INTERNALBOARDSQUARE_H

#include "BoardSquare.h"  // header

class InternalBoardSquare {
public:
    // Constructor
    InternalBoardSquare(SquareType type = SquareType::EMPTY, Color color = Color::WHITE);

    // Getters
    SquareType getSquareType() const;
    Color getSquareColor() const;
    bool isRedRobotPresent() const;
    bool isBlueRobotPresent() const;
    Direction getRobotDirection() const;

    // Setters
    void setSquareType(SquareType type);
    void setSquareColor(Color color);
    void setRedRobotPresent(bool isPresent);
    void setBlueRobotPresent(bool isPresent);
    void setRobotDirection(Direction direction);

private:
    SquareType squareType;     // Type of the square EMPTY, ROCK, FOG, WALL
    Color squareColor;         // Color of the square RED, BLUE, WHITE
    bool redRobotPresent;      // Whether the red robot is present on this square
    bool blueRobotPresent;     // Whether the blue robot is present on this square
    Direction robotDirection;  // Direction the robot in this square is facing
};

#endif 
