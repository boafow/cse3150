// Check whether the given integer list has duplicates or not
// Return true if there is duplicate, false otherwise
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool ECCheckDuplicates(const std::vector<int> &listNumbers)
{
    vector<int> sorted = listNumbers;
    sort( sorted.begin(), sorted.end());
    auto j = sorted.begin()+1;
    
    for (auto i=sorted.begin(); i<sorted.end()-1; i++) {
        if (*i == *j) {
            return true;
        }
        j++;
    }
    return false;
}

int main()
{
    const vector<int> v = {1, 4, 5, 3, 4, 1};
    cout << "There is a duplicate: " << ECCheckDuplicates(v) << endl;
}


