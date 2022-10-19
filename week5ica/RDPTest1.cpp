#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <chrono>
using namespace std::chrono;

extern void RemoveDupPointers(vector<string *> &arrayPtrs);

void Test()
{
  const int SZ = 100;
  const int NUM_STR = 50000;
  vector<string> arrayStrs;
  for(int i=0; i<NUM_STR; ++i)
  {
    string str(SZ, 'a');
    int pos = i % SZ;
    str[pos] += i;
    arrayStrs.push_back(str); 
  }
  vector<string *> arrayPtrs;
  for(int i=0; i<NUM_STR; ++i)
  {
    arrayPtrs.push_back(&arrayStrs[i]);
  }
  auto start = high_resolution_clock::now();
  RemoveDupPointers(arrayPtrs);
  // time it again
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running time: "  << duration.count() << endl;
}

int main()
{
  Test();
}

