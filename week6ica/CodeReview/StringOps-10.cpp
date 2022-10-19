#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// find duplicate (i.e. appearing at least twice) characters in string
void GetDuplicateChars(const std::vector<char> &strInput, std::set<char> &setDupChars)
{
    // your code goes here
    std::vector<char> temp;
    for(int i = 0; i < strInput.size(); i++) temp.push_back(strInput[i]);
    sort(temp.begin(), temp.end());
    for(int i = 0; i < strInput.size() - 1; i++){
        if(temp[i] == temp[i+1])
            setDupChars.insert(temp[i]);
    }
}

int main()
{
  // WHAT TEST CASE?
}
