 #include "../src/statistics.cpp"   
#include "../header/pokerPlayer.hpp"   


    PokerPlayer::PokerPlayer(string name):Player(name){
        //pokerStats = Statistics("usernameStatistics.txt", name);
        cout << " ";
    }

    PokerPlayer::PokerPlayer(string name, double balance):Player(name, balance){
        //pokerStats = Statistics("usernameStatistics.txt", name);
    }

    void PokerPlayer::updateStatistics(int gamesWon, int gamesPlayed){
        pokerStats.update(gamesWon, gamesPlayed);
    }

    void PokerPlayer::viewStatistics(){
        pokerStats.print();
    }



