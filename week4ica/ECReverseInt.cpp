//
//  ECReverseInt.cpp
//  
//
//  Created by Yufeng Wu on 11/13/19.
//  Reverse an integer. Assume unsigned.
//

#include <iostream>
#include <sstream>
using namespace std;

// Reverse an integer (stored in decimal format in a string)
string ECReverseInt(const string &strNumber)
{
	string res;
	int res_int;
	for(int i = strNumber.size()-1; i >= 0; --i){
		res += strNumber[i];
	}

	res_int = stoi(res);
	return to_string(res_int);
}
/*
int main() {
	cout << ECReverseInt("2022") << endl;
	//cout << ECReverseInt("") << endl;
	cout << ECReverseInt("10") << endl;
	cout << ECReverseInt("1") << endl;
 } */
