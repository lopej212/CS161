/***********************************************************************************
 * Program Filanme: Encrypt
 * Author: Jose Manuel Lopez Alcala
 * Date: May 20, 2016
 * Description: Takes any phrase in English and converts it into morse and then back
 * Input: User input. A phrase in English
 * Output: The morse equivalent
 * *********************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
void upperCase(char message[]);
void encrypt(char message[],char code[]);
void keyword(char keyphrase[]);
void duplicateRemove(char keyphrase[]);
void newAlphabet(char keyphrase[], char newAlpha[] );
void encrypt2(char newAlphabet[], char message[],char cipher[]);
void decrypt(char cipher[],char newAlphabet[],char morse2[]);
void decrypt2(char morse2[]);
/***********************************************************************************
 * Function: This is the main function 
 * Description: This is the drinving function for the whole program
 * Paramenters:It doesn't take any parameters
 * Pre-condition:none
 * Post-condition: none
 * ********************************************************************************/
int main(){
   char message[500];
   char code[200] = "";
   char cipher[100]= "";
   char morse2[100]="";
   cout << "Enter message to encrypt: " << endl;
   cin.getline(message,500);
   upperCase(message);
   encrypt(message,code);
   //cout << code << endl;//for testing 
   char keyphrase[100];
   char newAlpha[27]="";
   cout << "Enter keyphrase: " << endl;
   cin.getline(keyphrase,100);
   duplicateRemove(keyphrase);
   newAlphabet(keyphrase,newAlpha);
   //cout << newAlpha << endl;//for testing
   encrypt2( newAlpha, code,cipher);
   //cout << cipher << endl;//for testing
   decrypt(cipher,newAlpha,morse2);
   //cout << morse2 << endl;//for testing 
   decrypt2(morse2);


return 0;

}
/***********************************************************************************
 * Function:Uppercase() 
 * Description:This function will turn any lowercase letter in a  string into a uppercase letter
 * Paramenters: The messsage being converted to uppercase
 * Pre-condition:Message can be upper or lower case 
 * Post-condition: Message is return in upper case letters
 * ********************************************************************************/
void upperCase(char message[]){
   for( int i = 0 ; i < strlen(message); i++){
      message[i] = toupper(message[i]);
   }
}
//This function works       
void encrypt(char message[],char code[]){
   //cout << "Code: " << code << endl;// for testing 
   char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char morse[][5] = {"*-","-***","-*-*","-**","*",
      "**-*","--*","****","**","*---",
      "-*-","*-**","--","-*","---",
      "*--*","--*-","*-*","***","-",
      "**-","***-","*--","-**-","-*--","--*"};
   //cout << "Message length: " << strlen(message) << endl;//for testing 
   for(int i =0; i < strlen(message); i++){
      for(int j = 0; j < 26; j ++){
	 if(message[i] == alpha[j]){
	   //cout << "This is message letter at index i: " << message[i] << endl;//for testing
	    //cout << "This is the current alpha letter being checked: " << alpha[j] << endl;//for testing 
	    strcat(code,morse[j]);
	   strcat(code,"X");
	 }
      }
      if(message[i] == char(32)){
	 strcat(code,"X");
      }
   }
   strcat(code,"X");
  // cout << code << endl;
}
/***********************************************************************************
 * Function: DuplicateRemove()
 * Description:Taskes any phrase and takes out any duplicate elements in the string
 * Parameters:Phrase used for conversion
 * Pre-condition:none
 * Post-condition:returns string without any duplicate leters
 * ********************************************************************************/
void duplicateRemove(char keyphrase[]){
   int size = strlen(keyphrase);
   upperCase(keyphrase);

   for(int i = 0; i < size; i++){
      for(int j = i + 1; j < size;){
	 if(keyphrase[j] == keyphrase[i]){
	    for(int k = j; k < size; k++){
	       //strcpy(newMessage,&keyphrase[k+1]);//testing
	       keyphrase[k] = keyphrase[k+1];
	    }
	    size--;
	 }else
	    j++;
      }
   
   }
   //cout << keyphrase << endl;//for tesing 
}

/***********************************************************************************
 * Function:newAlphabet()
 * Description:Takes the keyphrase and the original alphabet and then combines them to make the second look up table for the encrytionn
 * Parameters:keyphrase and newalphabet
 * Pre-condition:the key phraes must be in all uppercase
 * Post-condition:makes it so that the new alphbet has the keyphras and the rest of the alphabet with out any duplicates
 * *******************************************************************************/
void newAlphabet(char keyphrase[], char newAlpha[] ){
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  strcat(newAlpha,keyphrase);
 //cout << newAlpha << endl;//for testing 
  strcat(newAlpha,alpha);
     //cout << newAlpha << endl;//for testing 
  duplicateRemove(newAlpha);
// cout << newAlpha << endl;//for testing 

}

/***********************************************************************************
 * Function:encrupt() 
 * Description:This function will take the message and create the cipher text 
 * Parameters:the new alphabet, the morse code and the cipher 
 * Pre-condition: alphabet and morse must be in upper case 
 * Post-condition:this will modify the cipher string so that it has all hte cipher text within it.
 **********************************************************************************/
void encrypt2(char newAlphabet[], char message[],char cipher[]){
   int size1 = (strlen(message)/3) + 1 ;
   int size2 = strlen(message);
   char fract[100][4] ={""};
   char newMorse [][4] ={"***","**-","**X","*-*","*--",
      "*-X","*X*","*X-","*XX","-**",
      "-*-","-*X","--*","---","--X",
      "-X*","-X-","-XX","X**","X*-",
      "X*X","X-*","X--","X-X","XX*","XX-"};
   int x =0;   
   for(int i = 0; i < size2; i+=3 ){
	 for(int k = 0; k < 3;k++){
	   strncat( fract[x], &message[i+k],1);
	 }
	 x++;
      }

   //test
   /*
   for(int i = 0; i < size1; i++){
	//cout << fract[i] << endl;
   }*/
   
for(int i = 0 ; i < size1; i++){
   if ( i > 0 && i% 5 == 0) cout << "  "; 
   for(int k = 0; k < 26; k++){
      if(strncmp(fract[i],newMorse[k],3) == 0 ){
	 cout << newAlphabet[k];
	 strncat(cipher, &newAlphabet[k],1);
      }
   }
}
cout << endl;
}

/***********************************************************************************
 * Function: decrypt()
 * Description:This function will take care of the first part of the decoding.It will the morse code frst that that another function will take care of of decoding the mores to englsih 
 * Parameters:cipher text, the new alphabet  and the morse code
 * Pre-condition:all must be in upper case 
 * Post-condition:
 **********************************************************************************/
void decrypt(char cipher[],char newAlphabet[],char morse2[]){
  char newMorse [][4] ={"***","**-","**X","*-*","*--",
      "*-X","*X*","*X-","*XX","-**",
      "-*-","-*X","--*","---","--X",
      "-X*","-X-","-XX","X**","X*-",
      "X*X","X-*","X--","X-X","XX*","XX-"}; 
  int size  = strlen(cipher);
  for(int i = 0; i < size; i++){
     for(int k = 0; k < 26; k++){
	if(strncmp(&cipher[i],&newAlphabet[k],1) ==0){
	   strcat(morse2,newMorse[k]);
	}
     }
  }
 // cout << morse2 << endl;//test
}

/***********************************************************************************
 * Function: decrypt2()
 * Description:This function will take care of the second part of the decoding. This fuction taks the morse code and then turns into englsih so that the user can see the translation
 * Parameters:morse code 
 * Pre-condition:none
 * Post-condition: prints the english version of the code back to the user
 **********************************************************************************/
void decrypt2(char morse2[]){
   int size = strlen(morse2);
   char fract2[100][5]={""};
   char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char morse[][5] = {"*-","-***","-*-*","-**","*",
      "**-*","--*","****","**","*---",
      "-*-","*-**","--","-*","---",
      "*--*","--*-","*-*","***","-",
      "**-","***-","*--","-**-","-*--","--*"};
   int x = 0;
   for(int i = 0; i < size; i++){
      if(morse2[i] == char(88)){
	 x++;
      }else{
	 strncat(fract2[x],&morse2[i],1);
      }
   }
   int size2 = strlen(morse2)/4 +1;/*
   for(int i = 0 ; i < size2 ; i++){
      cout << fract2[i] << endl;
   }*/
   for(int i = 0; i < size2; i++){
      for(int k = 0; k < 26; k++){
	 if(strncmp(fract2[i],morse[k],4)==0){
	       cout << alpha[k];
	 }
      }cout << " ";
   }
   cout << endl;
}

