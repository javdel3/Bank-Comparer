#include <iostream>
#include "headers.h"
using namespace std;

class Bank {
    public:
        Bank(string name);
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