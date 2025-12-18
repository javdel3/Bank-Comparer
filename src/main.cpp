#include <iostream>
#include "headers.h"
#include <string>
#include <limits> //Library to help check if user correctly input integer
#include <sstream>
using namespace std;

class Bank {
  public:
    string name;
    double apy;
    double totalMoneyEarned;
};

int main() {
  //Variables for user input
  string input = "";
  double user_principle = 0.00;
  unsigned int user_numYearsWithBanks = 0;
  bool isValidBankName = false;
  //Create objects for each bank
  Bank user_Bank1;
  user_Bank1.name = "";
  user_Bank1.apy = 0.00;
  user_Bank1.totalMoneyEarned = 0.00;

  Bank user_Bank2;
  user_Bank2.name = "";
  user_Bank2.apy = 0.00;
  user_Bank2.totalMoneyEarned = 0.00;

  PrintStartDisplay();
  cout<<endl;
  
  //Get user principle
  cout << "To begin enter the Principle going to be used to compare between both Banks: $";
    //Check for valid inputs
  do {
    //Attempt to read a double number
    getline(cin, input);
    stringstream ss(input); //Initializes the stream with 'input' string as its input buffer

    if(ss >> user_principle && user_principle > 0.00 && ss.eof()) {
        break;
    }

    cout << "---Invalid input. Please enter only positive numbers.---" << endl;
    cout << "To begin enter the Principle going to be used to compare between both Banks: ";

  } while (true);
  cout<<endl;

  //Get user number of years planning to invest the money
  cout << "Please enter the Number of Years you plan to invest the money: "; //Use years for both banks' calculations
    //Check for valid inputs
  do {
    //Attempt to read an integer
    getline(cin, input);
    stringstream ss(input); //Initializes the stream with 'input' string as its input buffer
    if (ss >> user_numYearsWithBanks && user_numYearsWithBanks > 0 && ss.eof()) {
        //Successfully read a number so break the loop
        break;
    }

    cout << "---Invalid input. Please enter only positive numbers.---" << endl;
    cout << "Please enter the Number of Years you plan to invest the money: ";

  } while (true);
  cout<<endl;

  //List of available banks
  cout<<endl;
  ListBanks();
  cout<<endl;

  //Bank 1 Name
    //Check valid input
  while (true) {
    cout << "Enter a valid name for bank 1 from the list above: ";
    getline(cin, user_Bank1.name);

    if (CheckValidBankName(user_Bank1.name)) {
        break;
    }

    cout << "---Invalid bank name. Please try again.---" << endl;
}
cout<<endl;

  //Bank 2 Name
  while (true) {
    cout << "Enter a valid name for bank 2 from the list above: ";
    getline(cin, user_Bank2.name);

    if (CheckValidBankName(user_Bank2.name)) {
        break;
    }

    cout << "---Invalid bank name. Please try again.---" << endl;
}
cout<<endl;
  
  //Bank 1 APY
  cout<<"Enter the APY advertised for " << user_Bank1.name << ":" << endl;
  cout<<"(Please enter only a number. Do NOT express as a precentage. Ex. enter 3.50)"<<endl;
    //Check for valid inputs
  do {
    //Attempt to read a double number
    getline(cin, input);
    stringstream ss(input); //Initializes the stream with 'input' string as its input buffer
    if (ss >> user_Bank1.apy && user_Bank1.apy > 0.00 && ss.eof()) {
        //Successfully read a number so break the loop
        break;
    }

    cout << "---Invalid input. Please enter only positive numbers.---" << endl;
    cout<<"Enter the APY advertised for " << user_Bank1.name << " :" << endl;
    cout<<"(Please enter only a number. Do NOT express as a precentage. Ex. enter 3.50)"<<endl;

  } while (true);
  cout<<endl;

  //Bank 1 interest earned calculation
  user_Bank1.totalMoneyEarned = CalcMoney(user_Bank1.apy, user_numYearsWithBanks, user_principle); //Calculate for user's Bank 1
  cout<<endl;
  
  //Bank 2 APY
  cout<<"Enter the APY advertised for " << user_Bank2.name << ":" << endl;
  cout<<"(Please enter only a number. Do NOT express as a precentage. Ex. enter 3.50)"<<endl;
    //Check for valid inputs
  do {
    //Attempt to read a double number
    getline(cin, input);
    stringstream ss(input); //Initializes the stream with 'input' string as its input buffer

    if (ss >> user_Bank2.apy && user_Bank2.apy > 0.00 && ss.eof()) {
        //Successfully read a number so break the loop
        break;
    }

    cout << "---Invalid input. Please enter only positive numbers.---" << endl;
    cout<<"Enter the APY advertised for " << user_Bank2.name << " :" << endl;
    cout<<"(Please enter only a number. Do NOT express as a precentage. Ex. enter 3.50)"<<endl;

  } while (true);
  cout<<endl;

  //Bank 2 interest calculation
  user_Bank2.totalMoneyEarned = CalcMoney(user_Bank2.apy, user_numYearsWithBanks, user_principle); //Calculate for user's Bank 2
  cout<<endl;

  //Compare Banks' Results
  if(user_Bank2.totalMoneyEarned > user_Bank1.totalMoneyEarned) {
    cout<<"You should bank with " << user_Bank2.name << "!"<<endl;
  }
  else {
    cout<<"You should bank with " << user_Bank1.name << "!"<<endl;
  }

  //End program
  cout<<endl;
  PrintEndDisplay();
  cout<<endl;

  return 0;
}