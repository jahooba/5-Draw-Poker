#include "../header/login.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;



TEST(LoginTests, RegisterUser)
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

    login.registerUser(testUser, testUser);

    EXPECT_FALSE(login.authenticateUser(failUser, wrongPassword));
}
