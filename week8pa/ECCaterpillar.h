#ifndef ECCaterpillar_h
#define ECCaterpillar_h

#include <string>
#include "ECOrganism.h"

class ECCaterpillar : public ECArthopods
{
public:
    ECCaterpillar(const std::string &name, const std::string &species = "caterpillar", int eatLimit = 5, int sleepStart = 9, int sleepEnd = 17, int recharge = 15, int work0 = 10, int work1 = 0) : ECArthopods(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1){};
    void Work(double hour, int type);
};

#endif /* ECCaterpillar_h */
