// @author Anbu Krishnan - anbu@iastate.edu
#include "Config.h"
#include <iostream>
#include <stdexcept>

// Helper function to check test results
void checkTest(const std::string& testName, bool condition) {
    if (condition) {
        std::cout << testName << ": PASS" << std::endl;
    } else {
        std::cout << testName << ": FAIL" << std::endl;
    }
}

// Test function for the default constructor
void testDefaultConstructor() {
    try {
        Config config;
        checkTest("Default constructor - HIT_DURATION", config.getHitDuration() == 20);
        checkTest("Default constructor - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 30);
        checkTest("Default constructor - ROCK_LOWER_BOUND", config.getRockLowerBound() == 10);
        checkTest("Default constructor - ROCK_UPPER_BOUND", config.getRockUpperBound() == 20);
        checkTest("Default constructor - FOG_LOWER_BOUND", config.getFogLowerBound() == 5);
        checkTest("Default constructor - FOG_UPPER_BOUND", config.getFogUpperBound() == 10);
        checkTest("Default constructor - LONG_RANGE_LIMIT", config.getLongRangeLimit() == 30);
    } catch (const std::exception& e) {
        std::cout << "Default constructor: FAIL - Exception: " << e.what() << std::endl;
    }
}

// Test function for a valid configuration file
void testValidConfigFile() {
    try {
        Config config("validConfig.txt");
        checkTest("Valid config file - HIT_DURATION", config.getHitDuration() == 28);
        checkTest("Valid config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 30);
        checkTest("Valid config file - ROCK_LOWER_BOUND", config.getRockLowerBound() == 10);
        checkTest("Valid config file - ROCK_UPPER_BOUND", config.getRockUpperBound() == 12);
        checkTest("Valid config file - FOG_LOWER_BOUND", config.getFogLowerBound() == 2);
        checkTest("Valid config file - FOG_UPPER_BOUND", config.getFogUpperBound() == 8);
        checkTest("Valid config file - LONG_RANGE_LIMIT", config.getLongRangeLimit() == 26);
    } catch (const std::exception& e) {
        std::cout << "Valid config file: FAIL - Exception: " << e.what() << std::endl;
    }
}

// Test function for a file with missing parameters
void testMissingParameters() {
    try {
        Config config("missingParametersConfig.txt");
        checkTest("Missing parameters - HIT_DURATION (default)", config.getHitDuration() == 20);
        checkTest("Missing parameters - PAINTBLOB_LIMIT (provided)", config.getPaintBlobLimit() == 25);
        checkTest("Missing parameters - ROCK_LOWER_BOUND (default)", config.getRockLowerBound() == 10);
        checkTest("Missing parameters - ROCK_UPPER_BOUND (provided)", config.getRockUpperBound() == 15);
    } catch (const std::exception& e) {
        std::cout << "Missing parameters: FAIL - Exception: " << e.what() << std::endl;
    }
}

// Test function for an invalid configuration file
void testInvalidConfigFile() {
    try {
        Config config("invalidConfig.txt");
        std::cout << "Invalid config file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Invalid config file: PASS - Exception: " << e.what() << std::endl;
    }
}

// Test function for a non-existent configuration file
void testNonExistentFile() {
    try {
        Config config("nonExistentFile.txt");
        std::cout << "Non-existent file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Non-existent file: PASS - Exception: " << e.what() << std::endl;
    }
}

// Main function to run all tests
int main() {
    std::cout << "Config class unit tests" << std::endl;

    testDefaultConstructor();
    testValidConfigFile();
    testMissingParameters();
    testInvalidConfigFile();
    testNonExistentFile();

    return 0;
}
