#include <iostream>
using namespace std;
extern string ECLongestPrefix(int numStrings, const string arrayStrings[]);

void Test()
{
  string str1 = "abcde";
  string str2 = "abxyzabcde";
  string str3 = "xabxyzabcde";
  string arrStrs[] = {str3, str1};
  string strPref = ECLongestPrefix(2, arrStrs);
  cout << "Common prefix: " << strPref << endl;
}

int main()
{
  Test();
}

