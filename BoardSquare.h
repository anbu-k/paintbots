// @author Anbu Krishnan - anbu@iastate.edu
#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

// Directions for robots
enum class Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// Types of squares on the board
enum class SquareType
{
    EMPTY,
    ROCK,
    FOG,
    WALL
};

// Colors associated with the square
enum class Color
{
    RED,
    BLUE,
    WHITE
};

class BoardSquare
{
private:
    Color squareColor;             // Color of the square
    SquareType squareType;         // Type of the square
    bool redRobotPresentFlag;      // Whether a red robot is on the square
    bool blueRobotPresentFlag;     // Whether a blue robot is on the square
    Direction robotDirectionValue; // Direction a robot is facing 

public:
    // Default Constructor
    BoardSquare()
        : squareColor(Color::WHITE),
          squareType(SquareType::EMPTY),
          redRobotPresentFlag(false),
          blueRobotPresentFlag(false),
          robotDirectionValue(Direction::NORTH) {}

    // Specific Constructor
    BoardSquare(Color color, SquareType type, bool redPresent, bool bluePresent, Direction direction)
        : squareColor(color),
          squareType(type),
          redRobotPresentFlag(redPresent),
          blueRobotPresentFlag(bluePresent),
          robotDirectionValue(direction) {}

    // Copy Constructor
    BoardSquare(const BoardSquare &other)
        : squareColor(other.squareColor),
          squareType(other.squareType),
          redRobotPresentFlag(other.redRobotPresentFlag),
          blueRobotPresentFlag(other.blueRobotPresentFlag),
          robotDirectionValue(other.robotDirectionValue) {}

    // Assignment Operator
    BoardSquare &operator=(const BoardSquare &other)
    {
        if (this != &other)
        {
            squareColor = other.squareColor;
            squareType = other.squareType;
            redRobotPresentFlag = other.redRobotPresentFlag;
            blueRobotPresentFlag = other.blueRobotPresentFlag;
            robotDirectionValue = other.robotDirectionValue;
        }
        return *this;
    }

    // Destructor
    virtual ~BoardSquare() {}

    // Inline Getter Methods
    inline Color getSquareColor() const { return squareColor; }
    inline SquareType getSquareType() const { return squareType; }
    inline bool redRobotPresent() const { return redRobotPresentFlag; }
    inline bool blueRobotPresent() const { return blueRobotPresentFlag; }
    inline Direction robotDirection() const { return robotDirectionValue; }

    // Inline Setter Methods
    inline void setSquareColor(Color color) { squareColor = color; }
    inline void setSquareType(SquareType type) { squareType = type; }
    inline void setRedRobotPresent(bool redPresent) { redRobotPresentFlag = redPresent; }
    inline void setBlueRobotPresent(bool bluePresent) { blueRobotPresentFlag = bluePresent; }
    inline void setRobotDirection(Direction direction) { robotDirectionValue = direction; }
};

#endif 