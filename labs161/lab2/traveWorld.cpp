/**********Author: Jose Manuel Lopez Alcala
 *Date: 4/5/2016
 *Lab2 assignemnt
************/

#include <iostream>
using namespace std;
int location = 0;
int randomNumber = 0;
int shelter_food = 0;
int main(){
	cout << "Hello and welcome to the airport" << endl;
	cout << "Where would you like to go: \n1) Egypt \n2) China \n3) Italia" << endl;
	cout << "To answer: enter number then press enter" << endl;
	cin >> location;
	randomNumber = rand()%3+1;
	cout << "Your plane took the wrong course you ended up in ";

	if ( randomNubmer == 1)
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

	cout << "Do you want to find food or shelter? (1)Food (2)Shelter: " << endl;
	cin >> shelter_food;
	
	if(location == 1 && shelter_food ==1){
		cout << "You didn't find any food." << endl;
		

  
