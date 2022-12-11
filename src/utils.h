#ifndef UTILS
#define UTILS

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>


template <typename Out>
void split(const std::string &s, char delim, Out result);

std::vector<std::string> split(const std::string &s, char delim);

bool compareStrings(std::string s1, std::string s2, std::string to);

std::vector<std::string> getFileLines(std::string path);


#endif
