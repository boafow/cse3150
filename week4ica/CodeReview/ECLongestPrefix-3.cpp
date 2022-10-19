#include <iostream>
using namespace std;

// Implement the longest prefix function here...
string ECLongestPrefix(int numStrings, const string arrayStrings[]) {
    // YW: this only serves as a starter code, which just print out the given array of strings
    // Replace with your own code here...
    string prefix(arrayStrings[0]);
    for (int i = 1; i < numStrings; ++i) {
        int pSize = prefix.size();
        if (pSize == 0) {
            break;
        }
        int compSize = arrayStrings[i].size();
        int maxSize = pSize < compSize ? pSize : compSize;
        int index = 0;
        bool isSame = true;
        while (index < pSize) {
            if (isSame && index < arrayStrings[i].size() && prefix[index] == arrayStrings[i][index]) {
                index++;

            } else {
                isSame = false;
                prefix.pop_back();
                index++;
            }
        }
    }
    return prefix;
}

