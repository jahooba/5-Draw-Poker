#include "../header/statistics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

Statistics::Statistics() {
    fileName = "EMPTY";
    playerName = "DEFAULT";
    wins = -1;
    gamesPlayed = -1;
}

Statistics::Statistics(string playername){
    fileName = "userdata/" + playername + "Stats.txt";
    playerName = playername;
    wins = 0;
    gamesPlayed = 0;

    fstream file(fileName, ios::app | ios::in);

    bool flag = false;

    if (file.is_open()) {
        string name;
        while(file >> name){
            if(name == playerName){
                flag = true;
            }
        }

        if(flag == false){
            file << playername << " ";
            file << wins << " " ;
            file  << gamesPlayed << endl;
        }

        if(flag){
            load();
        }
    }

    file.close();

    fstream file2(fileName, ios::app);

    if (file2.is_open()) {

        if(!flag){
            file2 << playername << " ";
            file2 << wins << " " ;
            file2  << gamesPlayed << endl;
        }

    }
    file2.close();
}


// Statistics::Statistics(int wins, int gamesPlayed){
//     this->wins = wins;
//     this->gamesPlayed = gamesPlayed;
// }

void Statistics::clearFile() {
    std::ofstream ofs;
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void Statistics::print(){
    load();
    cout << "Stats - " << playerName << endl;
    cout << "Games Won Total - " << wins << endl;
    cout << "Games Played Total - " << gamesPlayed << endl;
}

void Statistics::update(int winsAdded, int gamesPlayedAdded){
    this->wins += winsAdded;
    this->gamesPlayed += gamesPlayedAdded;
    save();
}

void Statistics::load(){
    fstream file(fileName);
    if(file){
        string name;
        while(file >> name){
            if(name == playerName){
                file >> wins;
                file >> gamesPlayed;
            }
        }
    }
}

void Statistics::save(){
    fstream file;
    file.open(fileName);
    Statistics::clearFile();

    if (file.is_open()) {
        file << playerName << " " << wins << " " << gamesPlayed << endl;
    }

    file.close();
}


int Statistics::getWins(){
    return wins;
}

int Statistics::getGamesPlayed(){
    return gamesPlayed;
}

string Statistics::getFileName() {
    return fileName;
}

