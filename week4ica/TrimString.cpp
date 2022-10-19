#include <string>
using namespace std;
// ensure x is trimed to contain its prefix of length of 
// no more than five after the function call
void TrimString(string &x)
{
	x = x.substr(0,5);
}
