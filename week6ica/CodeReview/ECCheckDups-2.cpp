// Check whether the given integer list has duplicates or not
// Return true if there is duplicate, false otherwise
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool ECCheckDuplicates(const std::vector<int> &listNumbers)
{
    if(listNumbers.empty()){
        return false;
    }
  vector<int> vect;
  copy(listNumbers.begin(), listNumbers.end(), back_inserter(vect));
  int current = vect[0];
  for(int i = 1; i < vect.size(); i++){
    if(current != vect[i]){
      current = vect[i];
    }
    else{
      return true;
    }
  }
  return false;
}

int main()
{
	vector<int> vec1 {1, 2, 3, 4, 5};
	vector<int> vec2 {1, 2, 1, 1, 1};
	vector<int> vec3 {5, 5, 4, 3, 2};
	vector<int> vec4 {1};

	cout << ECCheckDuplicates(vec1) << endl;
	cout << ECCheckDuplicates(vec2) << endl;
	cout << ECCheckDuplicates(vec3) << endl;
	cout << ECCheckDuplicates(vec4) << endl;


}

