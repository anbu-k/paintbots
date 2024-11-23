# coms3270P2 - Paintbots

This project is a C++ simulation for paintbots

To compile:
1. make
2. 6 executables should be created after make

All my executables: ./ConfigTest, ./BoardSquareTest, ./InternalBoardSquareTest, ./ExternalBoardSquareTest, ./GameBoardTest, ./PlainDisplayTest

To run tests:  
1. Type in Executables after make for example "./ConfigTest", or "./GameBoardTest", 
2. For the display functionality, use "./PlainDisplayTest"


To clean:
1. make clean

# file structure

- BoardSquare.h: Defines enumerations for Direction, SquareType, and Color, which are shared across board components.
- Config.cpp / Config.h: Implements the Config class, which reads and manages game configurations from a file or default settings.
- ConfigTest.cpp: Tests for the Config class to make sure there is correct parsing.
- InternalBoardSquare.cpp / InternalBoardSquare.h: Manages each board square's internal state, including type, color, and robot presence.
- ExternalBoardSquare.cpp / ExternalBoardSquare.h: Provides a read only view of InternalBoardSquare data, which is used by robot agents to access square properties safely.
- BoardSquareTest.cpp: Unit tests for verifying BoardSquare behaviors, including type, color, and enumeration usage.
- InternalBoardSquareTest.cpp: Tests to validate InternalBoardSquare functionality, including robot presence and state changes.
- ExternalBoardSquareTest.cpp: Tests to ensure read-only access of ExternalBoardSquare.
- GameBoard.cpp / GameBoard.h: Implements the GameBoard singleton class:
  - Manages the board as a collection of InternalBoardSquare objects.
  - Handles robot movements and square updates.
  - Notifies observers of changes via the Observer Pattern.
  - Implements scoring logic.
- GameBoardTest.cpp: Tests for the GameBoard class, including singleton behavior, robot movements, scoring, and observer notifications.
- PlainDisplay.cpp / PlainDisplay.h: Implements the PlainDisplay class:
  - Observes GameBoard changes.
  - Displays an ASCII representation of the game board, including square properties, robots, and obstacles.
- PlainDisplayTest.cpp: Tests and shows PlainDisplay functionality by simulating GameBoard changes and verifying the output
- ObserverPattern.cpp / ObserverPattern.h**: Implements a generic Observer Pattern:
  - Observer<T>: Interface for observer classes.
  - Observable<T>: Base class for subjects that notify observers of state changes.
- ITest.h: Defines the ITest interface, with a doTests() method for all test classes.

I test my code with MSYS2 MINGW64