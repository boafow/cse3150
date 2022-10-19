#include <iostream>
#include <vector>
using namespace std;

int ECBinarySearch(const int listNumbers[], int size, int value)
{
	int lower = 0;
	int upper = size;
	int mid;
	while(lower != upper){
		mid = (lower + upper)/2;
		if(value == listNumbers[mid]){
			return mid;
		} else if (value > listNumbers[mid]) {
			lower = mid + 1;
		} else {
			upper = mid - 1;
		}
	}
	return -1; 
}
/*
int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
	cout << ECBinarySearch(arr, 11, 9);
}*/
