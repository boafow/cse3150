#ifndef ECGrasshopper_h
#define ECGrasshopper_h

#include <string>
#include "ECOrganism.h"

class ECGrasshopper : public ECArthopods
{
    ECOrganism *prey;

public:

    ECGrasshopper(const std::string &name, ECOrganism *prey = nullptr, const std::string &species = "grasshopper", int eatLimit = 10, int sleepStart = 9, int sleepEnd = 17, int recharge = 25, int work0 = 5, int work1 = 40) : ECArthopods(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1)
    {
        this->prey = prey;
    };
	void Work(double hour, int type);
    void bite(ECOrganism *prey);
};
#endif /* ECGrasshopper_h */
