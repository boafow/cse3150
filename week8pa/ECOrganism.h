#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>

class ECOrganism
{
public:
    const std::string name; 	  //organism name
    int eatLimit; 	  //organism eat limit
    double vitality; //organism vitality
  	 
    virtual void Work(double hour, int type) = 0;
    virtual void Eat(double hour, int recharge = 0) = 0; 
    virtual bool IsSleeping(double hour) const = 0;
    virtual double GetVit() = 0;
};

//Arthopod class to generalize arthopod behaviors
class ECArthopods: virtual public ECOrganism {
public:
    std::string name;
    double vitality = 100;
    int recharge = 0; 	//Each arthopod has specific recharge from eating
    int sleepStart = 9; //Arthopods sleep starting at 9
    int sleepEnd = 17; 	//Arthopods wake at 17
    ECArthopods(const std::string &name): name(name) {}; //Arthopod cutom constructor with name
    bool IsSleeping(double hour) const;
    void Eat(double hour, int recharge);
    double GetVit();
};

//Mammal class to generalize mammal behaviors
class ECMammals: virtual public ECOrganism {
public:	
    std::string name;
    double vitality = 100;
    int recharge = 50; //all mammals recharge 50 from eating
    int work0 = 10;
    int sleepStart = 0;
    int sleepEnd = 0; //start and end time for mammals sleep
    ECMammals(const std::string &name): name(name) {};
    bool IsSleeping(double hour) const;
    void Eat(double hour, int recharge);
    double GetVit();
};
#endif /* ECOrganism_h */
