#ifndef ECSpider_h
#define ECSpider_h

#include <string>
#include "ECOrganism.h"

class ECSpider: virtual public ECArthopods {
public:
	const std::string name;
	ECArthopods* prey;
	int work0 = 10;
	int work1 = 30;
	int recharge = 20;
	int eatLimit = 5;
	ECSpider(const std::string &name, ECArthopods* prey = nullptr): ECArthopods(name), name(name), prey(prey) {};
	void Work (double hour, int type);
	void weave(ECOrganism* prey);
};

#endif /* ECSpider_h */
