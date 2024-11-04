CXX = g++

all: testconfig

testconfig: Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o
	$(CXX) -o testconfig Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o

Config.o: Config.cpp
	$(CXX) -c Config.cpp -o Config.o

ConfigTest.o: ConfigTest.cpp
	$(CXX) -c ConfigTest.cpp -o ConfigTest.o

InternalBoardSquare.o: InternalBoardSquare.cpp
	$(CXX) -c InternalBoardSquare.cpp -o InternalBoardSquare.o

ExternalBoardSquare.o: ExternalBoardSquare.cpp
	$(CXX) -c ExternalBoardSquare.cpp -o ExternalBoardSquare.o
	
clean:
	rm -f Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o testconfig

.PHONY: all clean
