#include "../header/login.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <map>
using namespace std;




TEST(LoginTests, RegisterUserPopulatesFileCorrectly)
{
    std::ofstream ofs;
    ofs.open("userdata/testUserdata.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    Login login = Login("userdata/testUserdata.txt");

    string testUser = "testUser1";
    string testPassword = "testPassword";

    login.registerUser(testUser, testUser);
    
    EXPECT_TRUE(login.authenticateUser(testUser, testPassword));
}

TEST(LoginTests, AuthenticateUserTrue)
{
    Login login = Login("userdata/testUserdata.txt");

    string testUser = "testUser";
    string testPassword = "testPassword";

    login.registerUser(testUser, testUser);
    
    EXPECT_TRUE(login.authenticateUser(testUser, testPassword));
}


TEST(LoginTests, AuthenticateUserFail) 
{
    Login login = Login("userdata/testUserdata.txt");
    
    string testUser = "testUser";
    string testPassword = "testPassword";

    string failUser = "nonexistentUser";
    string wrongPassword = "wrongPassword";

    login.registerUser(testUser, testPassword);

    EXPECT_FALSE(login.authenticateUser(failUser, wrongPassword) == 1); //1 is success code
}


TEST(LoginTests, HashesCorrectly)
{
    map<string, int> userMap;
    Login login = Login("userdata/testUserdata.txt");
    ifstream file("userdata/testUserdata.txt", ios::app | ios::in);

    login.registerUser("testHash", "abc");
    if (file.is_open()) {
        string username;
        int  hashed_password;
        while (file >> username >> hashed_password) {
            userMap[username] = hashed_password;
        }

        file.close();
    }
    EXPECT_EQ(userMap["testHash"], 590);
}

TEST(LoginTests, changePasswordWhenUserDontExist) 
{
    Login login = Login("userdata/testUserdata.txt");
    
    string testUser = "testUserchangePasswordWhenUserDontExist";
    string testPassword = "testPassword";

    

    EXPECT_FALSE(login.changePassword(testUser, testPassword)); 
}
