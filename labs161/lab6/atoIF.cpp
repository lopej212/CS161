#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main( int argc, char *argv[]){
  char conver[1];
 char user_input[50];
strcpy(user_input,argv[2]);
strcpy(conver,argv[1]);

int option = atoi(conver);

if(option == 1){
  int k = atoi(user_input);
   cout << k << endl;
}
else if(option == 2){
   double d = atof(user_input);
  cout << d << endl;
}
return 0;
}

