#include <vector>

bool IsNonDecreasing(std::vector<int> &vec)
{
	if(vec.size() == 0) return false;
	for(int i = 0; i < vec.size()-1; ++i){
		if(vec[i] > vec[i + 1]) return false;
	}
	return true;


}
