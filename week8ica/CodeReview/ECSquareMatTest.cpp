#include "ECSquareMat.h"
#include <iostream>
using namespace std;

int main()
{
  ECSquareMat mat(2);
  mat.SetValAt(0,0,2);
  ECSquareMat mat1(2);
  mat.SetValAt(1,1,1);
  ECSquareMat mat2 = mat+mat1;
  cout << mat2.GetValAt(0,0) << endl;
}

