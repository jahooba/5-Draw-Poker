#include "../header/login.hpp"
using namespace std;

Login::Login(const string& filename) : filename(filename) {
    loadUserData();
    isLoggedIn = false;
}


void Login::loadUserData() {
    ifstream file(filename);

    if (file.is_open()) {
        string username, password;
        while (file >> username >> password) {
            userMap[username] = password;
        }

        file.close();
    }
}

bool Login::registerUser(const string& username, const string& password)
{
    if (userMap.find(username) == userMap.end())
    {
        userMap[username] = password;
        saveUserData();
        return true;
    } 
    else 
    {
        return false;
    }
}

bool Login::authenticateUser(string& username,  string& password) {
    // Check if the username exists
    if (userMap.find(username) != userMap.end()) { // find(key) returns an interator pointing to the found element or .end() if not exist
        if (userMap[username] == password) {
            cout << "Login successful!\n";
            return true;
        } 
        else 
        {
            cout << "Incorrect password. Please try again.\n";
        }
    } 
    else
    {
        cout << "Username not found. Please register or check your username.\n";
    }

    return false;
}


void Login::saveUserData() {
    ofstream file(filename);

    if (file.is_open()) 
    {
        for (auto& entry : userMap) 
        {
            file << entry.first << " " << entry.second << "\n";
        }

        file.close();
    }
}