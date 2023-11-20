#include "../header/login.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;



TEST(LoginTests, RegisterUser)
{
    Login login = Login("test_userdata.txt");
    login.registerUser("test_user", "test_password");
    EXPECT_TRUE(login.authenticateUser("test_user", "test_password"));
}


TEST(LoginTests, AuthenticateUserFail) 
{
    Login login = Login("test_userdata.txt");
    login.registerUser("test_user", "test_password");
    EXPECT_FALSE(login.authenticateUser("nonexistent_user", "wrong_password"));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}