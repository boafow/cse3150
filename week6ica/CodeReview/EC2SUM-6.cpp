// YW: I modify the student' code by using C++ standard library
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void EC2SUM( const int listNumbers[], int sizeNumbers, const int listTargets[], int szTargets, bool list2SUMRes[] )
{
  // for each number x = listTargets[i], if there are two numbers 
  // in listNumbers that add up to x, then list2SUMres[i]=true 
  // otherwise, list2SUMRes[i]=false

  // YW: I used vector here
  //int* sorted_list_numbers = const_cast<int*>(listNumbers);
  //ECSort(sorted_list_numbers, sizeNumbers);
  vector<int> sorted_list_numbers;
  for(int i=0; i<sizeNumbers; ++i)
  {
    sorted_list_numbers.push_back( listNumbers[i] );
  }
  std::sort(sorted_list_numbers.begin(), sorted_list_numbers.end());

  for(int i = 0; i < szTargets; ++i)
  {
    int x = listTargets[i];
    for(int j = 0; j < sizeNumbers; ++j)
    {
      int val = listNumbers[j] - x;
      //if(ECBinarySearch(sorted_list_numbers, sizeNumbers, val) != -1)
      if(std::binary_search(sorted_list_numbers.begin(), sorted_list_numbers.end(), val) )
      {
        list2SUMRes[i] = true;
        break;
      }
    }
    list2SUMRes[i] = false;
  }
}

int main()
{
  // TEST CASE?
}
