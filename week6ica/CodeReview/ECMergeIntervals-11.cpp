#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals) {
  vector<pair<int, int> > sortVec;
  for(int i = 0; i < listIntervals.size(); i++) {
    sortVec.push_back(listIntervals[i]);
  }
  sort(sortVec.begin(), sortVec.end());

  int newFirst;
  int newSecond;
  for(int i = 0; i < sortVec.size() - 1; i++) {
    if(sortVec[i].second >= sortVec[i + 1].first) {
      newFirst = sortVec[i].first;
      newSecond = sortVec[i + 1].second;
      pair<int, int> pr (newFirst, newSecond);
      listNonOverlapIntervals.push_back(pr);
      newFirst = sortVec[i + 2].first;
    }
    else {
      newFirst = sortVec[i + 1].first;
      newSecond = sortVec[i + 1].second;
      pair<int, int> pr (newFirst, newSecond);
      listNonOverlapIntervals.push_back(pr);
    }
  }
}

//#if 0 
int main() {
  pair<int, int> p1 (1, 3);
  pair<int, int> p2 (2, 6);
  pair<int, int> p3 (8, 10);
  pair<int, int> p4 (15, 18);

  vector<pair<int, int> > v1;
  v1.push_back(p1);
  v1.push_back(p2);
  v1.push_back(p3);
  v1.push_back(p4);

  vector<pair<int, int> > res1;

  ECMergeIntervals(v1, res1);

  cout << "First test case: ";
  for(vector<pair<int, int> >::iterator itr = res1.begin(); itr != res1.end(); itr++) {
    cout << "[" << (*itr).first << ", " << (*itr).second << "]";
  }

  cout << endl;

    // MORE TEST CASES? 

#if 0
  pair<int, int> p5 (1, 4);
  pair<int, int> p6 (4, 5);
  vector<pair<int, int> > v2;
  v2.push_back(p5);
  v2.push_back(p6);

  vector<pair<int, int> > res2;

  ECMergeIntervals(v2, res2);

  cout << "Second test case: ";
  for(vector<pair<int, int> >::iterator itr = res2.begin(); itr != res2.end(); itr++) {
    cout << "[" << (*itr).first << ", " << (*itr).second << "]";
  }
  
  cout << endl;

  pair<int, int> p7 (1, 32);
  pair<int, int> p8 (19, 21);
  pair<int, int> p9 (13, 1011);
  pair<int, int> p10 (12, 1869);

  vector<pair<int, int> > v3;
  v3.push_back(p7);
  v3.push_back(p8);
  v3.push_back(p9);
  v3.push_back(p10);

  vector<pair<int, int> > res3;

  ECMergeIntervals(v3, res3);

  cout << "Third test case: ";
  for(vector<pair<int, int> >::iterator itr = res3.begin(); itr != res3.end(); itr++) {
    cout << "[" << (*itr).first << ", " << (*itr).second << "]";
  }

  cout << endl;
#endif
}

