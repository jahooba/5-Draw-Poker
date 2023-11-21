#include<iostream>
#include "../header/login.hpp"

int main() {

    Login login("userdata.txt");
    login.registerUser("user1", "password1");
    login.registerUser("user2", "password2");
    login.registerUser("user3", "password3");
    return 0;
}