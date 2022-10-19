//
//  ValidPalindrome.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

// Function to test if the input string is a valid palindrome
// Note: only consider alphanumeric symbols and ignore cases
bool IsValidPalindrome(const string &strInput)
{
    if(strInput == ""){
	    return true;
    }
    // your code go here ...
    string postStr = "";
    for(int i = 0; i < strInput.length(); i++){
	if(isalnum(strInput[i])){
		postStr += tolower(strInput[i]);
		}
	}
    if(postStr.length() == 1){
	    return true;
    }
    int i = 0;
    int j = (postStr.length()-1);
    while(true){
	if(postStr[i] == postStr[j]){
		i++;
		j--;
	} else {
		return false;
	}
	if(j==0){
		return true;
		}
    }
    return false;
}
/*
int main(){
	cout << "enter a string: ";
	string palindromeTest;
	getline(cin, palindromeTest);
	cout << IsValidPalindrome(palindromeTest) << endl;
	return 0;
}
*/
