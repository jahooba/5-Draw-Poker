#include "../header/balance.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

Balance::Balance(string name){
    this->name = name;
    balance = 0;
    fileName = "userdata/" + name + "Balance.txt";
    fstream file(fileName, ios::app | ios::in);

    bool flag = false;

    if (file.is_open()) {
        string playerName;
        while(file >> playerName){
            if(name == playerName){
                flag = true;
            }
        }

        if(flag == false){
            file << name << " ";
            file << balance << " " ;
        }
        if(flag){
            load();
        }
    }

    file.close();

    fstream file2(fileName, ios::app);

    if (file2.is_open()) {

        if(!flag){
            file2 << name << " ";
            file2 << balance << " " ;
        }

    }
    file2.close();
}

Balance::Balance(string name, double balance){
    this->name = name;
    this->balance = balance;
    fileName = "userdata/" + name + "Balance.txt";
}

double Balance::getBalance(){
    return balance;
}

void Balance::appendBalance(double add){
    balance = balance + add;
    save();
}


void Balance::setBalance(double newBalance){
    balance = newBalance;
}

void Balance::load(){
    fstream file(fileName);
    if(file){
        string playerName;
        while(file >> playerName){
            if(name == playerName){
                file >> balance;
            }
        }
    }
}

void Balance::save(){
    fstream file;
    file.open(fileName);
    Balance::clearFile();

    if (file.is_open()) {
        file << name << " " << balance << endl;
    }

    file.close();
}

void Balance::clearFile() {
    std::ofstream ofs;
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}