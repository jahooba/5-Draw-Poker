#pragma once
using namespace std;

class Balance {
    private:
        double balance;
        void setBalance(double);
    public:
        double getBalance();
        void appendBalance(double);
};
