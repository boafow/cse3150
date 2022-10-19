#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compareInterval(pair<int, int> v1, pair<int, int> v2){
	return (v1.first < v2.first);
}

bool overlaps(pair<int, int> p1, pair<int,int> p2){
	return ((p1.second >= p2.first) || (p1.second >= p2.second));
}

void ECMergeIntervals(const vector<pair<int,int>> &listIntervals, vector<pair<int,int>> &listNonOverlapIntervals){
	vector<pair<int, int>> v;

	for(auto element : listIntervals){
		v.push_back(element);
	}

	sort(v.begin(), v.end(), compareInterval);

	listNonOverlapIntervals.push_back(v[0]);

	for(int i = 1; i < v.size(); i++){
		pair<int, int> top = listNonOverlapIntervals.back();
		
		if(overlaps(top, v[i])){
			if(top.second >= v[i].second){
				//collapse and push
				pair<int, int> collapsed {top.first, top.second};
				listNonOverlapIntervals.pop_back();
				listNonOverlapIntervals.push_back(collapsed);
			} else if(top.second >= v[i].first){
				// Merge and push
				pair<int, int> merged {top.first, v[i].second};
				listNonOverlapIntervals.pop_back(); //Remove top
				listNonOverlapIntervals.push_back(merged); //Next top is merged
			}
		} else {
			listNonOverlapIntervals.push_back(v[i]);
		}
	}
}
/*
int main() {
	// top: 5, 10
	// v[i]: 8, 10
	// listNonOverlap: (1,4) , (5,11) 
	vector<pair<int, int>> vecIn {{1,4}, {4,5}};
	vector<pair<int, int>> vecOut;
	
	ECMergeIntervals(vecIn, vecOut);
	for(auto p : vecOut){
		cout << "Pair: " << p.first << ", " << p.second << endl;
	}
	return 0;
}*/
