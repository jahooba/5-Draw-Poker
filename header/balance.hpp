#include "../header/player.hpp"

class Balance: public Player{
    private:
        double balance;
        void setBalance(double);
    public:
        double getBalance();
        void appendBalance(double);
};
