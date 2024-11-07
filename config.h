// @author Anbu Krishnan - anbu@iastate.edu
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <stdexcept>

class Config {
public:
    // Constructors
    Config();  // Default constructor with default values
    Config(const std::string& filePath);  // Constructor that parses a configuration file

    // Getter methods for configuration parameters
    int getHitDuration() const;
    int getPaintBlobLimit() const;
    int getRockLowerBound() const;
    int getRockUpperBound() const;
    int getFogLowerBound() const;
    int getFogUpperBound() const;
    int getLongRangeLimit() const;

private:
    // Member variables for configuration parameters
    int hitDuration;
    int paintBlobLimit;
    int rockLowerBound;
    int rockUpperBound;
    int fogLowerBound;
    int fogUpperBound;
    int longRangeLimit;

    // Helper method to parse the configuration file
    void parseConfigFile(const std::string& filePath);

    // Helper method to trim whitespace from a string
    std::string trim(const std::string& str);
};

#endif // CONFIG_H
