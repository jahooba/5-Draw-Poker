#include "../header/login.hpp"
using namespace std;


Login::Login(const string& filename) : filename(filename) {
    loadUserData();
    isLoggedIn = false;
}


void Login::loadUserData() {
    ifstream file(filename, ios::app | ios::in);

    if (file.is_open()) {
        string username;
        int  hashed_password;
        while (file >> username >> hashed_password) {
            userMap[username] = hashed_password;
        }

        file.close();
    }
}

bool Login::registerUser(const string& username, const string& password)
{
    if (userMap.find(username) == userMap.end())
    {
        userMap[username] = hashPassword(password);
        saveUserData();
        return true;
    } 
    else 
    {
        return false;
    }
}

int Login::authenticateUser(string& username,  string& password) {
    // Check if the username exists
    if (userMap.find(username) != userMap.end()) { // find(key) returns an interator pointing to the found element or .end() if not exist
        if (userMap[username] == hashPassword(password)) {
            return 1;// success
        } 
        else 
        {
            return 2; // wrong pwd
        }
    } 
    else
    {
        return 3; //DNE username
    }

}


void Login::saveUserData() {
    clearFile();
    ofstream file(filename, ios::app | ios::in);

    if (file.is_open()) 
    {
        for (auto& entry : userMap) 
        {
            file << entry.first << " " << entry.second << "\n";
        }

        file.close();
    }
}

int Login::hashPassword(const string& password)
{
    int result = 0;
    for (int i = 0; i < password.length(); ++i) 
    {
        char c = password[i];
        result += c*(i+1);
    }
    return result;
}

bool Login::changePassword(string& username, string& password)
{
    if (userMap.find(username) == userMap.end()) //username doesnt exist
    {
        return false;
    }
    userMap[username] = hashPassword(password);
    saveUserData();
    return true;
}

void Login::clearFile() {
    try {
        std::ofstream outputFile(filename, std::ios::trunc);

        if (!outputFile.is_open()) {
            throw std::runtime_error("Unable to open file: " + filename);
        }

        outputFile.close();

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}