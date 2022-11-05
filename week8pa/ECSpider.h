#ifndef ECSpider_h
#define ECSpider_h

#include <string>
#include "ECOrganism.h"

class ECSpider : public ECArthopods
{
	ECOrganism *prey;

public:
	ECSpider(const std::string &name, ECOrganism *prey = nullptr, const std::string &species = "spider", int eatLimit = 5, int sleepStart = 9, int sleepEnd = 17, int recharge = 20, int work0 = 10, int work1 = 30) : 
	ECArthopods(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1)
	{
		this->prey = prey;
	};
	void Work(double hour, int type);
	void trap(ECOrganism *prey);
};
#endif /* ECSpider_h */
