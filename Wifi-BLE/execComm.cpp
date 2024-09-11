
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
