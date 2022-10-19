#include <iostream>
#include "ECNumbers.h"

using namespace std;

int main(){
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	cout << ECNumbers::ECSquareN(n) << endl;
	cout << ECNumbers::ECDoubleN(n) << endl;
	return 0;
}
