#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/statistics.hpp"   
#include "../src/statistics.cpp"   
#include "../header/pokerPlayer.hpp" 
#include <iostream>
#include <string>

using namespace std;


TEST(statisticsTests, validConstructor){
    ASSERT_NO_THROW(Statistics stats = Statistics("userStats.txt", "Adam"));
    int x = remove("userStats.txt");
}

TEST(statisticsTests, updateAndSaveTests){
    Statistics stats = Statistics("userStats.txt", "Adam");
    stats.update(30, 20);
    int temp1;
    int temp2;
    string temp3;
    ifstream tempFile("userStats.txt");
    if(tempFile){
        tempFile >> temp3;
        tempFile >> temp1;
        tempFile >> temp2;
    }
    EXPECT_EQ(temp1, 30);
    EXPECT_EQ(temp2, 20);
    int x = remove("userStats.txt");

    tempFile.close();
}

TEST(statisticsTests, loadTests){
    Statistics stats = Statistics("userStats.txt", "Adam");
    int temp1;
    int temp2;
    string temp3;
    ofstream tempFile2("random.txt");
    if(tempFile2){
        tempFile2 << "Adam 32 56" << endl;
    }
    int x = remove("userStats.txt");
    rename("random.txt", "userStats.txt");
    tempFile2.close();
    
    stats.load();
    EXPECT_EQ(stats.getWins(), 32);
    EXPECT_EQ(stats.getGamesPlayed(), 56);
    ASSERT_NO_THROW(stats.print());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}