#pragma once
#include <string>

using namespace std;

class Statistics{
private:
    int wins;
    int gamesPlayed;
    string fileName;

public:
    Statistics(string);
    Statistics(int, int);
    void print();
    void update(int, int);
    void load();
    void save();

};