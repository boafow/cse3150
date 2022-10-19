#include "ECLongestPrefix.h" 
#include <iostream>
#include <string>
using namespace std;

// Implement the longest prefix function here...
string prefixHelper(string str1, string str2){
	string res = "";
	int len = min(str1.length(), str2.length());
	for(int i = 0; i < len; i++){
		if(str1[i] != str2[i]){
			break;
		}
		res += str1[i];
	}
	return (res);
}

string ECLongestPrefix(int numStrings, string arrayStrings[])
{
  string prefix = arrayStrings[0];
  for(int i = 1; i < numStrings; i++){
	prefix = prefixHelper(prefix, arrayStrings[i]);
  } 
  return (prefix);
}
