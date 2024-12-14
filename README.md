# coms3270P2 - Paintbots

This project is a C++ simulation for paintbots

To compile:
1. make
2. 7 executables should be created after make

All my executables: ./ConfigTest, ./BoardSquareTest, ./InternalBoardSquareTest, ./ExternalBoardSquareTest, ./GameBoardTest, ./PlainDisplayTest, ./paintbots

To run tests:  
1. Type in Executables after make for example "./ConfigTest", or "./GameBoardTest", 
2. For the display functionality, use "./PlainDisplayTest"

To clean:
1. make clean

RULES FOR PAINTBOTS EXECUTABLE:

You might need to convert config files into unix first:
1. dos2unix boardconfig.txt
2. dos2unix robotconfig.txt

1. make
2. ./paintbots boardconfig.txt robotconfig.txt

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
- IRobotAgent.h:  
  Defines the interface for robot strategies:
  - getRobotName(), getRobotCreator(): Identifies robots.
  - getMove(ExternalBoardSquare** srs, ExternalBoardSquare** lrs): Generates a robot's move.
  - setRobotColor(Robot::RobotColor c): Sets the robot's color.
- RobotAgentRoster.cpp / RobotAgentRoster.h**:  
  Manages a list of robot agents using the Singleton Pattern:
  - Adds robot agents by add (IRobotAgent*)
  - Provides access to agents by index or name through an overloaded operator[].
  -  initialize() method to register built-in agents like lazyRobot, randomRobot, and AntiRandom.
- Robot.cpp / Robot.h:  
  Implements robot behavior and integrates the Strategy Pattern:
  - setRobotAgent(IRobotAgent*) and getRobotAgent() to assign and retrieve strategies.
  - setColor(RobotColor) and getRobotColor() for managing robot color.
  - Handles robot-specific functionality, including paint blob mechanics and movement.

- GameLogic.cpp / GameLogic.h:  
  Manages the game simulation:
  - Reads configuration files and initializes the board and robots.
  - Simulates the game turn by turn, by the Paintbots rules.
  - Determines the winner and handles game-ending conditions.
  - Includes pause functionality.
- lazyRobot.cpp / randomRobot.cpp / AntiRandom.cpp:  
  Implements robot agent strategies:
  - lazyRobot: Stays in place, firing paint blobs randomly.
  - randomRobot: Moves to random valid squares without shooting.
  - AntiRandom: Optimized to defeat randomRobot with a success rate of 80%.


I test my code in pyrite and it compiles