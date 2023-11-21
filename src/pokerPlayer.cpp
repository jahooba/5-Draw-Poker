 #include "../header/statistics.cpp"   
#include "../header/pokerPlayer.cpp"   


class PokerPlayer: public Player{

    void PokerPlayer::updateStatistics(int gamesWon, int gamesPlayed){
        pokerStats.update(gamesWon, gamesPlayed);
    }

    void PokerPlayer::viewStatistics(){
        pokerStats.print();
    }
}


