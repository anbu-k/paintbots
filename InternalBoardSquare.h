// @author Anbu Krishnan - anbu@iastate.edu
#ifndef INTERNALBOARDSQUARE_H
#define INTERNALBOARDSQUARE_H

#include "BoardSquare.h"

class InternalBoardSquare : public BoardSquare
{
public:
    // Default Constructor
    InternalBoardSquare()
        : BoardSquare() {}

    // Specific Constructor
    InternalBoardSquare(SquareType type, Color color, bool redPresent = false, bool bluePresent = false, Direction direction = Direction::NORTH)
        : BoardSquare(color, type, redPresent, bluePresent, direction) {}
};

#endif // INTERNALBOARDSQUARE_H
