# coms3270P2 - Paintbots

This project is a C++ simulation for paintbots

To compile:
1. make
2. ./testconfig

To clean:
1. make clean

# file structure

- BoardSquare.h: Defines enumerations for Direction, SquareType, and Color, which are shared across board components.
- Config.cpp / Config.h: Implements the Config class, which reads and manages game configurations from a file or default settings.
- ConfigTest.cpp: Tests for the Config class to make sure there is correct parsing.
- InternalBoardSquare.cpp / InternalBoardSquare.h: Manages each board square's internal state, including type, color, and robot presence.
- ExternalBoardSquare.cpp / ExternalBoardSquare.h: Provides a read only view of InternalBoardSquare data, which is used by robot agents to access square properties safely.


I test my code with MSYS2 MINGW64