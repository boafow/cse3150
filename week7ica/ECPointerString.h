#ifndef EC_STRING_PTR
#define EC_STRING_PTR

#include <string>

class ECStringPtr
{
public:
	ECStringPtr();					//default
	ECStringPtr(const std::string &strInit);	//custom
	ECStringPtr(const ECStringPtr &rhs);		//copy
	ECStringPtr(ECStringPtr &&rhs);			//move
	~ECStringPtr();					//Destructor
	
	ECStringPtr &operator=(const ECStringPtr &rhs); //assignment operator
	void SetString(const std::string &strToSet);	
	const std::string *GetPtr() const;

        // Skip for the first pass. Create a string by duplicating itself, e.g. if this string is "abc", 
        // the new string is "abcabc"
        ECStringPtr Duplicate() const;
	
private:
  std::string *ptr;
};

#endif
