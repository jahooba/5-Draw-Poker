#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Login {
public:

    Login(const string& filename);

    //~Login();

    bool registerUser(const string& username, const string& password);

    int authenticateUser( string& username, string& password); //1 - success, 2 - Wrong Password, 3 - UserName DNE

    bool changePassword(string& username, string& password);

    

private:

    string filename;

    bool isLoggedIn;

    map<string, int> userMap; //key value pair (hashed)

    void loadUserData();

    void saveUserData();

    int hashPassword(const string& password);
};
