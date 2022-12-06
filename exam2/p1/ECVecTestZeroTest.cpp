#include <vector>
#include <iostream>
using namespace std;

#include "ECVecTestZero.cpp"


// test if vec[pos] == 0

int main()
{
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(0);
  vec.push_back(3);
  if( ECVecTestZero(vec, 0) == false)
  {
    cout << "Pass\n";
  }
  else
  {
    cout << "Fail\n";
  }
  if( ECVecTestZero(vec, 2) == true)
  {
    cout << "Pass\n";
  }
  else
  {
    cout << "Fail\n";
  }
}

