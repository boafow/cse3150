#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool ECConsecutiveVec(vector<int>& vec)
{
	if(vec.size() < 2) return false;
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size()-1; ++i){
		if(pow(vec[i]-vec[i+1], 2) != 1) return false;
	}
	return true;
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
