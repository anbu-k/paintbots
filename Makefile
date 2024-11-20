# Main target: build all test executables
all: ConfigTest BoardSquareTest InternalBoardSquareTest ExternalBoardSquareTest GameBoardTest PlainDisplayTest

# ConfigTest executable
ConfigTest: Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o GameBoard.o
	g++ -o ConfigTest Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o GameBoard.o

# BoardSquareTest executable
BoardSquareTest: BoardSquareTest.o
	g++ -o BoardSquareTest BoardSquareTest.o

# InternalBoardSquareTest executable
InternalBoardSquareTest: InternalBoardSquare.o InternalBoardSquareTest.o
	g++ -o InternalBoardSquareTest InternalBoardSquare.o InternalBoardSquareTest.o

# ExternalBoardSquareTest executable
ExternalBoardSquareTest: ExternalBoardSquare.o ExternalBoardSquareTest.o
	g++ -o ExternalBoardSquareTest ExternalBoardSquare.o ExternalBoardSquareTest.o

# GameBoardTest executable
GameBoardTest: GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o GameBoardTest.o
	g++ -o GameBoardTest GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o GameBoardTest.o

# PlainDisplayTest executable
PlainDisplayTest: PlainDisplay.o GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o PlainDisplayTest.o
	g++ -o PlainDisplayTest PlainDisplay.o GameBoard.o InternalBoardSquare.o ExternalBoardSquare.o Config.o ObserverPattern.o PlainDisplayTest.o

# Pattern rule for object files
%.o: %.cpp
	g++ -c $< -o $@

# Dependencies for object files
Config.o: Config.cpp Config.h
ConfigTest.o: ConfigTest.cpp Config.h ITest.h
InternalBoardSquare.o: InternalBoardSquare.cpp InternalBoardSquare.h BoardSquare.h
ExternalBoardSquare.o: ExternalBoardSquare.cpp ExternalBoardSquare.h BoardSquare.h
BoardSquareTest.o: BoardSquareTest.cpp BoardSquare.h
InternalBoardSquareTest.o: InternalBoardSquareTest.cpp InternalBoardSquare.h BoardSquare.h
ExternalBoardSquareTest.o: ExternalBoardSquareTest.cpp ExternalBoardSquare.h BoardSquare.h
GameBoard.o: GameBoard.cpp GameBoard.h InternalBoardSquare.h ExternalBoardSquare.h Config.h ObserverPattern.h
GameBoardTest.o: GameBoardTest.cpp GameBoard.h InternalBoardSquare.h ExternalBoardSquare.h BoardSquare.h Config.h ObserverPattern.h
PlainDisplay.o: PlainDisplay.cpp PlainDisplay.h GameBoard.h ObserverPattern.h

# Clean up all object files and test executables
clean:
	rm -f *.o ConfigTest BoardSquareTest InternalBoardSquareTest ExternalBoardSquareTest GameBoardTest PlainDisplayTest
