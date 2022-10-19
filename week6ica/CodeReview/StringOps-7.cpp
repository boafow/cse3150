#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// determine if strInput contains strPattern as a substring
bool IsSubString( const std::vector<char> &strInput, const std::vector<char> &strPattern )   
{
    if(strInput.size() == 0 || strPattern.size()==0 || strInput.size() < strPattern.size())
        return false;
    string str(strInput.begin(),strInput.end());
    string str1(strPattern.begin(),strPattern.end());
    if (str.find(str1))
    {
        return false;
    }
    return true;
}

int main()
{
  // TEST CASE?
}
