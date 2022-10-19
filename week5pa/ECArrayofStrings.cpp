#include <iostream>
#include "ECArrayofStrings.h" 

using namespace std;

ECArrayofStrings :: ECArrayofStrings(){

}

ECArrayofStrings :: ~ECArrayofStrings(){
	setofstrings.clear();
}

void ECArrayofStrings :: AddString( const string &strToAdd ){
	setofstrings.push_back(strToAdd);
}

int ECArrayofStrings :: GetNumofStrings() const{
	return setofstrings.size();
}

int ECArrayofStrings :: GetMaxLen() const{
	int max = 0;
	for( auto s : setofstrings ){
		if(s.size() > max) max = s.size();
	}
	return max;
}

string ECArrayofStrings :: GetLongestCommonPrefix() const{
	string prefix = setofstrings[0];
	for(int i = 1; i < setofstrings.size(); ++i){
		prefix = GetLongestCommonPrefixofTwo(prefix, setofstrings[i]);
	}
	return prefix;
}

string ECArrayofStrings :: Concatnate() const{
	std::string concat = setofstrings[0];
	for(int i = 1; i < setofstrings.size(); ++i){
		concat += setofstrings[i];
	}
	return concat;
}

void ECArrayofStrings:: Dump() const{
	for( auto s : setofstrings ){
		std::cout << s << endl;
	}
}

string ECArrayofStrings :: GetLongestCommonPrefixofTwo(const string &str1, const string &str2) const{
	std::string res = "";
	int len = min(str1.length(), str2.length());
	for(int i = 0; i < len; ++i){
		if(str1[i] != str2[i]) break;
		res += str1[i];
	}
	return res;
}


