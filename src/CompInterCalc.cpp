#include "headers.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double CalcMoney(double apy, int userCompYears, double principle) {
    double result = 0.00;

    //vars for loop
    string compFreq = "";
    bool isCorrectChoice = false;

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

    cin>>compFreq;

    //Ensure valid selection and prep for calculation
    while(isCorrectChoice == false) {
        cout<<"Choose the Compound Frequency: "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Daily"<<endl;
        cout<<"Weekly"<<endl;
        cout<<"Biweekly"<<endl;
        cout<<"Monthly"<<endl;
        cout<<"Quarterly"<<endl;
        cout<<"Semi-annually"<<endl;
        cout<<"Annually"<<endl;

        cin>>compFreq;
        
        if(compFreq == "Daily") {
            userCompYears = userCompYears*365;
            isCorrectChoice = true;
        }
        else if(compFreq == "Weekly") {
            userCompYears = userCompYears*52;
            isCorrectChoice = true;
        }
        else if(compFreq == "Biweekly") {
            userCompYears = userCompYears*26;
            isCorrectChoice = true;
        }
        else if(compFreq == "Monthly") {
            userCompYears = userCompYears*12;
            isCorrectChoice = true;
        }
        else if(compFreq == "Quarterly") {
            userCompYears = userCompYears*4;
            isCorrectChoice = true;
        }
        else if(compFreq == "Semi-annually") {
            userCompYears = userCompYears*2;
            isCorrectChoice = true;
        }
        else if(compFreq == "Annually") {
            userCompYears = userCompYears*1;
            isCorrectChoice = true;
        }
        else {
            cout<<"--- Invalid Selection. Please enter one of the choices provided above. ---"<<endl;
        }
    }
    
    //Formula to calculate total money
    result = principle * pow((1 + apy / 100), userCompYears); 

    //Display the total money
    cout << fixed << setprecision(2);
        //cout << "Total Money after " << userCompYears << " years: $" << result << endl;

    //return result;
}

int main(){
    double apy = 4.25;
    double princ = 8377.14;
    int yrs = 10;
    cout<< "Total Money: "<< CalcMoney(apy, yrs, princ)<<endl;
    return 0;
}