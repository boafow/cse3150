#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// determine if strInput contains strPattern as a substring
bool IsSubString( const std::vector<char> &strInput, const std::vector<char> &strPattern )   
{
    // your code goes here
    vector<char> cur;
    for(int i = 0; i <= strInput.size() - strPattern.size(); i++){
        cur.clear();
        for(int j = i; j < strPattern.size(); j++){
            cur.push_back(strInput[j]);
        }
        if(cur == strPattern) return true;
    }
    return false;
}


int main()
{
  // TEST CASE?
}
