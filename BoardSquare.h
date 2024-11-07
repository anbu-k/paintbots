// @author Anbu Krishnan - anbu@iastate.edu
#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

// directions
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// square types
enum class SquareType {
    EMPTY,
    ROCK,
    FOG,
    WALL
};

// colors
enum class Color {
    RED,
    BLUE,
    WHITE
};

#endif // BOARDSQUARE_H
