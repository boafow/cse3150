#include "ECStockWatch.cpp"
#include <iostream>
#include <cmath>
using namespace std;

void ASSERT_EQ(int x, int y)
{
  if( x== y )
  {
    cout << "Match value: " << x << endl;
  }
  else
  {
    cout << "Mismatch: " << x << "  " << y << endl;
  }
}

int main()
{
  // create a stock watch
  ECExchange ex;
  // create a subscriber for analysis
  ECStockAnalysist an;
  // Subscribe
  ex.Subscribe(&an);
  // create a trader for AAPL
  ECStockTrader st("AAPL");
  // Subscribe
  ex.Subscribe(&st);
  // update price for AAPL
  ex.UpdatePrice("AAPL", 100);
  // Update again 
  ex.UpdatePrice("AAPL", 120);
  // analysis should have range (100,120) for AAPL
  double pm = 0, pm2 = 0;
  an.GetStockPriceRange("AAPL", pm, pm2);
  ASSERT_EQ(std::fabs(pm-100)<0.00001, true);
  ASSERT_EQ(std::fabs(pm2-120)<0.00001, true);
  // trader should say price changed twice
  ASSERT_EQ(st.GetNumPriceChanges(), 2);
}

