#ifndef EC_ASSETS_H
#define EC_ASSETS_H

#include <string>

class ECAsset {
public:
	ECAsset();
	virtual double GetValue() const = 0;
	virtual double GetProfit() const = 0;
	
};

class ECCash : public ECAsset
{
public:
  ECCash(double amount);
  virtual double GetValue() const;
  virtual double GetProfit() const;

private:
  double value;
};

class ECStock : public ECAsset
{
public:
  ECStock(const std::string &ticker, double shares, double price, double cost);
  virtual double GetValue() const;
  virtual double GetProfit() const;
private:
  std::string ticker;
  double shares;
  double price;
  double cost;

};

class ECDividentStock : public ECStock
{
public:
  ECDividentStock(const std::string &ticker, double shares, double price, double cost,  double divident);
  virtual double GetValue() const;
  virtual double GetProfit() const;

  // what to put here?
private:
  double divident;
};

class ECAccount
{
public:
  ECAccount(const std::string &ownerName);

  // Add asset
  void AddAsset(ECAsset *pAsset);

  // Get balance
  double GetBalance();

  double GetProfit();
  double GetCashBalance();


  // Buy stock
  void PurchaseStock(const std::string &ticker, double shares, double curPrice);

  // what more to put here?
  //
private:
  std::vectors<ECAsset *> listAssets;
};

#endif
