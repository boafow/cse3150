#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// determine if strInput contains strPattern as a substring
bool IsSubString( const std::vector<char> &strInput, const std::vector<char> &strPattern )   
{
    // your code goes here
    if(strPattern.size()==0){
        return false;
    }
    if(strInput.size()==0){
        return false;
    }
    int k = 0;
    for(int i = 0; i<strInput.size(); ++i){
        for(int j = 0; j<strPattern.size(); ++j){
            if(strPattern[j] == strInput[i]){
                k++;
            }
        }
    }
    if(k == strPattern.size()){
        return true;
    }
    return false;
    

}

int main()
{
  // TEST CASE?
}
