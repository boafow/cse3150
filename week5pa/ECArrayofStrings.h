#ifndef EC_ARRAY_OF_STRINGS
#define EC_ARRAY_OF_STRINGS

using namespace std;
#include <string>
#include <vector>

class ECArrayofStrings {
	public:
		ECArrayofStrings();
		~ECArrayofStrings();
  		void AddString( const std::string &strToAdd );
  		int GetNumofStrings() const;
  		int GetMaxLen() const;
  		std::string GetLongestCommonPrefix() const;
  		std::string Concatnate() const;
  		void Dump() const;
	private:
  		std::string GetLongestCommonPrefixofTwo(const std::string &str1, const std::string &str2) const;
		std::vector<std::string> setofstrings;
};


#endif
