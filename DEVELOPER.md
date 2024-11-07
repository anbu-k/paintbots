# Developer Guide - Paintbots part a 

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

# Testing

ConfigTest.cpp:
ConfigTest.cpp validates the Config class through  test cases:
1. Default Constructor: Confirms that default values are set correctly.
2. Valid Config File: Makes sure that configuration values from a valid file override defaults.
3. Missing Parameters: Tests that missing values default correctly without errors.
4. Invalid Config File: Makes sure there's error handling for incorrect file formats.
5. Non-Existent File: Makes sure that missing files create exceptions.
6. more extraneous tests

I have a configfiletests folder that contains txt files that I used for testing correctness

Use Makefile for compilation, includes make clean

Everything runs correctly and follows the project specification
