// Check whether the given integer list has duplicates or not
// Return true if there is duplicate, false otherwise
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool ECCheckDuplicates(const std::vector<int> &listNumbers)
{
  // WHAT IS WRONG WITH THIS SIMPLE CODE? 
  unordered_map<int, int> dict; 
  for(unsigned long i = 0; i < listNumbers.size(); i++)
    if(dict.find(listNumbers[i]) == dict.end())
      dict[i] = i;
    else return true;
  return false;
}

