#include "ECClass.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class for class
ECClass :: ECClass()
{
}

void ECClass :: AddStudent( const ECStudent &s)
{
  listStu.push_back(s);
}

double ECClass :: GetAveMedian() const{
	if (listStu.size() == 0) return 0.0;
	vector<double> list;
	for(auto s : listStu){
		list.push_back(s.GetAve());
	}
	std::sort(list.begin(), list.end());
	return list[list.size()/2];
}

std::string ECClass :: GetRankedStudentName(int n) const{
	if(listStu.size() <= n) throw "No Students";
	vector<pair<double, string>> list;
	for( auto s : listStu) {
		pair<double, string> pp(s.GetAve(), s.GetName());
		list.push_back(pp);
	}
	std::sort(list.begin(), list.end());
	return list[list.size() - 1 - n].second;

}

