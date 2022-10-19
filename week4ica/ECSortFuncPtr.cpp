#include <iostream>
using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*comp)(int, int))
{
	int pmin = 0;
  	for(int i=0; i<size; ++i){
		pmin = i;
		int min = listNumbers[pmin];
		for(int j = pmin+1; j < size; ++j){
			if(comp( listNumbers[j],min)){
				min = listNumbers[j];
				int temp = listNumbers[pmin];
				listNumbers[pmin] = listNumbers[j];
				listNumbers[j] = temp;
			}
		}	
 	 }
}

bool Compare(int x, int y){
	if((x%2 == 0) && (y%2 ==1)){
		return true;
	}

	if((x%2 == 1) && (y%2==0)){
		return false;
	}

	return x < y;
}

int main()
{
  int arr[] = {1,3,2,4};
  ECSortFP(arr, 4, Compare);

  // print it out
  for(int i=0; i<4; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

