#include "../header/statistics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

/*Statistics::Statistics(){
    cout << "default";
}
*/

Statistics::Statistics(string filename, string playername){
    fileName = filename;
    playerName = playername;
    wins = 0;
    gamesPlayed = 0;

    fstream file(filename, ios::app | ios::in);

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

    fstream file2(filename, ios::app);

    if (file2.is_open()) {

        if(!flag){
            file2 << playername << " ";
            file2 << wins << " " ;
            file2  << gamesPlayed << endl;
        }

    }
    file2.close();
}


Statistics::Statistics(int wins, int gamesPlayed){
    this->wins = wins;
    this->gamesPlayed = gamesPlayed;
}


void Statistics::print(){
    load();
    cout << "Stats - " << playerName << endl;
    cout << "Games Won Total - " << wins << endl;
    cout << "Games Played Total - " << gamesPlayed << endl;
}

void Statistics::update(int wins, int gamesPlayed){
    this->wins = wins;
    this->gamesPlayed = gamesPlayed;
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
    ifstream file;
    file.open(fileName, ios::in);
    ofstream temp;
    temp.open("temp.txt");

    string line;
    while (getline(file,line)){
        if ((line.substr(0, playerName.length())) != playerName){
            temp << line << endl;
        }
        else {
            temp << playerName << " " << wins << " " << gamesPlayed << endl;
        }
    }

    
    const char* fN = fileName.c_str();
    int num = remove(fN);
    rename("temp.txt","userStats.txt");

    temp.close();
    file.close();
}


int Statistics::getWins(){
    return wins;
}

int Statistics::getGamesPlayed(){
    return gamesPlayed;
}



