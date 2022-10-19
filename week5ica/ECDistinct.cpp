#include <vector>
#include <map>
#include <iostream>
using namespace std;

void ECCountDistinct(const vector<int> &listNums, map<int,int> &mapDistinct)
{
  mapDistinct.clear();
  for(auto n : listNums){	 //For each element in listNums
	if(mapDistinct.find(n) == mapDistinct.end()) { 	 //If first occurrence
		mapDistinct.insert(pair<int, int>(n, 1)); //Insert into map with frequency 1
	} else {
		mapDistinct[n] += 1;			 //n already appears in map, increase frequency
	}
  }
}
/*
int main()
{
  const int arr[] = {1,3,5,3,3,5,2,3,1};
  vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  map<int,int> mapDist;

  ECCountDistinct(vec, mapDist);

  //ASSERT_EQ( mapDist.size(), 4);
  cout << "size of mapDist: " << mapDist.size() << ": " << mapDist[1] << " " << mapDist[2] << " ";
  cout << mapDist[3] << " " << mapDist[5] << endl;
  //ASSERT_EQ( mapDist[1], 2);
  //ASSERT_EQ( mapDist[2], 1);
  //ASSERT_EQ( mapDist[3], 4);
  //ASSERT_EQ( mapDist[5], 2);
}*/
