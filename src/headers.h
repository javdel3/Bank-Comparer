#ifndef HEADER_FILES
#define HEADER_FILES

#include <string>
using namespace std;

void PrintStartDisplay();
void ListBanks();
bool CheckValidBankName(string user_BankName);
double CalcMoney(double apy, int userCompYears, double principle);
void PrintEndDisplay();

#endif