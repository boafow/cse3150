#include <cmath>
using namespace std;

bool ECIsPrime(long n)
{
  for(int x = 2; x <= sqrt(n); ++x){
	  if((n%2) == 0){
		  return false;
	  }
  }
  return true;
}
