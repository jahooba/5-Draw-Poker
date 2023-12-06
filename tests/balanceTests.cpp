#include "gtest/gtest.h"
#include "../src/balance.cpp"

using namespace std;

TEST(balanceTests, validConstructor){
    Balance *temp;
    EXPECT_NO_THROW(temp = new Balance("Sarah"));
    delete temp;
}


TEST(balanceTests, loadAndSave){
    Balance temp = Balance("Alexa");
    temp.setBalance(52);
    temp.save();

    string temp1;
    int temp2;

    ifstream tempFile;
    tempFile.open("userdata/AlexaBalance.txt", fstream::out);
    
    if(tempFile){
        tempFile >> temp1;
        tempFile >> temp2;
    }

    EXPECT_EQ(temp1, "Alexa");
    EXPECT_EQ(temp2, 52);

    tempFile.close();

}

TEST(balanceTests, loadTests){
    Balance bal = Balance("Alexa");
    string temp1;
    int temp2;

    bal.load();
    EXPECT_EQ(bal.getBalance(), 52);
}
