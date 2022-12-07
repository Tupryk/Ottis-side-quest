#ifndef UTILS
#define UTILS

#include <string>
#include <sstream>
#include <vector>
#include <iterator>


template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

bool compareStrings(std::string s1, std::string s2, std::string to) {return (abs(s1.compare(to)) < abs(s2.compare(to)));}


#endif
