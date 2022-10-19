#include <iostream>
using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...
  string ref = arrayStrings[0];
  int ref_len = ref.length();
  string longest = "";

  //start pointer
  for(int i=1; i<ref_len + 1; ++i)
  {
    //end pointer
    string sub = ref.substr(0, i);
    //for each string
    for (int f = 0; f < numStrings; f++) {
      if (arrayStrings[f].substr(0, i) != sub) {
	return longest;
      }
    }
    longest = sub;
  }
  return longest;
}

