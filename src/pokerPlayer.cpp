#include "../header/statistics.hpp"  
#include "../header/player.hpp" 
#include "../header/balance.hpp"  
#include "../header/pokerPlayer.hpp"   


    //PokerPlayer::PokerPlayer() = default;

    PokerPlayer::PokerPlayer(string name):Player(name){
        pokerStats = Statistics("usernameStats.txt", name);
    }

    PokerPlayer::PokerPlayer(string name, double balance):Player(name, balance){
        pokerStats = Statistics("usernameStats.txt", name);
    }

    void PokerPlayer::updateStatistics(int gamesWon, int gamesPlayed){
        pokerStats.update(gamesWon, gamesPlayed);
    }

    void PokerPlayer::viewStatistics(){
        pokerStats.print();
    }



