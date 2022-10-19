#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  int w = 0;
  char arr[] = "hello";
  int i=8;
  arr[i] = 'T';
  cout << "arr = " << arr << endl;
  cout << "w = " << w << endl;
  bitset<32> bb(w);
  cout << "Binary w: " << bb << endl;
  return 0;
}
