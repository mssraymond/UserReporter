#ifndef USERREPORTER_HPP
#define USERREPORTER_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <random>

class UserReport
{
private:
    std::unordered_map<std::string, std::vector<int> *> mp;
    std::vector<std::string> ls;
    std::mt19937 rg;

public:
    UserReport();
    ~UserReport();
    void reportUser(const std::string &username);
    void unreportUser(const std::string &username);
    std::string getRandom();
    void printRatio(int loops);
};

#endif