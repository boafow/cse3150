#ifndef ECMouse_h
#define ECMouse_h

#include <string>
#include "ECOrganism.h"

class ECMouse : public ECMammals
{
    ECOrganism *prey;

public:
    ECMouse(const std::string &name, ECOrganism *prey = nullptr, const std::string &species = "mouse", int eatLimit = 10, int sleepStart = 10, int sleepEnd = 18, int recharge = 50, int work0 = 10, int work1 = 20) : ECMammals(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1)
    {
        this->prey = prey;
    };
    void Work(double hour, int type);
    void hunt(ECOrganism *prey);
};
#endif /* ECMouse_h */
