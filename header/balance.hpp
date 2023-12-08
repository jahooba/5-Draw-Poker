#pragma once
#include <string>

using namespace std;

class Balance{
private:
    double balance;
    string name;
    string fileName;

public:
    Balance(string name);
    Balance(string name, double balance);
    double getBalance();
    void appendBalance(double);
    void setBalance(double);
    void load();
    void save();
    void clearFile();
    void print();
};
