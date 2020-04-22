/****************************************************
Program Filename: Assigment1
Author: Manuel Lopez
Date:03/29/16
Description: Setting C++ programs, printing and 
             variables and using documentation
Input:
Output: 
****************************************************/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

#define PI 3.14159265

int main()
{
    cout << "************************PART 1**************************"<< endl;
    /*First set of problems*/
    
    //Cosine problem
    double cosResult = cos((2*PI)/3);
    cout << "Cos(2\u03C0_/3) = " << cosResult << endl;
    
    //Sine problem
    double sinResult = 2 *sin((2*PI)/3);
    cout << "2sin(2\u03C0_/3) = " << sinResult << endl;
    
    //Tangent problem
    double tanResult = tan((-3*PI)/4);
    cout << "tan(-3\u03C0_/4 = " << tanResult << endl;
    
    //log base 10 problem
    double logResult = log10(55);
    cout << "log10(55) = " << logResult << endl;
    
    //Natural log problem
    double lnResult = log(60);
    cout << "ln(60) = " << lnResult << endl;
    
    
    /* Second set of problems */
    double numerator1 = log(15);
    double denominator1 = log(2);
    double answer1 = numerator1/ denominator1;
    cout << "\nUsing logbx = ln(x)/ln(b), log2(15) = ln(15)/ln(2)" << endl;
    cout << " ln(15)/ln(2) = " << answer1 << endl;
    
    double numerator2 = log(40);
    double denominator2 = log(4);
    double answer2 = numerator2/ denominator2;
    cout << "\nUsing logbx = ln(x)/ln(b), log4(40) = ln(40)/ln(4)" << endl;
    cout << " ln(15)/ln(2) = " << answer2 << endl;
    
    
    /* x = 1, 10, 100*/
    int x_equals[] = {1,10,100};
    cout << "\nPROBLEM: 3^sin(x)" << endl;
    for(int i = 0; i < 3; i++)
    {
        int x = x_equals[i];
        double exponent = sin(x);
        double answer2 = pow(3, exponent);
        cout << "\nSolving for x = " << x << endl;
        cout << "Exponent value is sin(" << x << ")" << " = " << exponent << endl;
        cout << "Simplyfied problem: 3^" << exponent << " = " <<  answer2 << endl;
    }
    
    cout << "\nPROBLEM: log(x^2 + 1)" << endl;
    for(int k = 0; k < 3; k++)
    {
        int x = x_equals[k];
        double inside = pow(x, 2)+1;
        double answer3 = log10(inside);
        cout << "\nSolving for x = " << x << endl;
        cout << "Inside value of log(" << x << "^2 + 1) = " << inside << endl;
        cout << "Simplyfied problem: log(" << inside << ")" << " = " << answer3 << endl;
    }
    
    cout << "********************PART 2**************************" << endl;
    
    cout << "The macros for this system are: " << endl;
    cout << "Max int signed: " << INT_MAX << endl;
    cout << "Min int signed: " << INT_MIN << endl;
    cout << "Max long signed: " << LONG_MAX << endl;
    cout << "Min long signed: " << LONG_MIN << endl;
    cout << "Max short signed: " << SHRT_MAX << endl;
    cout << "Min short signed: " << SHRT_MIN << endl;
    cout << "Unsigned int: " << UINT_MAX << endl;
    cout << "Unsigned long: " << ULONG_MAX << endl;
    cout << "Unsigned short: " << USHRT_MAX << endl;
    
    /***************Using sizeof()*****************/
    cout << "***************USING sizeof()***************"<< endl;
    signed int max_Int = pow(2,sizeof(int)*8-1)-1;
    cout << "Max int signed: " << max_Int << endl;
    signed int min_Int = pow(2, sizeof(int)*8);
    cout << "Min int signed: " << min_Int << endl;
    signed long max_long = pow(2, sizeof(long)*8);// does not output the correct numbers
    cout << "Max long signed:  " << max_long << endl;
    signed long min_long = pow(2, sizeof(long)*8);
    cout << "Min long signed: " << min_long << endl;
    signed short max_short = pow(2, sizeof(short)*8-1)-1;
    cout << "Max short signed: " << max_short << endl;
    signed short min_short = pow(2, sizeof(short)*8-1);
    cout << "Min short signed: " << min_short << endl;
    unsigned int max_Uint = pow(2, sizeof(int)*8)-1;
    cout << "Max int unsigned: " << max_Uint << endl;
    unsigned long max_Ulong = pow(2, sizeof(long)*8)-1;// does not output the correct nubmers
    cout << "Max long unsigned: " << max_Ulong << endl;
    unsigned short max_Ushort = pow(2, sizeof(short)*8)-1;
    cout << "Max short unsigned: " << max_Ushort << endl;

   
    return 0;
}