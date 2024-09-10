#include <iostream>
#include "headers.h"
#include "ListBank.cpp"
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
}