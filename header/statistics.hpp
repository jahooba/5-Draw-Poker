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
    Statistics();
    Statistics(string);
    // Statistics(int, int);
    void print();
    void update(int, int);
    void load();
    void save();
    void clearFile();
    int getWins();
    int getGamesPlayed();
    string getFileName();


};