// @author Anbu Krishnan - anbu@iastate.edu
#include "BoardSquare.h"
#include <iostream>

int main()
{
    BoardSquare square;
    bool pass = true;

    pass &= (square.getSquareColor() == Color::WHITE);
    pass &= (square.getSquareType() == SquareType::EMPTY);
    pass &= (!square.redRobotPresent());
    pass &= (!square.blueRobotPresent());
    pass &= (square.robotDirection() == Direction::NORTH);

    std::cout << "BoardSquareTest: " << (pass ? "PASS" : "FAIL") << std::endl;
    return pass ? 0 : 1;
}
