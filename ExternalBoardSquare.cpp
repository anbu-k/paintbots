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

// Methods for data access

 /** 
   * Returns the color of the square.  Possible values for  
   * game squares are Color.RED, Color.BLUE, or Color.WHITE 
   * @return color of this square 
   */ 
Color ExternalBoardSquare::getSquareColor() const {
    return squareColor;
}


 /** 
   * Determines whether the red robot is present on this square. 
   * @return true if the red robot is present, false otherwise. 
   */ 
bool ExternalBoardSquare::redRobotPresent() const {
    return redRobotPresentFlag;
}

 /** 
   * Determines whether the blue robot is present on this square. 
   * @return true if the blue robot is present, false otherwise. 
   */ 
bool ExternalBoardSquare::blueRobotPresent() const {
    return blueRobotPresentFlag;
}

 /** 
   * Returns the direction that a robot in this square is facing. 
   * This value is meaningless if there is no robot in the square. 
   * North is up, East is right, South is down, and West is left. 
   * @return direction that a robot in the square is facing 
   */ 
Direction ExternalBoardSquare::robotDirection() const {
    return robotDirectionValue;
}

/** 
   * Returns the type of this square. 
   * @return the type of this square 
   */ 
SquareType ExternalBoardSquare::getSquareType() const {
    return squareType;
}
