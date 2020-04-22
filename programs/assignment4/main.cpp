/***********************************************************
 ** Program Filename: Hangman
 ** Author: Jose Manuel Lopez Alcala
 ** Date: 5/6/2016
 ** Description: Hangman Game
 **********************************************************/

#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
/*************************************************************
These are all the following functions that will be used
 ************************************************************/
int difficulty();
string phrase_andcheck();
string get_phrase();
bool acceptable_phrase(string &p);
void display_dashed(string w, string &dashed_word);
void letters_guessed(string guess, string &all_guesses);
void gues_letterCompare(string guess, string w, string &hidden, int &total_letters, int &currentMiss);
void play(string &dashedmessage, string originalWord, int misses);
void dashedMessage_print(string dashed);
void misSix_1();
void misSix_2();
void misSix_3();
void misSix_4();
void misSix_5();
void misSix_6();
void misEleven_1();
void misEleven_2();
void misEleven_3();
void misEleven_4();
void misEleven_5();
void misEleven_6();
void misEleven_7();
void misEleven_8();
void misEleven_9();
void misEleven_10();
void misEleven_11();
void hang_six(int misses);
void hang_eleven(int misses);
void hallows(int mode, int currentMiss);

/*************************************************
 ** Function: Main Function
 ** Parameters:None
 ** Pre-Conditions: None
 ** Post Condition: None
 ************************************************/
int main(){
    cout << "Welcome to Hangman" << endl;
    int misses =difficulty();
    string word = get_phrase();
    system("clear");
    string dashed_word = "";
    display_dashed(word, dashed_word);
    //system("clear");
    play(dashed_word, word, misses);
    
    return 0;
}


/*************************************************
 ** Function: difficulty()
 ** Description: Gets the difficulty on which the player
 ** wants to play
 ** Parameters: None
 ** Pre-Conditions: Needs to be called by main
 ** Post Condition: Returns the difficulty
 ************************************************/
int difficulty(){
    int setting = 0;
    cout << "Mode: \n(0)Hard \n(1)Easy" << endl;
    cin >> setting;
    if(setting == 0){
        setting = 6;
    }else if (setting == 1){
        setting = 11;
    }
    return setting;
}

/*get phrase and check
string phrase_andcheck(){
    string phrase;
    do {
        phrase = get_phrase();
    } while (acceptable_phrase(phrase)==false);
    return phrase;
}*/
//get phrase from user function and set lowercase
/*************************************************
 ** Function:get_phrase()
 ** Description: Gets the phrase from the user
 ** Parameters:None
 ** Pre-Conditions:Needs to be called by main
 ** Post Condition:Returns the input from the user to main
 ************************************************/
string get_phrase(){
    string phrase;
    cin.ignore();
    cout << "Enter a message: " << endl;
    getline(cin,phrase);
    int size = phrase.size();
    for (int k = 0; k < size; k++) {
        phrase[k] = tolower(phrase[k]);
    }
    //transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
    return phrase;
}

/*
//checks that the entered string is acceptable for the program
bool acceptable_phrase(string &p){
    bool acceptable = false;
    for (int i = 0; i < p.length(); i++) {
        if(isalpha(p[i])== true || isspace(p[i])==true){
            acceptable = true;
        }else{
            acceptable = false;
            return acceptable;
        }
    }
    return acceptable;
}*/

/*************************************************
 ** Function:displayed_dashed()
 ** Description:Changes the entered phrase from user to
 ** the console but with slashes instead of letters
 ** Parameters: string w is the input string from user,
 **             string &dashed_word is the displyed word to user
 **             in the form of slashes
 ** Pre-Conditions:string w and dashed_word must exist for function to work
 ** Post Condition:changes word to dashed word
 ************************************************/
void display_dashed(string w, string &dashed_word){
    dashed_word = w;
    for (int i =0; i < w.length(); i++) {
        /*if (isalpha(w[i])){
            dashed_word[i] = '-';
        }else if (isspace(w[i])){
            dashed_word[i] = ' ';
        }*/
        if (w[i]== ' ') {
            dashed_word[i] = ' ';
        }else{
            dashed_word[i] = '-';
        }
    }
    //cout << "The message is: " << dashed_word << endl;
}

/*************************************************
 ** Function:letters_guessed()
 ** Description: It adds the letters guess to the list of guessed letters
 ** Parameters:string guess(current guess) and string where all guesses are stored
 ** Pre-Conditions: Must be called by play()
 ** Post Condition: stores letter guesed to string of letters
 ************************************************/
void letters_guessed(string guess, string &all_guesses){
    all_guesses.append(guess);
    cout << "You have guessed: " << all_guesses << endl;
    
}

//guess letter funciton(compares to original and adds to dashed if same)
/*************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post Condition:
 ************************************************/
void gues_letterCompare(string guess, string w, string &hidden, int &total_letters, int &currentMiss){
    for (int i = 0; i< w.length(); i++) {
        if (w[i] == guess[0]) {
            total_letters++;
            hidden[i] = guess[0];
        }
    }
    if (total_letters == 0 ) {
        currentMiss ++;
    }
    cout << "There is " << total_letters << " " <<  guess << endl;
}
//prints out dashed message with the guessed letters showing
/*************************************************
 ** Function:dashedMessage_print()
 ** Description: Prints the dashed message with guessed letter showing
 ** Parameters: dashed string
 ** Pre-Conditions:string dashed must exist
 ** Post Condition:print string to console
 ************************************************/
void dashedMessage_print(string dashed){
    cout << "The message is: " << dashed << endl;
}

/*************************************************
 ** Function:play()
 ** Description:this function runs the biggest part of the program
 ** Parameters:dashedmessage, inputed string and the difficulty level
 ** Pre-Conditions: input must have been obtained, dashed string created and difficulty set
 ** Post Condition: win or lose output
 ************************************************/
void play(string &dashedmessage, string originalWord, int misses){
    string all_guesses;
    int current_misses = 0;
    do {
        string guess;
        int total_letters = 0;
        dashedMessage_print(dashedmessage);
        cout << "Guess a letter: ";
        cin >> guess;
        gues_letterCompare(guess, originalWord, dashedmessage, total_letters, current_misses);
        letters_guessed(guess,all_guesses);
        hallows(misses, current_misses);
        if (current_misses == misses) {
            cout << "You lose"<< endl;
            return;
        }
        
    } while (dashedmessage.compare(originalWord) != 0);
    cout << "You Win!" << endl;
    
    
    
    
}
///////////////////////////////////////////////////////////////////////
//This function will be handeling the difficulty and printing the hallows
/*************************************************
 ** Function:Hallows()
 ** Description:This function will be handeling the
 **             difficuly and printing of the hallows
 ** Parameters:difficulty and current number of misses
 ** Pre-Conditions:difficuly must be set and current misses must exist
 ** Post Condition: printing of hallows
 ************************************************/
void hallows(int mode, int currentMiss){
    if (mode == 6) {
        hang_six(currentMiss);
    }else if (mode == 11){
        hang_eleven(currentMiss);
    }
}


/////////////////////////////////////////////////////////////////////////
//These functions will handle the displayment of the hallows for SIX ERRORS
/*************************************************
 ** Function:hang_six()
 ** Description:This function will handle the printing of the hallows 
 **             for the hard mode
 ** Parameters: number of current incorrect answers
 ** Pre-Conditions:Misses must be set
 ** Post Condition:calls one of the printing functions
 ************************************************/
void hang_six(int misses){
    if (misses == 1){
        misSix_1();
    }else if (misses == 2){
        misSix_2();
    }else if (misses == 3){
        misSix_3();
    }else if (misses == 4){
        misSix_4();
    }else if (misses == 5){
        misSix_5();
    }else if (misses == 6){
        misSix_6();
    }
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the    
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_1(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <2; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }
    cout << array2[2][0]<< "  " <<   array2[2][3] << endl;
    cout << array2[1][3] << endl;
    cout << array2[3][3] << endl;
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_2(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <2; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }for (int i = 0 ; i <=3; i++) {
        cout << array2[2][i];
    }
    cout << endl;
    cout << array2[1][3] << endl;
    cout << array2[3][3] << endl;
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_3(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <=2; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }
    cout << array2[1][3] << endl;
    cout << array2[3][3] << endl;
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_4(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <=3; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }
    cout << array2[1][3] << endl;
    cout << array2[3][3] << endl;
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_5(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <=3; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }
    cout << array2[1][0] << " " <<array2[4][2]<< endl;
}
/*************************************************
 ** Function: misSix_1() - misSix6()
 ** Description:prints the actual hallow for the
 **             number of incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_six()
 ** Post Condition: printing hallows
 ************************************************/
void misSix_6(){
    char array2[5][6] ={
        {'-','-','-','-',' ',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','_','O','_',' '},{'|',' ',' ','|',' ',' '},
        {'|',' ','/',' ','\\',' '}};
    for (int x  = 0; x <=4; x++) {
        for (int y = 0; y<=5; y++){
            cout <<array2[x][y];
        }
        cout << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
//These functions will handle the displayment of the hallows for ELEVEN ERRORS
/*************************************************
 ** Function:hang_eleven()
 ** Description:This function will handle the printing 
 **             of the hallows for the easy mode
 ** Parameters:number of incorrect guesses
 ** Pre-Conditions:misses must be set
 ** Post Condition:calles one of the printing options
 ************************************************/
void hang_eleven(int misses){
    if (misses == 1) {
        misEleven_1();
    }else if (misses == 2){
        misEleven_2();
    }else if (misses == 3){
        misEleven_3();
    }else if (misses == 4){
        misEleven_4();
    }else if (misses == 5){
        misEleven_5();
    }else if (misses == 6){
        misEleven_6();
    }else if (misses == 7){
        misEleven_7();
    }else if (misses == 8){
        misEleven_8();
    }else if (misses == 9){
        misEleven_9();
    }else if (misses == 10){
        misEleven_10();
    }else if (misses == 11){
        misEleven_11();
    }
}

/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the    
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_1(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=1; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[2][0]<< "     "  << array1[2][6] << endl;
    for (int x = 3 ; x <=7 ; x++) {
        cout << array1[x][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_2(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=1; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[2][0]<< "   " << array1[2][4]<< " " << array1[2][6] << endl;
    for (int x = 3 ; x <=7 ; x++) {
        cout << array1[x][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_3(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=1; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[2][0]<< " " << array1[2][2]<< " " << array1[2][4]<< " " << array1[2][6] << endl;
    for (int x = 3 ; x <=7 ; x++) {
        cout << array1[x][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_4(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=1; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[2][0]<< " " << array1[2][2]<< " " << array1[2][4]<< " " << array1[2][6] << " " << array1[2][8]<< endl;
    for (int x = 3 ; x <=7 ; x++) {
        cout << array1[x][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_5(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=2; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    for (int i = 3; i <=7; i++) {
        cout << array1[i][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_6(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=3; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    for (int i = 4; i <=7; i++) {
        cout << array1[i][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_7(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=4; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    
    for (int i = 6; i <=7; i++) {
        cout << array1[i][0]<< endl;
    }
    
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_8(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=4; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[5][0] << "    " << array1[5][5]<< endl;
    
    for (int i = 6; i <=7; i++) {
        cout << array1[i][0]<< endl;
    }
    
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_9(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=5; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    for (int i = 6; i <=7; i++) {
        cout << array1[i][0]<< endl;
    }
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_10(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=5; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    cout << array1[6][0] << "   " << array1[6][4]<<endl;
    cout << array1[7][0] << endl;
    
}
/*************************************************
 ** Functions: misEleven_1()- misEleven_2()
 ** Description: this will print the hallows for the
 **             correspoding incorrect answers
 ** Parameters:None
 ** Pre-Conditions:Must be called by hang_eleven
 ** Post Condition:prints hallows
 ************************************************/
void misEleven_11(){
    char array1[8][11] = {
        {'-','-','-','-','-','-','-',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ','-',' ','-',' ','O',' ','-',' ','-'},
        {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' '},{'|',' ',' ',' ',' ','/',' ','\\',' ',' ',' '},
        {'|',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
    for (int x = 0; x <=7; x++) {
        for (int y = 0; y <=10; y++) {
            cout << array1[x][y];
        }cout << endl;
    }
    
}
//////////////////////////////////////////////////////////////////////END OF PROGRAM////////////////////////////////////////////////////////////





