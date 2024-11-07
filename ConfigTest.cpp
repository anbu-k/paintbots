// @author Anbu Krishnan - anbu@iastate.edu
#include "Config.h"
#include <iostream>
#include <stdexcept>

// helper to check test results
void checkTest(const std::string& testName, bool condition) {
    if (condition) {
        std::cout << testName << ": PASS" << std::endl;
    } else {
        std::cout << testName << ": FAIL" << std::endl;
    }
}

// tests the default constructor
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

// tests for a valid configuration file
void testValidConfigFile() {
    try {
        Config config("configfiletests/validConfig.txt");
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

// tests for a file with missing parameters
void testMissingParameters() {
    try {
        Config config("configfiletests/missingParametersConfig.txt");
        checkTest("Missing parameters - HIT_DURATION (default)", config.getHitDuration() == 20);
        checkTest("Missing parameters - PAINTBLOB_LIMIT (provided)", config.getPaintBlobLimit() == 25);
        checkTest("Missing parameters - ROCK_LOWER_BOUND (default)", config.getRockLowerBound() == 10);
        checkTest("Missing parameters - ROCK_UPPER_BOUND (provided)", config.getRockUpperBound() == 15);
    } catch (const std::exception& e) {
        std::cout << "Missing parameters: FAIL - Exception: " << e.what() << std::endl;
    }
}

// tests for an invalid configuration file 
void testInvalidConfigFile() {
    try {
        Config config("configfiletests/invalidConfig.txt");
        std::cout << "Invalid config file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Invalid config file: PASS - Exception: " << e.what() << std::endl;
    }
}

// tests for a non existent configuration file
void testNonExistentFile() {
    try {
        Config config("configfiletests/nonExistentFile.txt");
        std::cout << "Non-existent file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Non-existent file: PASS - Exception: " << e.what() << std::endl;
    }
}

// tests for trailing whitespace
void testWhitespaceConfigFile() {
    try {
        Config config("configfiletests/whitespaceConfig.txt");
        checkTest("Whitespace config file - HIT_DURATION", config.getHitDuration() == 25);
        checkTest("Whitespace config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 35);
        checkTest("Whitespace config file - ROCK_LOWER_BOUND", config.getRockLowerBound() == 15);
    } catch (const std::exception& e) {
        std::cout << "Whitespace config file: FAIL - Exception: " << e.what() << std::endl;
    }
}

// tests for mixed case parameter names 
void testCaseInsensitiveConfigFile() {
    try {
        Config config("configfiletests/caseInsensitiveConfig.txt");
        checkTest("Case-insensitive config file - HIT_DURATION", config.getHitDuration() == 22);
        checkTest("Case-insensitive config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 29);
    } catch (const std::exception& e) {
        std::cout << "Case-insensitive config file: FAIL - Exception: " << e.what() << std::endl;
    }
}

// tests for unexpected additional whitespace 
void testExtraWhitespaceConfigFile() {
    try {
        Config config("configfiletests/extraWhitespaceConfig.txt");
        checkTest("Extra whitespace config file - FOG_LOWER_BOUND", config.getFogLowerBound() == 3);
        checkTest("Extra whitespace config file - FOG_UPPER_BOUND", config.getFogUpperBound() == 7);
    } catch (const std::exception& e) {
        std::cout << "Extra whitespace config file: FAIL - Exception: " << e.what() << std::endl;
    }
}

// tests for invalid parameter names
void testInvalidParameterNameConfigFile() {
    try {
        Config config("configfiletests/invalidParameterNameConfig.txt");
        std::cout << "Invalid parameter name config file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Invalid parameter name config file: PASS - Exception: " << e.what() << std::endl;
    }
}

// tests for non integer values where integers are expected
void testNonIntegerValuesConfigFile() {
    try {
        Config config("configfiletests/nonIntegerValuesConfig.txt");
        std::cout << "Non-integer values config file: FAIL - No exception thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Non-integer values config file: PASS - Exception: " << e.what() << std::endl;
    }
}

// Main
int main() {
    std::cout << "Config class unit tests" << std::endl;

    testDefaultConstructor();
    testValidConfigFile();
    testMissingParameters();
    testInvalidConfigFile();
    testNonExistentFile();
    testWhitespaceConfigFile();
    testCaseInsensitiveConfigFile();
    testExtraWhitespaceConfigFile();
    testInvalidParameterNameConfigFile();
    testNonIntegerValuesConfigFile();

    return 0;
}
