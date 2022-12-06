// Test minesweeper
#include "ECMinesweeper.h"
#include <iostream>
using namespace std;

void Test()
{
  ECMinesweeper mf(4,4);
  mf.PlantMine(0, 0);
  mf.PlantMine(2, 1);
  // check mine number
  // [0,1] = 1
  cout << "mn[0,1]: " << mf.GetMineNumber(0,1) << endl;
  // [0,1] = 1
  cout << "mn[0,1]: " << mf.GetMineNumber(0,1) << endl;
  // [0,2] = 0
  cout << "mn[0,2]: " << mf.GetMineNumber(0,2) << endl;
  // [1,0] = 2
  cout << "mn[1,0]: " << mf.GetMineNumber(1,0) << endl;
  // [1,1] = 2
  cout << "mn[1,1]: " << mf.GetMineNumber(1,1) << endl;
  // [1,2] = 1
  cout << "mn[1,2]: " << mf.GetMineNumber(1,2) << endl;
  // [2,0] = 1
  cout << "mn[2,0]: " << mf.GetMineNumber(2,0) << endl;
  // [3,0] = 1
  cout << "mn[3,0]: " << mf.GetMineNumber(3,0) << endl;
  // [3,3] = 0
  cout << "mn[3,3]: " << mf.GetMineNumber(3,3) << endl;
}

int main()
{
  Test();
}

