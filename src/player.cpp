#include <string>
#include "../header/player.hpp"
#include "../header/balance.hpp"

Player::Player(string name){
    this->name = name;
}

Player::Player(string, int){

}

string Player::getName(){
    return this->name;
}
