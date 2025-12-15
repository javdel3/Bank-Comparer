#include "headers.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void ListBanks() {
    ifstream inFS("UserBankList"); //Specify text file to open
    string currentBank;    //Hold the name of the current bank being displayed from the file

    //Check if file correctly opened
    if(!inFS.is_open()) {
        cout<<"Unable to open file"<<endl;
        return;
    }

    cout<<"List of Banks Available:"<<endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    //Repeatedly output the bank name until at the end of the file
    while(getline(inFS, currentBank)) {           
        cout<<currentBank<<endl;
    }

    //Close text file
    inFS.close();
    cout << "----------------------------------------------------------------------------------" << endl;
}

bool CheckValidBankName (string user_BankName) {
    ifstream inFS("UserBankList"); //Specify text file to open
    string validBankName;    //Hold the name of the bank being compared as a valid option from the list

    //Check if file correctly opened
    if(!inFS.is_open()) {
        cout<<"Unable to open file"<<endl;
        return false;
    }

    while(getline(inFS, validBankName)) {
        if(user_BankName == validBankName) {
            return true;
        }
    }

    inFS.close();

    //User input was not a valid bank name from list
    return false;
}
