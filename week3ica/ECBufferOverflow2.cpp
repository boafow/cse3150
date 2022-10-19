#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main();

void foo()
{
  cout << "Enter foo\n";
  long arr[10] = {0};
  int i = 10;
  int offset = 1;
  arr[i+3] = (long)main+offset;
  cout << "arr: ";
  for(int i = 0; i < 16; i++){
	  cout << arr[i] << " ";
	 }
  cout << endl;
  cout << "Foo is at: " << (long)foo << endl;
  cout << "Main is at: " << (long)main << endl;
  // sleep for a while
  std::chrono::milliseconds timespan(1000); // or whatever
  std::this_thread::sleep_for(timespan);
  cout << "Exit foo\n";
}

int main()
{
  foo();
  return 0;
}

