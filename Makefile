all: ConfigTest BoardSquareTest InternalBoardSquareTest ExternalBoardSquareTest GameBoardTest PlainDisplayTest paintbots

# executables
ConfigTest: Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o GameBoard.o Robot.o RobotAgentRoster.o LazyRobot.o RandomRobot.o AntiRandom.o
	g++ -o ConfigTest Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o GameBoard.o Robot.o RobotAgentRoster.o LazyRobot.o RandomRobot.o AntiRandom.o

BoardSquareTest: BoardSquareTest.o
	g++ -o BoardSquareTest BoardSquareTest.o

InternalBoardSquareTest: InternalBoardSquare.o InternalBoardSquareTest.o
	g++ -o InternalBoardSquareTest InternalBoardSquare.o InternalBoardSquareTest.o

ExternalBoardSquareTest: ExternalBoardSquare.o ExternalBoardSquareTest.o
	g++ -o ExternalBoardSquareTest ExternalBoardSquare.o ExternalBoardSquareTest.o

GameBoardTest: GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o Robot.o RobotAgentRoster.o GameBoardTest.o LazyRobot.o RandomRobot.o AntiRandom.o
	g++ -o GameBoardTest GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o Robot.o RobotAgentRoster.o GameBoardTest.o LazyRobot.o RandomRobot.o AntiRandom.o

PlainDisplayTest: PlainDisplay.o GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o Robot.o RobotAgentRoster.o PlainDisplayTest.o LazyRobot.o RandomRobot.o AntiRandom.o
	g++ -o PlainDisplayTest PlainDisplay.o GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o Robot.o RobotAgentRoster.o PlainDisplayTest.o LazyRobot.o RandomRobot.o AntiRandom.o

# main executable
paintbots: GameLogic.o Robot.o RobotAgentRoster.o LazyRobot.o RandomRobot.o AntiRandom.o InternalBoardSquare.o ExternalBoardSquare.o Config.o GameBoard.o ObserverPattern.o PlainDisplay.o
	g++ -o paintbots GameLogic.o Robot.o RobotAgentRoster.o LazyRobot.o RandomRobot.o AntiRandom.o InternalBoardSquare.o ExternalBoardSquare.o Config.o GameBoard.o ObserverPattern.o PlainDisplay.o

# Pattern rule for object files
%.o: %.cpp
	g++ -Wall -g -c $< -o $@

# Dependencies
Config.o: Config.cpp Config.h
ConfigTest.o: ConfigTest.cpp Config.h ITest.h
InternalBoardSquare.o: InternalBoardSquare.cpp InternalBoardSquare.h BoardSquare.h
ExternalBoardSquare.o: ExternalBoardSquare.cpp ExternalBoardSquare.h BoardSquare.h
BoardSquareTest.o: BoardSquareTest.cpp BoardSquare.h
InternalBoardSquareTest.o: InternalBoardSquareTest.cpp InternalBoardSquare.h BoardSquare.h
ExternalBoardSquareTest.o: ExternalBoardSquareTest.cpp ExternalBoardSquare.h BoardSquare.h
GameBoard.o: GameBoard.cpp GameBoard.h InternalBoardSquare.h ExternalBoardSquare.h Config.h ObserverPattern.h Robot.h
GameBoardTest.o: GameBoardTest.cpp GameBoard.h InternalBoardSquare.h ExternalBoardSquare.h BoardSquare.h Config.h ObserverPattern.h Robot.h
PlainDisplay.o: PlainDisplay.cpp PlainDisplay.h GameBoard.h ObserverPattern.h Robot.h
GameLogic.o: GameLogic.cpp GameLogic.h GameBoard.h Robot.h RobotAgentRoster.h
Robot.o: Robot.cpp Robot.h IRobotAgent.h RobotAgentRoster.h
RobotAgentRoster.o: RobotAgentRoster.cpp RobotAgentRoster.h IRobotAgent.h Robot.h
LazyRobot.o: LazyRobot.cpp LazyRobot.h IRobotAgent.h Robot.h ExternalBoardSquare.h
RandomRobot.o: RandomRobot.cpp RandomRobot.h IRobotAgent.h Robot.h ExternalBoardSquare.h
AntiRandom.o: AntiRandom.cpp AntiRandom.h IRobotAgent.h Robot.h ExternalBoardSquare.h

clean:
	rm -f *.o ConfigTest BoardSquareTest InternalBoardSquareTest ExternalBoardSquareTest GameBoardTest PlainDisplayTest paintbots
