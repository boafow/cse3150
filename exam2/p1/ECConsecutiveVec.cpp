#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool ECConsecutiveVec(.... )
{
  // your code ehre
}

// test
int main()
{
  vector<int> vec;
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(4);
  // this should be consectutive
  if( ECConsecutiveVec(vec) )
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT consecutive\n";
  }
  vec.push_back(1);
  // this should be NOT consectutive
  if( ECConsecutiveVec(vec) )
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT consecutive\n";
  }
}
