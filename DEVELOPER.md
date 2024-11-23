# Developer Guide - Paintbots 

# Class Structure

1. BoardSquare.h
Defines shared enumerations:
- Direction : Represents possible movement directions (NORTH, SOUTH, EAST, WEST).
- SquareType : Represents types of squares (EMPTY, ROCK, FOG, WALL).
- Color : Represents square colors (RED, BLUE, WHITE).

2. config.cpp / config.h
The Config class reads game settings from a configuration file and provides defaults when parameters are missing. methods:
- Constructors:
  - Config(): Initializes with default values.
  - Config(const std::string& filePath): Parses the configuration file.
- parseConfigFile(): Helper method that reads and parses configuration files
- Getter Methods: Read only access to each configuration parameter

3. InternalBoardSquare.cpp / InternalBoardSquare.h
Manages the internal state of each board square, including:
- Attributes:
  - squareType, squareColor: Type and color of the square.
  - redRobotPresent, blueRobotPresent: Flags indicating robot presence.
  - robotDirection: The direction a robot is facing if present.
- Methods:
  - Getters and setters for each attribute, allowing external control over the board state.
- Constructor: Initializes square type and color with default values.

 4. ExternalBoardSquare.cpp / ExternalBoardSquare.h
Provides controlled access to square properties without allowing modification, which is intended for robot agents.
- Constructor: Copies values from InternalBoardSquare by value to prevent modifications.
- Methods: Provides read only access to squareColor, robot presence, robotDirection, and squareType.

Part B Major Additions

5. ObserverPattern.h / ObserverPattern.cpp
Implements the Observer pattern to handle game state updates.
- Template: Observer<T>: Interface for objects that need to receive updates.
  - virtual function update(T* observableData).
- Template: Observable<T>: Manages a list of observers and notifies them of changes.
- Methods: 
  - registerObserver(), removeObserver(), notifyObservers().

6. GameBoard.cpp / GameBoard.h
Implements game logic and integrates with the Observable interface.

- Methods:
  - MoveRobot(): Executes a robot move based on a RobotMoveRequest.
  - PaintBlobHit(): Determines whether a robot would hit its target if it fired.
  - notifySquareChange(), notifyRobotMove(), notifyScoreChange(): Notifies observers when the game state changes.
- Implements the Singleton pattern to make sure there's only one instance of GameBoard.

7. PlainDisplay.h / PlainDisplay.cpp
Implements an ASCII display for the game board and observes GameBoard for updates.
- Features:
  - Displays the game board with symbols:
    - R/B: Red/Blue robots.
    - X: Rocks or fog.
    - Square colors: R, B, W (Red, Blue, White).
- Updates dynamically when GameBoard notifies observers of state changes.

Minor Changes
8. Introduced inheritance 
9. Changed RobotColor from RED and BLUE to XRED and XBLUE which will be changed back in part c

# Testing

All my executables: ./ConfigTest, ./BoardSquareTest, ./InternalBoardSquareTest, ./ExternalBoardSquareTest, ./GameBoardTest, ./PlainDisplayTest

New Exectuables from part B: ./BoardSquareTest, ./InternalBoardSquareTest, ./ExternalBoardSquareTest, ./GameBoardTest, ./PlainDisplayTest

Changed name of the config test executable from "testconfig" to "ConfigTest" like asked in the instructions

ConfigTest.cpp:
ConfigTest.cpp validates the Config class through  test cases:
1. Default Constructor: Confirms that default values are set correctly.
2. Valid Config File: Makes sure that configuration values from a valid file override defaults.
3. Missing Parameters: Tests that missing values default correctly without errors.
4. Invalid Config File: Makes sure there's error handling for incorrect file formats.
5. Non-Existent File: Makes sure that missing files create exceptions.
6. more extraneous tests

GameBoardTest.cpp
Tests GameBoard functionality:
- Singleton Pattern: Ensures only one instance of the GameBoard exists.
- MoveRobot: Tests correct robot movement and state updates.
- PaintBlobHit: Verifies that rocks block shots and correct targets are identified.

PlainDisplayTest.cpp
Tests the PlainDisplay class:
- Verifies that board changes trigger updates.
- Displays the board in ASCII
- Uses manual inspection of output to confirm correctness.

BoardSquareTest.cpp
- Tests the enums (Direction, SqyareType, Color) and how they interact with the other classes
  - validation of SquareType and Color default assignments
  - verification of Direction values

InternalBoardSquareTest.cpp
- validates the state management of individual board squares
  - type SquareType and color Color
  - robot presence redRobotPresent, blueRobotPresent and direction robotDirection
  - validates the correct square type and color initialization

ExternalBoardSquareTest.cpp
- Tests the read-only access provided by ExternalBoardSquare to internal square data
  - makes sure that the ExternalBoardSquare constructor correctly copies data from InternalBoardSquare


I have a configfiletests folder that contains txt files that I used for testing correctness for part a 

Use Makefile for compilation, includes make clean

Everything runs correctly and follows the project specification
