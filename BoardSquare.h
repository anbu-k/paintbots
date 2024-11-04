// @author Anbu Krishnan - anbu@iastate.edu
#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

// Enumeration for directions
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// Enumeration for square types
enum class SquareType {
    EMPTY,
    ROCK,
    FOG,
    WALL
};

// Enumeration for colors
enum class Color {
    RED,
    BLUE,
    WHITE
};

#endif // BOARDSQUARE_H
