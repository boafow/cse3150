#include "ECSquareMat.h"
#include <iostream>
using namespace std;

int main(){
	ECSquareMat mat(4);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			mat.SetValAt(i,j,i+j);
		}
	}
	for(int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j){
                        cout << mat.GetValAt(i,j) << endl;
                }
        }


	cout << mat.GetDimension() << endl;
	return 0;
}
