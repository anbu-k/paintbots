// @author Anbu Krishnan - anbu@iastate.edu
#include "GameBoard.h"
#include "ObserverPattern.h"
#include <iostream>
#include <cassert>
#include <string>

// Helper function to check test results
void checkTest(const std::string& testName, bool condition) {
    if (condition) {
        std::cout << testName << ": PASS" << std::endl;
    } else {
        std::cout << testName << ": FAIL" << std::endl;
    }
}

// Mock observer class for testing
class MockObserver : public Observer<std::string> {
private:
    std::vector<std::string> receivedMessages;

public:
    void update(std::string* observableData) override {
        if (observableData) {
            receivedMessages.push_back(*observableData);
        }
    }

    const std::vector<std::string>& getMessages() const {
        return receivedMessages;
    }

    void clearMessages() {
        receivedMessages.clear();
    }
};

// Test for singleton pattern
void testSingletonPattern() {
    GameBoard* instance1 = GameBoard::getInstance("xyzzy");
    GameBoard* instance2 = GameBoard::getInstance("xyzzy");
    checkTest("Singleton pattern - Same instance", instance1 == instance2);
    GameBoard* instanceInvalid = GameBoard::getInstance("wrong_password");
    checkTest("Singleton pattern - Invalid password returns NULL", instanceInvalid == nullptr);
}

// Test default configuration
void testDefaultConfiguration() {
    GameBoard* gameBoard = GameBoard::getInstance("xyzzy");
    InternalBoardSquare& square = gameBoard->getSquare(0, 0);
    checkTest("Default configuration - Square is empty", square.getSquareType() == SquareType::EMPTY);
}

// Test custom configuration
void testCustomConfiguration() {
    Config customConfig("configfiletests/validConfig.txt");
    GameBoard* gameBoard = GameBoard::getInstance("xyzzy", customConfig);
    InternalBoardSquare& square = gameBoard->getSquare(7, 7);
    checkTest("Custom configuration - Square is empty", square.getSquareType() == SquareType::EMPTY);
}

// Test observer notifications
void testObserverNotifications() {
    GameBoard* gameBoard = GameBoard::getInstance("xyzzy");
    MockObserver observer;

    // Register the observer
    gameBoard->registerObserver(&observer);

    // Trigger notifications
    gameBoard->setSquareColor(5, 5, Color::RED);
    gameBoard->setRobotPaintColor(RobotColor::BLUE, Color::BLUE);

    const auto& messages = observer.getMessages();
    checkTest("Observer - Correct number of notifications", messages.size() == 2);
    checkTest("Observer - First notification correct", messages[0] == "Square changed at (5, 5)");
    checkTest("Observer - Second notification correct", messages[1].find("Score updated") != std::string::npos);

    // Clean up
    observer.clearMessages();
    gameBoard->removeObserver(&observer);
}

// Main function
int main() {
    std::cout << "GameBoard class unit tests" << std::endl;

    testSingletonPattern();
    testDefaultConfiguration();
    testCustomConfiguration();
    testObserverNotifications();

    return 0;
}
