#ifndef ECPanda_h
#define ECPanda_h

#include <string>
#include "ECOrganism.h"

class ECPanda : public ECMammals
{

public:

    ECPanda(const std::string &name, ECOrganism *prey = nullptr, const std::string &species = "panda", int eatLimit = 12, int sleepStart = 15, int sleepEnd = 10, int recharge = 50, int work0 = 0, int work1 = 0) : 
    ECMammals(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1)
    {};
    void Work(double hour, int type);
};

#endif /* ECPanda_h */
