#ifndef ECMerchandise_hpp
#define ECMerchandise_hpp

#include <string>

// your code goes here
class ECTennisShoe
{
	int shoeSize;
	int price;

public:
	//virtual destructor
	virtual ~ECTennisShoe() = default;
	virtual int GetShoeSize() const { return shoeSize; }
	virtual int GetPrice() const { return price; }
};

class ECTennisBall
{
	int numBalls;
	int price;

public:
	//virtual destructor
	virtual ~ECTennisBall() = default;
	virtual int GetNumBalls() const { return numBalls; }
	virtual int GetPrice() const { return price; }
};

class ECTennisBag
{
	int numRackets;
	int price;

public:
	//virtual destructor
	virtual ~ECTennisBag() = default;
	virtual int GetNumRackets() { return numRackets; }
	virtual int GetPrice() { return price; }
};

class vendor {
public:
	virtual ~vendor() = default;
	virtual ECTennisShoe* GetShoe() = 0;
	virtual ECTennisBall* GetBall() = 0;
	virtual ECTennisBag* GetBag() = 0;

	void createMerchandise();
	virtual ECTennisShoe* createShoe() { return new ECTennisShoe(); }
	virtual ECTennisBall* createBall() { return new ECTennisBall(); }
	virtual ECTennisBag* createBag() { return new ECTennisBag(); }
};

#endif /* ECMerchandise_hpp */
