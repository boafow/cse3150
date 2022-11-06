//
//  ECMerchandiseFactory.hpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"

// *********************************************************
// List of vendors
typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;

// *********************************************************
// merchandise factory

// your code goes here


// *********************************************************
// Merchandise creation: singleton pattern

class ECMerchandiseTennisShop
{
public:
    virtual ~ECMerchandiseTennisShop();
    static ECMerchandiseTennisShop &Instance();
    ECTennisShoe *OrderTennisShoe(int sz);
    ECTennisBallCan *OrderTennisBallCan();
    ECTennisBag *OrderTennisBag();
    void ChooseVendor(TENNIS_VENDOR vendor);
    int GetNumShoesSold() const;
    int GetNumBallcansSold() const;
    int GetNumBagsSold() const;
    int GetTotNumBallsSold() const;
    int GetTotRacquetBagCapaictySold() const;
    int GetTotRevenue() const;
    
private:
    // your code goes here
};


#endif /* ECMerchandiseFactory_hpp */
