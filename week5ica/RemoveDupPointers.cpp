#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
using namespace std;

void RemoveDupPointers(vector<string *> &arrayPtrs)
{
	/*
        for (long unsigned int i = 0; i < arrayPtrs.size(); i++)
        {
            for (long unsigned int j = i + 1; j < arrayPtrs.size(); j++)
            {
                if (*arrayPtrs[i] == *arrayPtrs[j])
                {
                    arrayPtrs.erase(arrayPtrs.begin() + j);
                    j--;
                }
            }
        }
  	*/
	set<string> setKnowns;
	for(unsigned int i = 0; i < arrayPtrs.size(); ++i){
		if(setKnowns.find(*arrayPtrs[i]) != setKnowns.end()) {
			arrayPtrs.erase(arrayPtrs.begin() + i);
			--i;
		} else {
			setKnowns.insert(*arrayPtrs[i]);
		}
	}

}

