#include<iostream>
#include "../header/login.hpp"
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


int main() {
    Login login("userdata.txt");
    
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
    }


    // login.registerUser("user1", "password1");
    // login.registerUser("user2", "password2");
    // login.registerUser("user3", "password3");
    return 0;
}