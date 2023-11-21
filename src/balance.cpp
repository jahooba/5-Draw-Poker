#include "../header/balance.hpp"

using namespace std;

Balance::Balance(){
    balance = 0;
}

Balance::Balance(double balance){
    this->balance = balance;
}

double Balance::getBalance(){
    return balance;
}

void Balance::appendBalance(double add){
    balance = balance + add;
}


void Balance::setBalance(double newBalance){
    balance = newBalance;
}
