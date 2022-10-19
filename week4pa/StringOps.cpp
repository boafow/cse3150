#include "StringOps.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

void ConcatenateStrings( std::vector<char> &strConcatTo, const std::vector<char> &strConcating  )
{
    for(auto c : strConcating){
	strConcatTo.push_back(c);
    }
}

void GetDistinctSubstrings( const std::vector<char> & strInput, int k, std::set<vector<char>> &setUniqueSubstrings  )
{
	setUniqueSubstrings.clear();
	if(k > strInput.size() || k == 0) return;
	if(k == strInput.size()){
		setUniqueSubstrings.insert(strInput);
		return;
	}
	int i = 0;	//Keep track of index i
	for(char x : strInput) {	//Range based for loop goes through strIput by char
		vector<char> strVec; 	//Declare new vector
		for(int j = 0; j < k; ++j){	//Loop through strInput at index i for length k substring 
			if(i + k > strInput.size()) return;
			strVec.push_back(strInput[i+j]);	//Index at i (index of current range loop char) + j (index of substring starting at i
		}
		setUniqueSubstrings.insert(strVec);	//Insert into unique set
		strVec.clear();				//Clear vector
		++i;					//Increment index to keep track of current position in range based for
	}
}

bool IsSubString( const std::vector<char> &strInput, const std::vector<char> &strPattern ) {
	if(strPattern.size() > strInput.size()) return false;
	int i = 0;							// Keep track of index of c in range based for loop
	for(auto c : strInput) { 					// Use range base for loop to iterate over vector
		if(c == strPattern[0]){					// If the current chracter c matches the first character of the pattern
			for(int j = 0; j < strPattern.size(); ++j){ 	// For loop iterates through strPattern
				if(strInput[i+j] != strPattern[j]){	// If the current character + j(index of strPattern) is not equal to the current character of j false
				       	return false;
				} 	
			}
		return true;
		}
		++i;	// Increment the index of the current character in the range based for loop
	}
	return false;
}

void GetDuplicateChars(const std::vector<char> &strInput, std::set<char> &setDupChars){
	// Keep track of characters in a map of characters to integers
	// Iterate over map and insert characters that appear more than once into setDupCharacters

	map<char, int> duplicateMap;
	for(auto c : strInput){
		if(duplicateMap.find(c) == duplicateMap.end()){
			duplicateMap.insert(pair<char, int>(c, 1));
		} else {
			duplicateMap[c] += 1;
		}
	}

	for(auto c : duplicateMap){
		if(c.second > 1){
			setDupChars.insert(c.first);
		}
	}

}

/*
int main() {
	vector<char> concatTo = {'a', 'b'};
	vector<char> concat = {'c'};
	ConcatenateStrings(concatTo, concat);
	cout << "Strcat: ";
	for(auto c : concatTo){
		cout << c;
	}
	cout << endl;
	
	string s1 = "string1";
	vector strIn(s1.begin(),s1.end());
	set<vector<char>> uniqueSubstrings;
	GetDistinctSubstrings(strIn, 4, uniqueSubstrings);
	for(auto vec : uniqueSubstrings){
		for(auto ch : vec){
			cout << ch;
		}
		cout << " ";
	}
	cout << endl;
	
	vector<char> vecString = {'w', 'i', 'l', 'l', 'i', 'a', 'm'};
	vector<char> vecPattern = {'w','i','l','l','i','a','m', 'm'};
	cout << "IsSubstring: " << IsSubString(vecString, vecPattern) << endl;

	vector<char> vecString2 = {'w', 'w', 'i', 'l', 'l', 'i', 'a', 'm'};
	set<char> setChar;
	
	cout << "GetDupChars: " << setChar.size() << endl;
	GetDuplicateChars(vecString2, setChar);
	cout << "GetDupChars: " << setChar.size() << endl;
	return 0;
}*/
