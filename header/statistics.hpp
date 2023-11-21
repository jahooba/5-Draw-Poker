#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Statistics{
private:
    int wins;
    int gamesPlayed;
    string fileName;
    string playerName;

public:
    Statistics(string, string);
    Statistics(int, int);
    void print();
    void update(int, int);
    void load();
    void save();

};