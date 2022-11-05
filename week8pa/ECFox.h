#ifndef ECFox_h
#define ECFox_h

#include <string>
#include "ECOrganism.h"

class ECFox : public ECMammals
{
    ECOrganism *prey;

public:
    ECFox(const std::string &name, ECOrganism *prey = nullptr, const std::string &species = "fox", int eatLimit = 8, int sleepStart = 7, int sleepEnd = 14, int recharge = 50, int work0 = 10, int work1 = 40) : 
    ECMammals(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1){
        this->prey = prey;
    };
    
    void Work(double hour, int type);
    void hunt(ECOrganism *prey);
};

#endif /* ECFox_h */
