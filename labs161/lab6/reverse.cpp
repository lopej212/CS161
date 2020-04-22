#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]){
   char s[100];
   strcpy(s, argv[1]);
   int temp;
   int  count = strlen(s); 
   for(int i = 0; i < count/2; ++i)
   {
    temp = s[i];
  s[i] = s[count-i-1];
s[count-i-1] = temp;
   }

   cout << s << endl;
}
