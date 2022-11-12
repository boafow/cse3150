//
//  ECMerchandiseFactory.cpp
//
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#include "ECMerchandiseFactory.h"
#include <iostream>

using namespace std;

// *********************************************************
// Merchandise creation: singleton pattern

ECTennisBag *ECMerchandiseTennisShop::OrderTennisBag()
{
    if(mVendor == TENNIS_ADIDAS)
    {
        mNumBagsSold++;
        mTotRacquetBagCapaictySold += 6;
        mTotRevenue += 18;
        return new ECTennisBag(2);
    }
    else if(mVendor == TENNIS_NIKE)
    {
        mNumBagsSold++;
        mTotRacquetBagCapaictySold += 4;
        mTotRevenue += 12;
        return new ECTennisBag(3);
    }
    else if(mVendor == TENNIS_HEAD)
    {
        mNumBagsSold++;
        mTotRacquetBagCapaictySold += 3;
        mTotRevenue += 10;
        return new ECTennisBag(4);
    }
}

ECTennisBallCan *ECMerchandiseTennisShop::OrderTennisBallCan()
{
    if(mVendor == TENNIS_ADIDAS)
    {
        mNumBallCansSold++;
        mTotNumBallsSold += 3;
        mTotRevenue += 5;
        return new ECTennisBallCan();
    }
    else if(mVendor == TENNIS_NIKE)
    {
        mNumBallCansSold++;
        mTotNumBallsSold += 4;
        mTotRevenue += 6;
        return new ECTennisBallCan();
    }
    else if(mVendor == TENNIS_HEAD)
    {
        mNumBallCansSold++;
        mTotNumBallsSold += 3;
        mTotRevenue += 4;
        return new ECTennisBallCan();
    }
}

ECTennisShoe *ECMerchandiseTennisShop::OrderTennisShoe(int size)
{
    if(mVendor == TENNIS_ADIDAS)
    {
        mNumShoesSold++;
        mTotRevenue += 20;
        return new ECTennisShoe(size);
    }
    else if(mVendor == TENNIS_NIKE)
    {
        mNumShoesSold++;
        mTotRevenue += 15;
        return new ECTennisShoe(size);
    }
    else if(mVendor == TENNIS_HEAD)
    {
        mNumShoesSold++;
        mTotRevenue += 10;
        return new ECTennisShoe(size);
    }
}
