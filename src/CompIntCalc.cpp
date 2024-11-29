#include "headers.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double result = 0.00;

double CalcMoney(double apy, int userCompYears, double principle) {
    int compFreqNum = 1;

    //vars for loop
    string compFreq = "";
    bool isCorrectChoice = false;

    //Ensure valid selection and prep for calculation
    while(isCorrectChoice == false) {

        //User enters how many times the interest is compounded
        cout<<"Choose the Compound Frequency: "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Daily"<<endl;
        cout<<"Weekly"<<endl;
        cout<<"Biweekly"<<endl;
        cout<<"Monthly"<<endl;
        cout<<"Quarterly"<<endl;
        cout<<"Semi-annually"<<endl;
        cout<<"Annually"<<endl;
        cout<<endl;

        //User enters selection
        cout<<"Enter Selection: ";
        cin>>compFreq;
        cout<<endl;
        
        if(compFreq == "Daily") {
            compFreqNum = 365;
            isCorrectChoice = true;
        }
        else if(compFreq == "Weekly") {
            compFreqNum = 52;
            isCorrectChoice = true;
        }
        else if(compFreq == "Biweekly") {
            compFreqNum = 26;
            isCorrectChoice = true;
        }
        else if(compFreq == "Monthly") {
            compFreqNum = 12;
            isCorrectChoice = true;
        }
        else if(compFreq == "Quarterly") {
            compFreqNum = 4;
            isCorrectChoice = true;
        }
        else if(compFreq == "Semi-annually") {
            compFreqNum = 2;
            isCorrectChoice = true;
        }
        else if(compFreq == "Annually") {
            compFreqNum = 1;
            isCorrectChoice = true;
        }
        else {
            cout<<"--- Invalid Selection. Please enter one of the choices provided above. ---"<<endl;
            cout<<endl;
        }
    }
    
    //Formula to calculate total money
    result = principle * pow((1 + apy / compFreqNum), compFreqNum * userCompYears); 

    //Display the total money
    cout << fixed << setprecision(2);
    cout << "Total Money after " << userCompYears << " years: $" << result << endl;

    return result;
}

int main(){
    double apy = 4.25 / 100;
    double princ = 8377.14;
    int yrs = 2;
    
    CalcMoney(apy, yrs, princ);

    cout<<"Interest earned after " << yrs << "years: $" << result - princ << endl;

    return 0;
}