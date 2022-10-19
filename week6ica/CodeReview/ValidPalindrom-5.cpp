//
//  ValidPalindrome.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

// Function to test if the input string is a valid palindrome
// Note: only consider alphanumeric symbols and ignore cases
bool IsValidPalindrome(const string &strInput)
{
    // your code go here ...
    int x = 0;
    int len = strInput.length() - 1;
    string str;
    for(unsigned int i = 0; i < strInput.size(); i++)
    {
        str += strInput[i];
    }

    for (int i = 0; i <= len; i++)
    {
        str[i] = tolower(str[i]);
    }
    while (x <= len)
    {
        if (!(str[x] >= 'a' && str[x] <= 'z'))
        {
            x++;
        }
        else if (!(str[len] >= 'a' && str[len] <= 'z'))
        {
            len--;
        }
        else if (str[x] == str[len])
        {
            x++;
            len--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
  // TEST CASE? 
}
