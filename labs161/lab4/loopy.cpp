#include <iostream>
#include <cmath>
using namespace std;
void diamond();  
int main(){
	int number = 0;
	cout << "Enter a number: " << endl;
	cin >> number;
	for( int k = 1; k <= number; k++){
		for(int i = 0; i < k; i++){
			cout << k ;
		}
		cout << endl;
	}


	for(int k = 1; k <= number; k++){
	  for(int i = 1; i <= k; i++){
	   	cout << i;
	  }
	  cout << endl;
	}
	diamond(); 
	return 0;
}  

void diamond(){
	int length = 5;
       	length = length/2;

	for(int r=-length;r<=length;r++){
		for(int c=-length;c<=length;c++){
			if(abs(r)+abs(c)<=length)
				cout << "*";
			else
			   	cout << " ";
		}
		cout << endl;
	}
}

