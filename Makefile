all: testconfig

testconfig: Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o
	g++ -o testconfig Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o

Config.o: Config.cpp
	g++ -c Config.cpp -o Config.o

ConfigTest.o: ConfigTest.cpp
	g++ -c ConfigTest.cpp -o ConfigTest.o

InternalBoardSquare.o: InternalBoardSquare.cpp
	g++ -c InternalBoardSquare.cpp -o InternalBoardSquare.o

ExternalBoardSquare.o: ExternalBoardSquare.cpp
	g++ -c ExternalBoardSquare.cpp -o ExternalBoardSquare.o

clean:
	rm -f Config.o ConfigTest.o InternalBoardSquare.o ExternalBoardSquare.o testconfig

