
#include "execComm.h"


std::string execCommand(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;
    // Open a pipe to the command using popen
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    // Read the output from the command
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}



std::vector<std::string> parseSSIDs(const std::string& output) {
    std::vector<std::string> ssidList;
    std::istringstream stream(output);
    std::string line;

    // Read each line from the output
    while (std::getline(stream, line)) {
        // Trim any leading or trailing whitespace (if needed)
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // Add non-empty SSIDs to the list
        if (!line.empty()) {
            ssidList.push_back(line);
        }
    }

    return ssidList;
}
