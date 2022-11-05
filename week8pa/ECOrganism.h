#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>

class ECOrganism
{
public:
    const std::string name; // organism name
    double vitality = 100;  // organism vitality
    const std::string species; // organism type
    int eatLimit;           // organism eat limit
    int sleepStart;
    int sleepEnd;
    int recharge;
    int work0;
    int work1;

    ECOrganism(){};
    ECOrganism(const std::string &name, const std::string &species, int eatLimit, int sleepStart, int sleepEnd, int recharge, int work0, int work1) : name(name), species(species), eatLimit(eatLimit), sleepStart(sleepStart), sleepEnd(sleepEnd), recharge(recharge), work0(work0), work1(work1){};
    virtual ~ECOrganism(){};
    virtual void Work(double hour, int type) = 0;
    virtual void Eat(double hour, int recharge);
    virtual std::string GetName(){ return name; };
    virtual bool IsSleeping(double hour) const;
};

// Arthopod class to generalize arthopod behaviors
class ECArthopods :  public ECOrganism
{
public:
    // custom constructor that takes in all attributes
    ECArthopods(const std::string &name, const std::string &species, int eatLimit, int sleepStart, int sleepEnd, int recharge, int work0, int work1) : ECOrganism(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1){};
};

// Mammal class to generalize mammal behaviors
class ECMammals : public ECOrganism
{
public:
    // custom constructor that takes in all attributes
    ECMammals(const std::string &name, const std::string &species, int eatLimit, int sleepStart, int sleepEnd, int recharge, int work0, int work1) : ECOrganism(name, species, eatLimit, sleepStart, sleepEnd, recharge, work0, work1){};
};
#endif /* ECOrganism_h */
