//
//  main.cpp
//  Program Filename: AreaBeneathCurve
//  Author:Jose Manuel Lopez Alcala
//  Date: 4/14/16
//  Description: This program will be able to
//               calculate the area beneath the curve in to ways
//  Input: User input
//  Ouput: Area beneath the curve
//  Copyright © 2016 Jose Manuel Lopez Alcala. All rights reserved.

#include <iostream>
#include <cmath>
using namespace std;

float function_1(float x_value);
float function_2(float x_value);
float function_3(float x_value);
float function_4(float x_value);
float function_5(float x_value);
float rectangles_func(float start, float end, float n_subintervals, float (*mathFunc)(float));
float trapezoids_func(float start, float end, float n_subintervals, float (*mathFunc)(float));

int main(){
    /* Variables used in the program*/
    int choice_function = 0;
    int rectangle_trapezoid = 0;
    int rectangles = 0;
    int trapezoids = 0;
    int start_point = 0;
    int end_point = 0;
    
    cout << "Integral calculator" << endl;
    
    cout << "Choose a function to integrate: \n1) f(x) = 2x^5 + x^3 - 10x + 2 \n2) f(x) = 6x^2 - x + 10"
            "\n3) f(x) = 5x + 3 \n4) f(x) = 2x^3 + 120 \n5) f(x) = 2x^2" << endl;
    cin >> choice_function;
    
    //This while loop will make sure the user will input the correct answer.
    while (choice_function != 1 && choice_function != 2 && choice_function != 3 && choice_function != 4 && choice_function != 5) {
        cout << "Invalid response!" << endl;
        cout << "Choose a function to integrate: \n1) f(x) = 2x^5 + x^3 - 10x + 2 \n2) f(x) = 6x^2 - x + 10"
        "\n3) f(x) = 5x + 3 \n4) f(x) = 2x^3 + 120 \n5) f(x) = 2x^2" << endl;
        cin >> choice_function;
    }
    
    cout << "How would you like to calculate the area: \n1) Rectangles \n2) Trapezoids \n3) Rectangles & Trapezoids" << endl;
    cin >> rectangle_trapezoid;
    //This while loop will make sure the user will input the correct answer.
    while (rectangle_trapezoid != 1 && rectangle_trapezoid != 2 && rectangle_trapezoid != 3) {
        cout << "Invalid response!" << endl;
        cout << "How would you like to calculate the area: \n1) Rectangles \n2) Trapezoids \n3) Rectangles & Trapezoids" << endl;
        cin >> rectangle_trapezoid;
    }
    
    if(rectangle_trapezoid == 1){
        cout << "How many rectangles do you want? ";
        cin >> rectangles;
    }else if (rectangle_trapezoid == 2){
        cout << "How many trapezoids do you want? ";
        cin >> trapezoids;
    }else{
        cout << "How many subdintervals do you want?";
        cin >> rectangles;
        trapezoids  = rectangles;
    }
    
    cout << "What is your staring point? ";
    cin >> start_point;
    cout << "What is your end point? ";
    cin >> end_point;
    
    //If true, math function 1 will be used
    if (choice_function == 1) {
        if (rectangle_trapezoid == 1 ) {
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = rectangles_func(start_point, end_point, rectangles, function_1);
            cout << answer << endl;
        }else if (rectangle_trapezoid == 2){
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = trapezoids_func(start_point, end_point, trapezoids, function_1);
            cout << answer << endl;
        }else{
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            cout << "Using rectangles: ";
            float answer = rectangles_func(start_point, end_point, rectangles, function_1);
            cout << answer << endl;
            cout << "Using trapezoids: ";
            float answer2 = trapezoids_func(start_point, end_point, trapezoids, function_1);
            cout << answer2 << endl;
        }
    }
    //If true, math function 2 will be used
    else if (choice_function == 2){
        if (rectangle_trapezoid == 1) {
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = rectangles_func(start_point, end_point, rectangles, function_2);
            cout << answer << endl;
        }else if (rectangle_trapezoid == 2){
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = trapezoids_func(start_point, end_point, trapezoids, function_2);
            cout << answer << endl;
        }else{
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            cout << "Using rectangles: ";
            float answer = rectangles_func(start_point, end_point, rectangles, function_2);
            cout << answer << endl;
            cout << "Using trapezoids: ";
            float answer2 = trapezoids_func(start_point, end_point, trapezoids, function_2);
            cout << answer2 << endl;
        }
    }
    //If true, math function 3 will be used
    else if (choice_function == 3){
        if (rectangle_trapezoid == 1) {
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = rectangles_func(start_point, end_point, rectangles, function_3);
            cout << answer << endl;
        }else if (rectangle_trapezoid == 2){
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = trapezoids_func(start_point, end_point, trapezoids, function_3);
            cout << answer << endl;
        }else{
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            cout << "Using rectangles: ";
            float answer = rectangles_func(start_point, end_point, rectangles, function_3);
            cout << answer << endl;
            cout << "Using trapezoids: ";
            float answer2 = trapezoids_func(start_point, end_point, trapezoids, function_3);
            cout << answer2 << endl;
        }
    }
    //If true, math function 4 will be used
    else if (choice_function == 4){
        if (rectangle_trapezoid == 1) {
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = rectangles_func(start_point, end_point, rectangles, function_4);
            cout << answer << endl;
        }else if (rectangle_trapezoid == 2){
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = trapezoids_func(start_point, end_point, trapezoids, function_4);
            cout << answer << endl;
        }else{
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            cout << "Using rectangles: ";
            float answer = rectangles_func(start_point, end_point, rectangles, function_4);
            cout << answer << endl;
            cout << "Using trapezoids: ";
            float answer2 = trapezoids_func(start_point, end_point, trapezoids, function_4);
            cout << answer2 << endl;
        }
    }
    //If true, math function 5 will be used
    else if (choice_function == 5){
        if (rectangle_trapezoid == 1) {
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = rectangles_func(start_point, end_point, rectangles, function_5);
            cout << answer << endl;
        }else if (rectangle_trapezoid == 2){
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            float answer = trapezoids_func(start_point, end_point, trapezoids, function_5);
            cout << answer << endl;
        }else{
            cout << "The calculated area beneath the function between " << start_point << " and " << end_point << " is: " << endl;
            cout << "Using rectangles: ";
            float answer = rectangles_func(start_point, end_point, rectangles, function_5);
            cout << answer << endl;
            cout << "Using trapezoids: ";
            float answer2 = trapezoids_func(start_point, end_point, trapezoids, function_5);
            cout << answer2 << endl;
        }
    }
    else{
        cout << "You didn't choose a function. Program exited" << endl;
        return 0;
    }
    return 0;
}

/********************************
 **Functions: Functions that correspond to mathematical functions the user 
 ** wants to solve for.
 ** Parameters: x values 
 ** Pre-condition: User must choose the corresponding function
 ** Post-condition: Returns the corresponding value for the input value
 *******************************/
//FUNCTION #1
float function_1(float x_value){
    float value = (2.0 * pow(x_value, 5.0)) + pow(x_value, 3.) - (10.0 * x_value) + 2.0;
    return value;
}
//FUNCTION #2
float function_2(float x_value){
    float value = (6.0 * pow(x_value, 2)) - x_value + 10.0;
    return value;
}
//FUNCTION #3
float function_3(float x_value){
    float value = (5.0 * x_value) + 3.0;
    return value;
}
//FUNCTION #4
float function_4(float x_value){
    float value = (2.0 * pow(x_value, 3.0)) + 120.0;
    return  value;
}
//FUNCTION #5
float function_5(float x_value){
    float value = 2.0 * pow(x_value, 2.0);
    return value;
}


/*********************************************************
 ** Function: calculator using rectangles
 ** Description: This function will be integrating functions using rectangles
 ** Parameters: start point, end point, number of subintervals
 ** Pre-condition: User must be using rectangles to integrate
 ** Post-Condtion: Output of the integral
 ********************************************************/
float rectangles_func(float start, float end, float n_subintervals, float (*mathFunc)(float)){
    
    float delta_x = (end-start)/n_subintervals;
    float area = 0.0;
    
    for (int k = 1; k <= n_subintervals ; k++){
        float x_k = start + (k-1.0) * delta_x;
        area += (*mathFunc)(x_k) * delta_x;
    }
    return  area;
}

/********************************************************
 **Function: Calculator using trapezoids
 **Description: This function will be integrating using trapezoids
 ** Parameters: star point, end point, number of subintervals
 ** Pre-condition: User must be using rectangles to integrate
 ** Post-condition: Output of the integral
 *******************************************************/
float trapezoids_func(float start, float end, float n_subintervals, float (*mathFunc)(float)){
    
    float delta_x = (end - start)/ n_subintervals;
    float area = (1.0/2) * ((*mathFunc)(start));
    
    for (int k = 1; k <=(n_subintervals-1); k++) {
        float x_k = start + (k * delta_x);
        area += ((*mathFunc)(x_k));
    }
    area += (1.0/2) * ((*mathFunc)(end));
    area *= delta_x;

    
    return area;
}


