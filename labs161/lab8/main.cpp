#include <iostream>
using namespace std;

int main(){
   int rows, cols;
/*
   cout << "Enter a number for rows: ";
   cin >> rows;
   cout << "Enter a  number for cols: ";
   cin >> cols;
   int array[rows][cols];
   for (int x = 0; x < rows; x++){
      for(int y = 0; y < cols; y++){
	 array[x][y] = x + y + 1;
      } 
   }*/ 


int** array;
array = new int*[rows];
for( int i = 0; i< rows; i++){
  array[i] = new int [cols];

}


for(int x  = 0; x < rows; x++){
  for (int y = 0; y< cols; y++){
     array[x][y] = 0;
  } 
 cout << endl; 
}
for(int x  = 0; x < rows; x++){
  for (int y = 0; y< cols; y++){
  cout << array[x][y];
  } 
  cout << endl;
} 
}

