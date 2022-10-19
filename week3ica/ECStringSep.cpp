// Starter code
#include <iostream>

using namespace std;

string foo(const string &str)
{
  string res;
  // your code goes here
	for(unsigned int i = 0; i < str.length(); i++){
		res += str[i];
		if(i != (str.length()-1)){
			res += ',';
		}
	}
  return res;
}
/*
int main()
{
  string str1 = "abc";
  cout << foo(str1) << endl;
  string str2 = "CSE3150";
  cout << foo(str2) << endl;
  string str3;
  cout << foo(str3) << endl;
  return 0;
}*/
