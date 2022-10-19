//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    	for(int i = 0; i < arrayPtrs.size()-1; i++){
		for(int j = 1; j < arrayPtrs.size(); j++){
			if(*arrayPtrs[j] == *arrayPtrs[i]){
				arrayPtrs.erase(arrayPtrs.begin()+j);
				j--;
			}
		}
	}
}
/*
int main(){
	string s1 = "abc";
	string s2 = "bcd";
	string s3 = "abc";
	  
	vector<string *> strVec{&s1, &s2, &s3, &s1};
	RemoveDupPointers(strVec);
	for(int i = 0; i < strVec.size(); i++){
		cout << *strVec[i] << " ";
	}
	cout << endl;
	return 0;
}*/
