#ifndef EXECCOMM_H
#define EXECCOMM_H


#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include <sstream>




std::string execCommand(const std::string& command);

std::vector<std::string> parseSSIDs(const std::string& output);

std::string extractMACAddress(const std::string& input);

#endif // EXECCOMM_H
