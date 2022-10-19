#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

bool ECCheckDuplicates(const vector<int> &listNumbers)
{
	vector<int> v;
	for(auto element : listNumbers) {
		v.push_back(element);
	}
       	sort(v.begin(), v.end());
	return (unique(v.begin(), v.end()) != v.end());
}
/*
int main() {
	vector<int> vec {1,2,3,3,4,3,2,4,2};
	vector<int> vec2 {1,2,3,4,5};
	vector<int> vec3 {};
	vector<int> vec4 {1};

	cout << ECCheckDuplicates(vec) << endl;
	cout << ECCheckDuplicates(vec2) << endl;
	cout << ECCheckDuplicates(vec3) << endl;
	cout << ECCheckDuplicates(vec4) << endl;


	return 0;
}
*/
