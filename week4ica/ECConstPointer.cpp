#include <iostream>
using namespace std;
int ECSumArray(const int *listNums, int size)
{
	int sum = 0;
	for( const int *ptr = listNums; ptr < listNums + size; ++ptr){
		sum += *ptr;
	}
	return sum;
}

int main()
{
  int array[] = {1,2,3,5};
  cout << ECSumArray(array, 4) << endl;
  return 0;
}
