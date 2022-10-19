// Starter code
#include <string>
#include <iostream>
using namespace std;

string ECSwapCase(string str)
{
  string res;
  for(unsigned int i = 0; i < str.length(); ++i)
  {
	char ch = str[i];
	if(isalpha(ch)) {
	if(isupper(ch)){
		res += tolower(ch);
	} else {
		res += toupper(ch);
	       	}
	} else {
		res += ch;
	}
  }
	return res;
}
/*
int main()
{
  string str1("Abcd");
  cout << ECSwapCase(str1) << endl;
  string str2("Cse 3150");
  cout << ECSwapCase(str2) << endl;
  return 0;
}
*/
