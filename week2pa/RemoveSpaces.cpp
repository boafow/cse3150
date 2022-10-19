#include <iostream>
#include <string>
using namespace std;

// your code goes here
string RemoveSpaces( const string &strIn)
{
    // your code goes here...
    string strOut;
    for(int i = 0; i < strIn.length(); i++){
	    if (strIn[i] != 32){ 
		strOut += strIn[i];
	    }
    }
    return strOut;
}
