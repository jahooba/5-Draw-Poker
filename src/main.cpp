#include<iostream>
#include "../header/login.hpp"
#include "../header/player.hpp"


using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void createAccount(Login &login)
{
    string newUser = "";
    string newPassword = "";
    

    cout << GREEN << "Enter a username" << RESET << endl;
    cin >> newUser;
    cout << GREEN << "Enter a password" << RESET << endl;
    cin >> newPassword;
    bool loginsuccess = login.registerUser(newUser, newPassword);
    if(loginsuccess)
    {
        cout << GREEN << "Successfully registered new user with username " << BLUE << newUser << RESET << endl;
    }
    else
    {
        cout << RED << "Unable to create a user, username already exists!! Please try again" << RESET << endl;
        createAccount(login);
    }
}

std::string userLogin(Login &login)
{
    string userName = "";
    string Pasword = "";

    cout << GREEN << "Please Enter your credentials below to login" << RESET << endl << endl << endl;

    cout << GREEN << "Enter a username" << RESET << endl;
    cin >> userName;
    cout << GREEN << "Enter a password" << RESET << endl;
    cin >> Pasword;

    int logSuccess = login.authenticateUser(userName, Pasword);
    if(logSuccess == 1)
    {
        cout << GREEN << "Successfully logged in, welcome " << BLUE << userName << RESET << endl;
        return userName;
    }
    else if(logSuccess == 2)
    {
        cout << RED << "Incorrect password, please try again " << BLUE << userName << RESET << endl;
        userLogin(login);
    }
    else if(logSuccess == 3)
    {
        cout << RED << "UserName does not exist, please try again" << RESET << endl;
        userLogin(login);
    }
    return "";
}

int main() {
    Login login("../userdata/userdata.txt");
    
    cout << GREEN <<"Welcome to Casino Game! Please Register or Sign in" << RESET << endl;
    cout << endl;
    
    string input = "";
    cout << GREEN << "Press l to login or c to create an account" << RESET << endl;

    cin >> input;
    while(input != "l" && input != "c")
    {
        cout << RED << "Please only press l to login or c to create an account" << RESET << endl;
        cin >> input;
    }
     
    if(input == "c")
    {
        cout << RED << "NOTE: We value your privacy at Casino Game and will not store your password" << RESET << endl;
        createAccount(login);
        cout << BLUE << "You can now login with your new credentials!!" << RESET << endl << endl << endl;
    }

    string res = userLogin(login);
    //------------------------------------LOGIN COMPLETE---------
    Player player(res);
    if(player.loadPlayer())
    {
        cout << "Successfully found a save file! Loading player now" << endl << endl << endl;
    }
    else
    {
        cout << "Unable to find a save file! Creating player now" << endl << endl << endl;
    }
        
    if(player.savePlayer())
    {
        cout << "Successfully saved player" << endl << endl << endl;
    }
    else
    {
        cout << "Unable to save player" << endl << endl << endl;
    }


    // login.registerUser("user1", "password1");
    // login.registerUser("user2", "password2");
    // login.registerUser("user3", "password3");
    return 0;
}