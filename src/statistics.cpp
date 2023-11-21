#include "../header/statistics.cpp"

class Statistics{


Statistics::Statistics(string filename){
    fileName = filename;
    wins = 0;
    gamesPlayed = 0;
}

Statistics::Statistics(int wins, int gamesPlayed){
    this->wins = wins;
    this->gamesPlayed = gamesPlayed;
}


void Statistics::print();

void Statistics::update(int, int);

    void Statistics::load();

void Statistics::save();


}