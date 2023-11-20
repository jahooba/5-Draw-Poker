#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Login {
public:

    Login(const std::string& filename);

    //~Login();

    void registerUser(const std::string& username, const std::string& password);

    bool authenticateUser( std::string& username, std::string& password);

private:

    std::string filename;

    bool isLoggedIn;

    std::map<std::string, std::string> userMap; //key value pair (unhashed for now)

    void loadUserData();

    void saveUserData();
};
