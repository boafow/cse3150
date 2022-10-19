// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]
// YW: this code needs to be built by adding -std=c++11
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void ECMergeIntervals(const std::vector<std::pair<int, int> > &listIntervals, std::vector<std::pair<int, int> > &listNonOverlapIntervals)
{
  pair<int, int> maxInterval = {INT_MAX, INT_MAX};
  vector<std::pair<int, int> > vecIntervals = listIntervals;
  vecIntervals.push_back(maxInterval);
  listNonOverlapIntervals.clear();

  if (vecIntervals.size() == 1 || vecIntervals.size() == 0)
  {
    listNonOverlapIntervals = vecIntervals;
  }
  else
  {
    //MergeSort(vecIntervals);
    // YW: I changed this to use std::sort instead of home-cooked sort
    std::sort(vecIntervals.begin(), vecIntervals.end());

    for (int i = 0; i < vecIntervals.size(); i++)
    {
      int currentMax = vecIntervals[i].second;
      for (int j = i + 1; j < vecIntervals.size(); j++)
      {
        if (currentMax + 1 < vecIntervals[j].first)
        {
          pair<int, int> interval = {vecIntervals[i].first, vecIntervals[j - 1].second};
          listNonOverlapIntervals.push_back(interval);
          i = j - 1;
          break;
        }

        currentMax = vecIntervals[j].second;
      }
    }
  }
  // listNonOverlapIntervals.push_back(vecIntervals[vecIntervals.size() - 1]);
}

int main()
{
  const std::vector<std::pair<int, int> > vecIntervals = {{1, 2}, {3, 7}, {12, 13}, {20, 23}};
  std::vector<std::pair<int, int> > listNonOverlapIntervals;

  ECMergeIntervals(vecIntervals, listNonOverlapIntervals);

  for (pair<int, int> interval : listNonOverlapIntervals)
  {
    std::cout << interval.first << ", " << interval.second << std::endl;
  }

  //  More test cases?
}
