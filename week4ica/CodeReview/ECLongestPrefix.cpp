#include <iostream>
using namespace std;

string ECLongestPrefix(int numStrings, const string arrayStrings[]) {
    //cout << endl << endl;
    string base = arrayStrings[0]; // set starting common prefix to first element

    for(unsigned int i = 1; i < numStrings; i++) {      // iterate over all strings
        string value = arrayStrings[i];
        if (base != value) {
            //cout << "[1] base: " << base  << " value  " << value  << endl;
            //return "h";
            //cout << "base find value pos: " << base.find(value) << endl;
            while ( base.find(value) == string::npos ) {// while there are no common chars
                //cout << "[2]base: " << base << " value: " << value << endl;
                if (base.size() > value.size()) {       // from the larger string, remove last char
                    base.pop_back();
                }
                else value.pop_back();
            }

            base = value;                               // base and remaining value should be equal
            //cout << "[3] base: " << base << endl << "value: " << value << endl;
        }
    }
    string strDummy = base;
    return strDummy;
}



