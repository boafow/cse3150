#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  // your code goes here ...
	int sum = 0; 
	for(int n : listNums) {
		sum += n;	
       	}
	return sum;
}
/*
int main()
{
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(1);
  vector<int> vecOdds;
  int sum = ECSumList(vec, vecOdds);
  cout << "sum: " << sum << endl;
}*/
