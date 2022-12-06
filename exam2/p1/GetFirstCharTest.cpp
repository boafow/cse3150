#include "GetFirstChar.cpp"
#include <iostream>
#include <chrono>
using namespace std::chrono;

void Test()
{
  // 
  char buff[10] = "CSE 3150";

  cout << GetFirstChar(buff) << endl;

  // also can pass in string as well
  string str = "CSE 3150";
  cout << GetFirstChar(str) << endl;
}

void Test2()
{
  const int SZ = 1000000;
  char buff[SZ];
  buff[0] = 'a';
  buff[1] = 'b';
  buff[2] = 'c';
  cout << GetFirstChar(buff) << endl;

  // now run multiple times
  for(int i=0; i<1000000; ++i)
  {
    if(GetFirstChar(buff) != 'a')
    {
      throw "wrong";
    }
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  Test();
  Test2();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running time: " << duration.count() << endl;
}

