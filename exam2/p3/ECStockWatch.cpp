#include <set>
#include <vector>
#include <pair>
#include <map>
using namespace std;

// This is the generic subscriber of ECExchange.
class ECSubscriber
{
public:
	ECSubscriber(){};
	virtual ~ECSubscriber(){};
	virtual void Update(const std::string &tickerStock, double price) = 0;
};


// This is the stock market which publishes stock prices. 
class ECExchange
{
public:
  ECExchange(){}
  ~ECExchange(){}
  // called when there is a change of price of some stock
  // For example, if stock AAPL's price changes to 100, you would call
  // UpdatePrice(string("AAPL"), 100);
  void UpdatePrice(const std::string &tickerStock, double price)
  {
    for(sub : psubs){
	    sub->Update(tickerStock, price);
    }
  }
  // Observer pattern, add/remove subscribers
  void Subscribe(ECSubscriber *psub)
  {
    psubs.push_back(psub);
  }
  void Unsubscribe(ECSubscriber *psub)
  {
    psubs.remove(psubs.begin(), psubs.end(), psub);
  }
  // add any other functions if you need

private:
  vector<ECSubscriber *> psubs;
};

// This is a concrete type of subscriber, who is interested in analyzing the stock prices. It keeps track of the price changes of all stocks, and reports the minimum/maximum stock prices of a specific stock.
class ECStockAnalysist 
{
public:
  ECStockAnalysist() {}
  // get the min/max of a stock, and save to (priceMin, priceMax)
  // return 0/0 if the stock price hasn't been updated yet
  void GetStockPriceRange(const string &ticker, double &priceMin, double &priceMax) const
  {
   	priceMin = stockPrices[stockTicker].first();
	priceMax = stockPrices[stockTicker].second();
  }
  virtual void Update(std::string &stockTicker, double price){
	if(!stockPrices.count(stockTicker)) stockPrices.insert(std::pair<int, pair<double, double>>(stockTicker, std::pair<double, double>(0, 0)));
	if(stockPrices[stockTicker].first() > price) { stockPrices[stockTicker].first() = price; }
	if(stockPrices[stockTicker].second() < price) { srockPrices[stockTicker].second() = price; }
  }

private:
  std::map<std::string, std::pair<double, double>> stockPrices;
};

// Trader is interested in a specific stock (ticker passed in to the constructor)
class ECStockTrader : public ECSubscriber
{
public:
  ECStockTrader(const string &ticker) : tickerFocus(ticker), priceChanges(0) {}

  // get the number of price changes for this stock
  int GetNumPriceChanges() const{ return priceChanges; }
  virtual void Update(std::string &stockTicker, double price){
	  if(tickerFocus == stockTicker){
		priceChanges += 1;
	  }
  }

private:
  std::string tickerFocus;
  int priceChanges;
};

