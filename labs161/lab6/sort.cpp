#include <iostream>
using namespace std;

void sort1( int array_1[],  int array_2[], int array_3[]);
void print(int array_3[]); 
int main(){
   int array_1[5]={};
   int array_2[5]={};
   int array_3[10]={};
   cout << "Enter elements of array 1: "<< endl;
  for(int i = 0; i <=4 ; i++){
     cin >> array_1[i];
  }
 cout<< "Enter elements of array 2: " << endl; 
  for (int q = 0; q<=4; q++){
     cin >> array_2[q];
  }

 
cout << "Array with both arrays together: ";
for (int k = 0; k<=4; k++){
  array_3[k] = array_1[k];
}
for(int k = 5; k<=9; k++){
  array_3[k] = array_2[k-5];
}
for(int a = 0; a<=9; a++){
 // cout << array_3[a];
} 
sort1(array_1,array_2,array_3);
print(array_3); 
return 0;
}

void sort1( int a_1[5],  int a_2[5], int array_3[]){
 
int location=0;
for(int i = 1; i < 10; i ++){
  for(int k = 0; k < 9; k++){
   if(array_3[k] > array_3[i]){
   location = array_3[i];
   array_3[i] = array_3[k];
   array_3[k] = location;
   }
  }
}
}
  
void print( int array_3[]){
for(int i =0; i <=9; i++){
cout << array_3[i];
}
}
