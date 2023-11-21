#include "../header/statistics.cpp"

class Statistics{

Statistics::Statistics(string filename, string playername){
    fileName = filename;
    playerName = playername;
    wins = 0;
    gamesPlayed = 0;

    ifstream file(filename);

    if (file.is_open()) {
        file << playername << " ";
        file << "wins " << wins << " " ;
        file << "games played " << gamesPlayed << endl;
        file.close();
    }
    
    file.close();
}

Statistics::Statistics(int wins, int gamesPlayed){
    this->wins = wins;
    this->gamesPlayed = gamesPlayed;
}


void Statistics::print(){
    ofstream file(filename);
    if (file.is_open()) {
        string name;
        while(file >> name){
            if(name == playerName){
                cout << "Stats - " << playerName << endl;
            }
        }
    }
}

void Statistics::update(int wins, int gamesPlayed){
    this->wins = wins;
    this->gamesPlayed = gamesPlayed;
}

void Statistics::load();

void Statistics::save(){
    if (file.is_open()) {
        string name;
        while(file >> name){
            if(name == playerName){

            }
        }
    }
}

}

