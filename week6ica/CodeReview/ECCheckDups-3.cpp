// Check whether the given integer list has duplicates or not
// Return true if there is duplicate, false otherwise
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool ECCheckDuplicates(const std::vector<int> &listNumbers) {
  std::vector<int> listNums = listNumbers;
  sort(listNums.begin(), listNums.end());
  for (int i = 0; i < listNumbers.size(); i++) {
    if (listNumbers[i] == listNumbers[i+1]) {
      return true;
    }
  }
  return false;
}

