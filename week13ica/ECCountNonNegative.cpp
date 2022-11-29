#include <vector>
#include <algorithm>
using namespace std;

// count and return the number of integers in vec that are non-negative
int ECCountNonNegatives(const std::vector<int> &vec)
{
	int count = 0;
	std::for_each(vec.begin(), vec.end(), [&count](int n){ if(n>=0) count+=1; });
	return count;

	//int count = 0;
	//for_each(vec.begin(), vec.end(), [&](int n){ if(n >= 0){count +=1} ;});
	//return count;
}
