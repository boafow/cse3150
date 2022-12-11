#include <vector>
using namespace std;

// test if vec[pos] == 0
bool ECVecTestZero(vector<int>& vec, int pos)
{
	if(vec[pos] == 0) return true;
	if(pos > vec.size()) return false;
}

