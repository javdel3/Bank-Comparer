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
