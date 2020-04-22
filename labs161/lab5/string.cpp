#include <iostream>
#include <string>
using namespace std;
void get_sentence(string &s); 
int main(){
	string sentence;
	get_sentence(sentence);  
	cout << sentence  << endl;
	return 0;
}

void  get_sentence(string &s){
	cout << "Enter a word or sentence"<< endl;
	cin >> s;
} 

