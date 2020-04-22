#include <iostream> 
using namespace std;
void convert( int x, int b); 
int main(){
   convert(6,8);
  return 0; 
}

void convert(int x , int b){
   if(x/b != 0){
      convert((x/b),b);
   }
   else if (x % b < 10){
 	cout << x % b << endl;
   }
   else if (x  % b == 10){
  	cout << " A " << endl;
   }
   else if (x % b == 11){
  	cout << " B " << endl;
   }
   else if (x % b == 12){
   	cout << " C " << endl;
   }
   else if(x % b == 13){
  	cout << " D "<< endl;
   }
   else if (x %b == 14){
   	cout << " E " << endl;
   }
   else if (x % b == 15){
   	cout << " F " << endl;
   }
}


