using namespace std;

// This is the generic subscriber of ECExchange.
class ECSubscriber
{
public:
  // your code
};


// This is the stock market which publishes stock prices. 
class ECExchange
{
public:
  ECExchange()
  {
  }
  // don't free the memory of subscribers
  ~ECExchange()
  {
  }
  // called when there is a change of price of some stock
  // For example, if stock AAPL's price changes to 100, you would call
  // UpdatePrice(string("AAPL"), 100);
  void UpdatePrice(const std::string &tickerStock, double price)
  {
    // your code
  }

  // Observer pattern, add/remove subscribers
  void Subscribe(ECSubscriber *psub)
  {
    // your code
  }
  void Unsubscribe(ECSubscriber *psub)
  {
    // your code
  }
  // add any other functions if you need

private:
  // your code
};

// This is a concrete type of subscriber, who is interested in analyzing the stock prices. It keeps track of the price changes of all stocks, and reports the minimum/maximum stock prices of a specific stock.
class ECStockAnalysist 
{
public:
  ECStockAnalysist() 
  {
  }
  // get the min/max of a stock, and save to (priceMin, priceMax)
  // return 0/0 if the stock price hasn't been updated yet
  void GetStockPriceRange(const string &ticker, double &priceMin, double &priceMax) const
  {
    // your code
  }

  // your code here

private:
  // your code here
};

// Trader is interested in a specific stock (ticker passed in to the constructor)
class ECStockTrader : public ECSubscriber
{
public:
  ECStockTrader(const string &ticker) : tickerFocus(ticker) {}

  // get the number of price changes for this stock
  int GetNumPriceChanges() const
  {
    // your code here
  }

private:
  std::string tickerFocus;
  // your code here
};

