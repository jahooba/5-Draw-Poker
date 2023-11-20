#include "../header/balance.hpp"
#include "../header/player.hpp"

void Balance::setBalance(double balance){
    this->balance = balance;
}

double Balance::getBalance(){
    return this->balance;
}

void Balance::appendBalance(double balance){
    this->balance += balance;
}
