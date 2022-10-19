// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]
#include <iostream>
using namespace std;

int ECSmallestCoverIntervals(const int arrInts[], int szArr)
{
	int count = 0;
	if(szArr == 1) {
		return 0;
	}
	for(int i = 0; i < szArr; ++i){
		if((arrInts[i] + 1) != (arrInts[i+1])){
			count += 1;
		}
	}
	return count;
}
/*
int main() {
	int arr1[] = {1, 2, 3, 5, 6, 9};
	int arr2[] = {0, 1, 2, 4, 5, 7};
	int arr3[] = {0, 2, 3, 4, 6, 8, 9};
	int arr4[] = {0};
	cout << ECSmallestCoverIntervals(arr1, 6) << endl;	
	cout << ECSmallestCoverIntervals(arr2, 6) << endl;
	cout << ECSmallestCoverIntervals(arr3, 7) << endl;
	cout << ECSmallestCoverIntervals(arr4, 1) << endl;
}
*/
