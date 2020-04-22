/**********Author: Jose Manuel Lopez Alcala
 *Date: 4/5/2016
 *Lab2 assignemnt
 ************/

#include <iostream>
#include <stdlib.h>
using namespace std;
int location = 0;
int randomNumber = 0;
int shelter_food = 0;
int explore = 0;

int main(){
    cout << "Hello and welcome to the airport" << endl;
    cout << "Where would you like to go: \n1) Egypt \n2) China \n3) Italia" << endl;
    cout << "To answer: enter number then press enter" << endl;
    cin >> location;
    randomNumber = rand()%3+1;
    cout << "Your plane took the wrong course you ended up in ";
    
    if ( randomNumber == 1)
    {
        cout << "Egypt." << endl;
    }
    else if(randomNumber == 2)
    {
        cout << "China. " << endl;
    }
    else
    {
        cout << "Italy." << endl;
    }
    
    /**********Food or shelter*********/
    cout << "Do you want to find food or shelter? (1)Food (2)Shelter: " << endl;
    cin >> shelter_food;
    
    if(location == 1 && shelter_food ==1)//egypt
    {
        cout << "You didn't find any food."  << endl;
    }
    else if (location == 1 && shelter_food == 2)
    {
        cout << "You found shelter" << endl;
    }
    
    if (location == 2 && shelter_food == 1)//china
    {
        cout << "You found found" << endl;
    }
    else if (location == 2 && shelter_food == 2){
        cout << "You found shelter" << endl;
    }
    
    if (location == 3 && shelter_food == 1) {
        cout << "You found pizza!" << endl;
    }else if (location == 3 && shelter_food == 2){
        cout << "You found shelter" << endl;
    }
    
    /*************Explore of not**************/
    cout << "Do you wan to explore or not: (1)Yes (2)No " << endl;
    cin >> explore;
    
    if (location == 1 && explore == 1) {
        cout << "You explored the pyramids and got chased mommmies" << endl;
    }else if (location == 1 && explore == 2){
        cout << "You went back home." << endl;
        cout << "End of travel."<< endl;
    }
    
    if (location == 2 && explore == 1) {
        cout << "You explored the jungle and got chased by a dragon,but made it back to shelter." << endl;
    } else if (location ==2 && explore ==2){
        cout << "You went back home!" <<endl;
        cout << "End of travel." << endl;
    }
    
    if (location == 3 && (explore == 1||2)) {
        cout << "You got bit by a spider and you suffered a painfull and slow death." << endl;
        cout << "End of your travel." << endl;
    }
}

