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

    

private:

    string filename;

    bool isLoggedIn;

    map<string, string> userMap; //key value pair (unhashed for now)

    void loadUserData();

    void saveUserData();
};
