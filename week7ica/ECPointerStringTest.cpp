#include "ECPointerString.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1 = "abc";
  string str2 = "def";
  ECStringPtr sp(str1);
  cout << *sp.GetPtr() << endl; 
  sp.SetString(str2);
  cout << *sp.GetPtr() << endl; 

  // get duplicate
  //ECStringPtr strDup = std::move( sp.Duplicate() );
  ECStringPtr strDup = sp.Duplicate();
  cout << *strDup.GetPtr() << endl;

  return 0;
}

