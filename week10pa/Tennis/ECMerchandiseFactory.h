#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"

typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;

// class ECMerchandiseFactory
// {
// private:
//     /* data */
// public:
//     ECMerchandiseFactory();
//     ~ECMerchandiseFactory();
// };

class ECTennisShoe
{
public:
    ECTennisShoe(int size) : mSize(size) {}
    int GetSize() const { return mSize; }

private:
    int mSize;
};

class ECTennisBallCan
{
public:
    ECTennisBallCan() {}
};

class ECTennisBag
{
public:
    ECTennisBag(int racquetCapacity) : mRacquetCapacity(racquetCapacity) {}
    int GetRacquetCapacity() const { return mRacquetCapacity; }

private:
    int mRacquetCapacity;
};

class ECMerchandiseTennisShop
{
public:
    virtual ~ECMerchandiseTennisShop(){};
    static ECMerchandiseTennisShop &Instance()
    {
        static ECMerchandiseTennisShop instance;
        return instance;
    }

    ECTennisShoe *OrderTennisShoe(int sz);
    ECTennisBallCan *OrderTennisBallCan();
    ECTennisBag *OrderTennisBag();

    void ChooseVendor(TENNIS_VENDOR vendor) { mVendor = vendor; }
    int GetNumShoesSold() const { return mNumShoesSold; };
    int GetNumBallcansSold() const { return mNumBallCansSold; };
    int GetNumBagsSold() const { return mNumBagsSold; };
    int GetTotNumBallsSold() const { return mTotNumBallsSold; };
    int GetTotRacquetBagCapaictySold() const { return mTotRacquetBagCapaictySold; };
    int GetTotRevenue() const { return mTotRevenue; };

private:
    ECMerchandiseTennisShop(){ mVendor = TENNIS_ADIDAS; };
    TENNIS_VENDOR mVendor;
    int mNumShoesSold;
    int mNumBallCansSold;
    int mNumBagsSold;
    int mTotNumBallsSold;
    int mTotRacquetBagCapaictySold;
    int mTotRevenue;
};

#endif /* ECMerchandiseFactory_hpp */
