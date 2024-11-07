// @author Anbu Krishnan - anbu@iastate.edu
#include "Config.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

// constructor
Config::Config() 
    : hitDuration(20), paintBlobLimit(30), rockLowerBound(10), rockUpperBound(20),
      fogLowerBound(5), fogUpperBound(10), longRangeLimit(30) {}

// Constructor that parses configuration file
Config::Config(const std::string& filePath) : Config() {
    parseConfigFile(filePath);
}

// getters
int Config::getHitDuration() const {
    return hitDuration;
}

int Config::getPaintBlobLimit() const {
    return paintBlobLimit;
}

int Config::getRockLowerBound() const {
    return rockLowerBound;
}

int Config::getRockUpperBound() const {
    return rockUpperBound;
}

int Config::getFogLowerBound() const {
    return fogLowerBound;
}

int Config::getFogUpperBound() const {
    return fogUpperBound;
}

int Config::getLongRangeLimit() const {
    return longRangeLimit;
}

// Helper that parses the configuration file
void Config::parseConfigFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Error: Configuration file not found.");
    }

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;  // Skips empty lines and comments

        std::istringstream lineStream(line);
        std::string key, equalsSign, value;
        if (!(lineStream >> key >> equalsSign >> value) || equalsSign != "=") {
            throw std::runtime_error("Error: Invalid line in configuration file: " + line);
        }

        // Converts keys to uppercase 
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);

        // Parses the value and assigns it to the member variable
        int intValue = std::stoi(value);
        if (key == "HIT_DURATION") hitDuration = intValue;
        else if (key == "PAINTBLOB_LIMIT") paintBlobLimit = intValue;
        else if (key == "ROCK_LOWER_BOUND") rockLowerBound = intValue;
        else if (key == "ROCK_UPPER_BOUND") rockUpperBound = intValue;
        else if (key == "FOG_LOWER_BOUND") fogLowerBound = intValue;
        else if (key == "FOG_UPPER_BOUND") fogUpperBound = intValue;
        else if (key == "LONG_RANGE_LIMIT") longRangeLimit = intValue;
        else {
            throw std::runtime_error("Error: Unknown configuration key: " + key);
        }
    }
}

// Helper method to trim whitespace from a string
std::string Config::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");

    if (first == std::string::npos) return "";

    size_t last = str.find_last_not_of(" \t");
    
    return str.substr(first, (last - first + 1));
}
