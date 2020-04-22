//
//  main.cpp
//  Program File Name: FinancialCalc
//  Author: Jose Manuel Lopez Alcala
//  Date: 4/7/16
//  Description: Financial calculator the computes Loan Balance, Compound
//               interest and future value
//  Input: User input
//  Output: Loan balance, interest, and future value
//  Copyright © 2016 Jose Manuel Lopez Alcala. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**************************** These are all the functions used in the program********************/
float loan_Balance(float initialAmount, float interestRate, float equalPayment,float PeriodsB);
float contComp_interest(float initialAmount, float interestRate, float timeYears);
float futureValue(float initialAmount, float rateOfReturn, float numberOfPeriods);
string goalBalance(float function, float goal);
string goalBalance2(float function, float goal);



int main(){
    /*For while looop*/
    bool inputCorrect = false;
    
    /*User input*/
    int user_choice = 0;
    
    /* Variables used for balance calculator*/
    float initial_Amount = 0;
    float interest_Rate = 0;
    float equal_Payment = 0;
    float periods = 0;
    float years = 0;
    float goal = 0;
    
    cout << "Welcome to the Financial Calculator!" << endl;
    
    //While loop used to make sure the user inputs a valid number
    while (inputCorrect == false) {
        cout << "\nWhat would you like to calculate?\n(Enter number and press enter)" << endl;
        cout << "1 - Loan Balance \n2 - Continuously Compounded Interest \n3 - Future Value" << endl;
        cin >> user_choice;
        
        //Runs through the loan balance calculator CHOICE 1
        if (user_choice == 1) {
            inputCorrect = true;
            cout << "You have chosen to calculate Loan Balance." << endl;
            cout << "What is the Initial Value  in Dollars(eg. 10): ";
            cin >> initial_Amount;
            cout << "What is the  interest rate (as decimal eg. 8% = .08):  ";
            cin >> interest_Rate;
            cout << "What is the amount of each equal payment: " << endl;
            cin >> equal_Payment;
            cout << "What is the number of time periods elapsed at any given point: ";
            cin >> periods;
            
            float x = loan_Balance(initial_Amount, interest_Rate, equal_Payment, periods);// x stores the output of the loan_balance() function
           /**************** This sections outputs the goal and the value of x****************/ 
            cout << "\nWhat is your goal balance in dollars: ";
            cin >> goal;
            cout << "Your goal amount is: $" << goal << endl;
            cout << "The actual balance is: $" << x << endl;
            cout << goalBalance2(x, goal) << endl;
            
        }
        //Runs throught the Continuously Compounded Interest calculator CHOICE 2
        else if (user_choice == 2){
            inputCorrect = true;
            cout << "You have chosen to calculate Continuously Compounded Interest" << endl;
            cout << "what is the Initial Investment in Dollars(eg. 10):  ";
            cin >> initial_Amount;
            cout << "What is the annual interest rate ( as decimal eg. 8% = .08): ";
            cin >> interest_Rate;
            cout << "What is the amount of time in years: ";
            cin >> years;
            
            float x = contComp_interest(initial_Amount, interest_Rate, years);// x stores the output of the contComp_interest() fucntion
           /************This section outputs the goal and hte value of x************/ 
            cout << "\nWhat is your goal amount in dollars: ";
            cin >> goal;
            cout << "Your goal amount is: $" << goal << endl;
            cout << "The actual amount was: $" << x << endl;
            cout << goalBalance(x, goal) << endl;
            
        }
        //Runs throught the future value calculator CHOICE 3
        else if (user_choice == 3){
            inputCorrect = true;
            cout << "You have chosen to calculate Future Value: " << endl;
            cout << "What is the Initial Investment in Dollars(eg. 10): ";
            cin >> initial_Amount;
            cout << "What is the annual rate of return: ";
            cin >>interest_Rate;
            cout << "What is the number of periods: ";
            cin >> periods;
            
            float x = futureValue(initial_Amount, interest_Rate, periods);//x stores the output of the futureValue() function
           /************This section outputs the goal and the value of x************/ 
            cout << "\nWhat is your goal future value in dollars: ";
            cin >> goal;
            cout << "Your goal future value  is: $" << goal << endl;
            cout << "The actual future value is: $" << x << endl;
            cout << goalBalance(x, goal) << endl;
        }
        // Tells user their input is wrong and starts over
        else{
            cout << "You have entered in invalid answer." << endl;
        }
    }
    
    return 0;
    
}

/*********************************************************
 **Function: loan_balance()
 **Description: This funciton will calculate the remaining balance
 **Parameters:initial amount, interest Rate, equal pay and period
 **Pre-condition: User must choose option 1
 **Post-condition: Balance output
 *********************************************************/
float loan_Balance(float initialAmount, float interestRate, float equalPayment,float PeriodsB){
    float A = initialAmount;
    float i = interestRate;
    float P = equalPayment;
    float n = PeriodsB;
    
    float amount_left = A*pow((1+i), n)-(P/i)*(pow((1+i),n)-1); //calculation line
    
    return amount_left;
}

/**********************************************************
 **Function: contComp_interest()
 **Description: This function will calculate the continuously componded interest
 **Parameters: initial amount, interest rate, time in years
 **Pre-condition: User must choose option 2
 **Post-condition: balance output
 *********************************************************/
float contComp_interest(float initialAmount, float interestRate, float timeYears){
    float P = initialAmount;
    float r = interestRate;
    float t = timeYears;
    
    float account_balance = P * pow(M_E, (r * t)); //calucation line
    
    return account_balance;
}

/**********************************************************
 **Function: futureValue()
 **Description: This function will calculute the future value 
 **Parameters: initial amount, rate of return, number of periods
 **Pre-condition: User must choose option 3
 **Post-condition: balance output
 *********************************************************/
float futureValue(float initialAmount, float rateOfReturn, float numberOfPeriods){
    float C = initialAmount;
    float r = rateOfReturn;
    float n = numberOfPeriods;
    
    float future_value = C * pow((1 + r), n); //calulation line
    
    return future_value;
}

/**********************************************************
 ** Functiion: goalBalance()
 ** Description: This function will tell the user whether they met their goal or not
 ** Parmeters: output from the user functions and goal 
 ** Pre-condition: none
 ** Post-condition: infor user wheter or not they met their goal
 **********************************************************/
string goalBalance(float function, float goal){
    string meet_NotMeet = " ";
    
    if (function == goal) {
        meet_NotMeet = "You will meet your goal. ";
    }
    else if (function > goal){
        meet_NotMeet = "You will meet your goal. ";
    }
    else{
        meet_NotMeet = "You will not meet your goal. ";
    }
    return meet_NotMeet;
}

/**********************************************************
 ** Functiion: goalBalance2()
 ** Description: This function will tell the user whether they met their goal or not 
 **              ONLY works  for loan balance
 ** Parmeters: output from the user functions and goal
 ** Pre-condition: none
 ** Post-condition: infor user wheter or not they met their goal
 **********************************************************/
string goalBalance2(float function, float goal){
    string meet_NotMeet = " ";
    
    if (function == goal) {
        meet_NotMeet = "You will meet your goal. ";
    }
    else if (function < goal){
        meet_NotMeet = "You will meet your goal. ";
    }
    else{
        meet_NotMeet = "You will not meet your goal. ";
    }
    return meet_NotMeet;
}
