#include "../header/login.h"
using namespace std;

Login::Login(const string& filename) : filename(filename) {
    loadUserData();
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