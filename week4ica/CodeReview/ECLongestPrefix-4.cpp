#include <iostream>
using namespace std;

// helper to find prefix of 2 strings
string PrefixHelp(const string str1, const string str2)
{
  string output;
  if (str1.length() < str2.length())
  {
    for (int i = 0; str1.length(); i++)
    {
      if (str1[i] != str2[i])
      {
        return output;
      }
      else
      {
        output += str1[i];
      }
    }
    return output;
  }
  else
  {
    for (int i = 0; str2.length(); i++)
    {
      if (str1[i] != str2[i])
      {
        return output;
      }
      else
      {
        output += str1[i];
      }
    }
    return output;
  }
}

// Implement the longest prefix function here...
// Compare the strings with the most difference possible in order to see what (if any) prefix they have;
// this way, all other strings (with smaller differences) will be accounted for
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  string a_string = arrayStrings[0];
  string z_string = arrayStrings[0];

  // find the string closest to the beginning ("a-end") of the alphabet
  for (int i = 0; i < numStrings; i++)
  {
    if (arrayStrings[i] < a_string)
    {
      a_string = arrayStrings[i];
    }
  }
  // find the string closest to the end ("z-end") of the alphabet
  for (int i = 0; i < numStrings; i++)
  {
    if (arrayStrings[i] > z_string)
    {
      z_string = arrayStrings[i];
    }
  }

  // find prefix of these two strings
  string the_prefix = PrefixHelp(a_string, z_string);
  return the_prefix;
}

