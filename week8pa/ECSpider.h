#ifndef ECSpider_h
#define ECSpider_h

#include <string>
#include "ECOrganism.h"

class ECSpider: virtual public ECOrganism, virtual public ECArthopods {
	work0 = 10;
	work1 = 30;
	recharge = 20;
	eatLimit = 5;
public:
	void DoSomething(const ECOrganism &rhs);

}

#endif /* ECSpider_h */
