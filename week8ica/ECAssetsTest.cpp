#include "ECAssets.h"
#include <iostream>
#include <vector>
using namespace std;

void Test()
{
  // Create an account, owner is Amy
  ECAccount account("Amy");

  // Cash of $1000
  ECCash *pc1 = new ECCash(1000);
  
  // Add to account of Amy
  account.AddAsset(pc1);
 
  // Stock of AAPL, 100 shares, current price $200, cost (per share) $150
  ECStock *ps1 = new ECStock("AAPL", 100, 200, 150);
  account.AddAsset(ps1);

  // Dividie stock: BAC, 50 shares, current price $30, cost (per share) $35,  divident $2 per share 
  ECDividentStock *ps2 = new ECDividentStock("BAC", 50, 30, 35, 2);
  account.AddAsset(ps2);

  // find out the account balance
  cout << "Balance of Amy's account: " << account.GetBalance() << endl;

  // now buy 10 shares of "GOOG" at price $100
  account.PurchaseStock("GOOG", 10, 100);
}

int main()
{
  Test();
}

