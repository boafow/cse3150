#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool ECFind(const set<int> &listNums, int x)
{/*
	for(auto n : listNums){
		if(n == x) return true;
	}
	return false;
	*/
	return listNums.find(x) != listNums.end();
}
/*
int main()
{
  // create a list of certain size
  const int NUM_INTS = 10000;
  set<int> ss;
  for(int i=0; i<NUM_INTS; ++i)
  {
    ss.insert(i);
  }
  const int NUM_FIND = 1000000;
  for(int i=0; i<NUM_FIND; ++i)
  {
    ECFind(ss,i);
  } 
}
*/
