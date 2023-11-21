#pragma once

using namespace std;

class Balance{
private:
    double balance;
public:
    Balance();
    Balance(double balance);
    double getBalance();
    void appendBalance(double);
    void setBalance(double);
    
};
