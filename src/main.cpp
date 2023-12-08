#include<iostream>
#include "../header/login.hpp"
#include "../header/player.hpp"
#include "../header/pokerPlayer.hpp"
#include "../header/pokerComputer.hpp"
#include "../header/poker.hpp"
#include "../header/pokerScoreKey.hpp"
#include "../header/hand.hpp"

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
        cout << RED << "Press q to quit, or anything else to try again" << RESET <<endl;
        string inp;
        cin >> inp;
        if(inp == "q")
            return "notFound";
        userLogin(login);
    }
    else if(logSuccess == 3)
    {
        cout << RED << "UserName does not exist, please try again" << RESET << endl;
        cout << RED << "Press q to quit, or anything else to try again" << RESET <<endl;
        string inp;
        cin >> inp;
        if(inp == "q")
            return "notFound";
        userLogin(login);
    }
    return "";
}

string menu()
{
    string input;
    while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
    {
        

        cout << GREEN << "Welcome to the main menu! Enter what you want to do " << RESET << endl;
        cout << GREEN << "Press 1 to start poker " << RESET << endl;
        cout << GREEN << "Press 2 to view your stats " << RESET << endl;
        cout << GREEN << "Press 3 to view your balance " << RESET << endl;
        cout << GREEN << "Press 4 to change your password " << RESET << endl;
        cout << GREEN << "Press 5 to EXIT " << RESET << endl << endl;

        cin >> input;
        cout << endl;
    }
    return input;
}

int main() {
    Login login("userdata/userdata.txt");
    
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
    if(res == "notFound")
        return 0;
    //------------------------------------LOGIN COMPLETE---------
    PokerPlayer player(res);

    if(player.loadPlayer())
    {
        cout << "Successfully found a save file! Loading player now" << endl << endl << endl;
    }
    else
    {
        cout << "Unable to find a save file! Creating player now" << endl << endl << endl;
    }

    if (player.getPlayerBalance()->getBalance() <= 0) {
        cout << RED << "You went bankrupt! Have some pity money." << RESET << endl << endl;
        player.getPlayerBalance()->appendBalance(100);
    }

    string menuInput = "";
    while (menuInput != "5")
    {
        menuInput = menu();
    
        if(menuInput == "1") //poker
        {
            PokerPlayer* playerOne = &player;
            PokerPlayer* playerTwo = new PokerComputer();
            vector<PokerPlayer*> playerVector;
            playerVector.push_back(playerOne);
            playerVector.push_back(playerTwo);

            Poker game(playerVector);

            game.Game_Start();

            delete playerTwo;
        }
        else if (menuInput == "2") // stats
        {
            player.viewStatistics();
        }
        else if (menuInput == "3") //view balance
        {
            player.viewBalance();
        }
        else if (menuInput == "4") // change password
        {
            string newPwd;
            cout << "Enter your new password" << endl;
            cin >> newPwd;
            if(login.changePassword(res, newPwd))
            {
                cout << GREEN << "Successfully changed password!!" << RESET << endl << endl;
            }
            else
            {
                cout << RED << "Unable to change password..." << RESET << endl << endl;
            }
        }
        else if (menuInput == "5")
        {   
            cout << BLUE << "Saving User Data..." << endl;
            cout << "We hope to see you again!" << RESET << endl;
        }
    
    }


    return 0;
}