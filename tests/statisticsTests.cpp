#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/statistics.hpp"   
#include "../src/statistics.cpp"   
#include "../header/pokerPlayer.hpp" 
#include <iostream>
#include <string>

using namespace std;


TEST(statisticsTests, validConstructor){
    ASSERT_NO_THROW(Statistics stats = Statistics("Adam"));
}

TEST(statisticsTests, updateAndSaveTests){
    Statistics stats = Statistics("Adam");
    stats.update(32, 56);
    int temp1;
    int temp2;
    string temp3;

    ifstream tempFile;
    tempFile.open(stats.getFileName(), fstream::out);
    
    if(tempFile){
        tempFile >> temp3;
        tempFile >> temp1;
        tempFile >> temp2;
    }

    EXPECT_EQ(temp1, 32);
    EXPECT_EQ(temp2, 56);

    stats.clearFile();
    tempFile.close();
}


TEST(statisticsTests, loadTests){
    Statistics stats = Statistics("Adam");
    int temp1;
    int temp2;
    string temp3;

    stats.load();
    EXPECT_EQ(stats.getWins(), 32);
    EXPECT_EQ(stats.getGamesPlayed(), 56);
    ASSERT_NO_THROW(stats.print());

    stats.update(-32, -56);
}
