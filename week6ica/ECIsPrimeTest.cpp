#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

extern bool ECIsPrime(long n);

void Test()
{
//  const long primeLarge = 999983;
//  const long primeLarge = 533000389;
//  const long primeLarge = 982451653;
//  const long primeLarge = 2147483647;
//  const long primeLarge = 999999999989;
//  const long primeLarge = 41434547495153;
//  const long primeLarge = 1181118711931201;
  const long primeLarge = 9999999900000001;
  bool f = ECIsPrime( primeLarge );

  if( f )
  {
    cout << primeLarge << " is prime\n";
  }
  else
  {
    cout << primeLarge << " is not prime\n";
  }
}

int main()
{
  int n = 2;
  bool f1 = ECIsPrime(n);
  if( f1 )
  {
    cout << n << " is prime\n";
  }
  else
  {
    cout << n << " is not prime\n";
  }
  n=5;
  f1 = ECIsPrime(n);
  if( f1 )
  {
    cout << n << " is prime\n";
  }
  else
  {
    cout << n << " is not prime\n";
  }
  n=9;
  f1 = ECIsPrime(n);
  if( f1 )
  {
    cout << n << " is prime\n";
  }
  else
  {
    cout << n << " is not prime\n";
  }
  auto start = high_resolution_clock::now();
  Test();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running time: "  << duration.count() << endl;
  return 0;
}
