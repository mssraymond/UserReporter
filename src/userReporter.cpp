#include "userReporter.hpp"

UserReport::UserReport()
{
    this->rg = std::mt19937(std::random_device{}());
}

UserReport::~UserReport() {}

void UserReport::reportUser(const std::string &username)
{
    if (this->mp.find(username) == this->mp.end())
    {
        this->mp[username] = new std::vector<int>();
    }
    this->mp[username]->push_back(this->ls.size());
    this->ls.push_back(username);
}

void UserReport::unreportUser(const std::string &username)
{
    if (this->mp.find(username) != this->mp.end())
    {
        int index = this->mp[username]->back();
        std::string tmp = this->ls.at(index);
        this->ls[index] = this->ls.back();
        this->ls[this->ls.size() - 1] = tmp;
        this->ls.pop_back();
        this->mp[username]->pop_back();
        if (this->mp[username]->size() == 0)
        {
            delete this->mp.at(username);
            this->mp.erase(username);
        }
    }
}

std::string UserReport::getRandom()
{
    std::uniform_int_distribution<int> dist(0, this->ls.size() - 1);
    int index = dist(this->rg);
    return this->ls.at(index);
}

void UserReport::printRatio(int loops)
{
    std::unordered_map<std::string, int> dict;
    int total = 0;
    for (int _ = 0; _ < loops; _++)
    {
        std::string username = this->getRandom();
        if (dict.find(username) == dict.end())
        {
            dict[username] = 1;
        }
        else
        {
            dict[username]++;
        }
        total++;
    }
    for (const auto &pair : dict)
    {
        printf("Username: %s, Count: %d, Total: %d, Ratio: %.3f%%\n", pair.first.c_str(), pair.second, total, static_cast<float>(pair.second) / total * 100);
    }
    std::cout << std::endl;
}