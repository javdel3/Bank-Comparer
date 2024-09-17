#include <iostream>
#include "headers.h"
using namespace std;

class Bank {
    public:
        string name;
        double apy;
    private:
        double CalcMoney();
        double balance;
};

void Greet() {
    cout << "Welcome!" << endl;
}

int main() {
  Greet();
  cout<<endl;
  PrintDisplay();
  cout<<endl;
  ListBanks();
  cout<<endl;
  return 0;
}