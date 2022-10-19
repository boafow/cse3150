#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Enter an integer value for a: ";
	// your code goes here...
	int a, b; 
       	cin >> a;
	if (cin.fail()){
		cout << "Not an integer!" << endl;
		return 0;
	} else {
		cout << "Enter an integer value for b: ";
        	cin >> b;
		if(cin.fail()){
			cout << "Not an integer!" << endl;
			return 0;
		} else {
			cout << a << " + " << b << " = " << a + b << endl;
			return 0;	
		}
	}
}
