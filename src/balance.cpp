#include "../header/balance.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

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

Balance::~Balance() {
    save();
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
    save();
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

    file.close();
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

void Balance::print(){
    load();
    cout << "Balance - " << YELLOW << name << RESET << endl;
    cout << "You currently have a balance of " << YELLOW << balance << RESET << "." <<endl << endl;
}

void Balance::clearFile() {
    try {
        std::ofstream outputFile(fileName, std::ios::trunc);

        if (!outputFile.is_open()) {
            throw std::runtime_error("Unable to open file: " + fileName);
        }

        outputFile.close();

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}