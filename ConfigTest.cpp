// @author Anbu Krishnan - anbu@iastate.edu
#include "Config.h"
#include "ITest.h"
#include <iostream>
#include <stdexcept>

class ConfigTest : public ITest
{
public:
    ConfigTest() = default; // Default constructor

    bool doTests() const override
    {
        bool allTestsPass = true;

        allTestsPass &= testDefaultConstructor();
        allTestsPass &= testValidConfigFile();
        allTestsPass &= testMissingParameters();
        allTestsPass &= testInvalidConfigFile();
        allTestsPass &= testNonExistentFile();
        allTestsPass &= testWhitespaceConfigFile();
        allTestsPass &= testCaseInsensitiveConfigFile();
        allTestsPass &= testExtraWhitespaceConfigFile();
        allTestsPass &= testInvalidParameterNameConfigFile();
        allTestsPass &= testNonIntegerValuesConfigFile();

        std::cout << "ConfigTest Summary: " << (allTestsPass ? "PASS" : "FAIL") << std::endl;
        return allTestsPass;
    }

private:
    void checkTest(const std::string &testName, bool condition) const
    {
        if (condition)
        {
            std::cout << testName << ": PASS" << std::endl;
        }
        else
        {
            std::cout << testName << ": FAIL" << std::endl;
        }
    }

    bool testDefaultConstructor() const
    {
        try
        {
            Config config;
            checkTest("Default constructor - HIT_DURATION", config.getHitDuration() == 20);
            checkTest("Default constructor - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 30);
            checkTest("Default constructor - ROCK_LOWER_BOUND", config.getRockLowerBound() == 10);
            checkTest("Default constructor - ROCK_UPPER_BOUND", config.getRockUpperBound() == 20);
            checkTest("Default constructor - FOG_LOWER_BOUND", config.getFogLowerBound() == 5);
            checkTest("Default constructor - FOG_UPPER_BOUND", config.getFogUpperBound() == 10);
            checkTest("Default constructor - LONG_RANGE_LIMIT", config.getLongRangeLimit() == 30);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Default constructor: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testValidConfigFile() const
    {
        try
        {
            Config config("configfiletests/validConfig.txt");
            checkTest("Valid config file - HIT_DURATION", config.getHitDuration() == 28);
            checkTest("Valid config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 30);
            checkTest("Valid config file - ROCK_LOWER_BOUND", config.getRockLowerBound() == 10);
            checkTest("Valid config file - ROCK_UPPER_BOUND", config.getRockUpperBound() == 12);
            checkTest("Valid config file - FOG_LOWER_BOUND", config.getFogLowerBound() == 2);
            checkTest("Valid config file - FOG_UPPER_BOUND", config.getFogUpperBound() == 8);
            checkTest("Valid config file - LONG_RANGE_LIMIT", config.getLongRangeLimit() == 26);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Valid config file: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testMissingParameters() const
    {
        try
        {
            Config config("configfiletests/missingParametersConfig.txt");
            checkTest("Missing parameters - HIT_DURATION (default)", config.getHitDuration() == 20);
            checkTest("Missing parameters - PAINTBLOB_LIMIT (provided)", config.getPaintBlobLimit() == 25);
            checkTest("Missing parameters - ROCK_LOWER_BOUND (default)", config.getRockLowerBound() == 10);
            checkTest("Missing parameters - ROCK_UPPER_BOUND (provided)", config.getRockUpperBound() == 15);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Missing parameters: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testInvalidConfigFile() const
    {
        try
        {
            Config config("configfiletests/invalidConfig.txt");
            std::cout << "Invalid config file: FAIL - No exception thrown" << std::endl;
            return false;
        }
        catch (const std::exception &e)
        {
            std::cout << "Invalid config file: PASS - Exception: " << e.what() << std::endl;
            return true;
        }
    }

    bool testNonExistentFile() const
    {
        try
        {
            Config config("configfiletests/nonExistentFile.txt");
            std::cout << "Non-existent file: FAIL - No exception thrown" << std::endl;
            return false;
        }
        catch (const std::exception &e)
        {
            std::cout << "Non-existent file: PASS - Exception: " << e.what() << std::endl;
            return true;
        }
    }

    bool testWhitespaceConfigFile() const
    {
        try
        {
            Config config("configfiletests/whitespaceConfig.txt");
            checkTest("Whitespace config file - HIT_DURATION", config.getHitDuration() == 25);
            checkTest("Whitespace config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 35);
            checkTest("Whitespace config file - ROCK_LOWER_BOUND", config.getRockLowerBound() == 15);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Whitespace config file: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testCaseInsensitiveConfigFile() const
    {
        try
        {
            Config config("configfiletests/caseInsensitiveConfig.txt");
            checkTest("Case-insensitive config file - HIT_DURATION", config.getHitDuration() == 22);
            checkTest("Case-insensitive config file - PAINTBLOB_LIMIT", config.getPaintBlobLimit() == 29);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Case-insensitive config file: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testExtraWhitespaceConfigFile() const
    {
        try
        {
            Config config("configfiletests/extraWhitespaceConfig.txt");
            checkTest("Extra whitespace config file - FOG_LOWER_BOUND", config.getFogLowerBound() == 3);
            checkTest("Extra whitespace config file - FOG_UPPER_BOUND", config.getFogUpperBound() == 7);
            return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Extra whitespace config file: FAIL - Exception: " << e.what() << std::endl;
            return false;
        }
    }

    bool testInvalidParameterNameConfigFile() const
    {
        try
        {
            Config config("configfiletests/invalidParameterNameConfig.txt");
            std::cout << "Invalid parameter name config file: FAIL - No exception thrown" << std::endl;
            return false;
        }
        catch (const std::exception &e)
        {
            std::cout << "Invalid parameter name config file: PASS - Exception: " << e.what() << std::endl;
            return true;
        }
    }

    bool testNonIntegerValuesConfigFile() const
    {
        try
        {
            Config config("configfiletests/nonIntegerValuesConfig.txt");
            std::cout << "Non-integer values config file: FAIL - No exception thrown" << std::endl;
            return false;
        }
        catch (const std::exception &e)
        {
            std::cout << "Non-integer values config file: PASS - Exception: " << e.what() << std::endl;
            return true;
        }
    }
};

int main()
{
    ConfigTest test;
    return test.doTests() ? 0 : 1;
}
