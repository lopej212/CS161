#include <iostream>
using namespace std;

int main(){
   double table[101][101];
   int  position1, position2;
   double number1, number2;
   for(int x = 0; x <= 100; x++){
     for(int y = 0; y <=100; y++){
	table[x][y] = (x * 0.1) * (y * 0.1);
     }
   }

   cout << "Enter the first number: ";
   cin >> number1;
   position1 = number1 * 10;
   cout << "Enter a second number: ";
   cin >> number2;
   position2 = number2 * 10;
   cout << table[position1][position2]<< endl;

   return 0;
}


