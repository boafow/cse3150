#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>

class ECOrganism
{
public:
    std::string name; 	  //organism name
    int eatLimit; 	  //organism eat limit
    float vitality = 100; //organism vitality
    
    virtual void Work(double hour, int type);
    virtual void Eat(double hour); 
    virtual bool IsSleeping(double hour) const = 0;
    virtual void DoSomething(const ECOrganism &rhs); 
};

//Arthopod class to generalize arthopod behaviors
class ECArthopods: virtual public ECOrganism {
    float work0 = work1 = 0; //Work types will have values to subtract from vit
    float recharge = 0; 	//Each arthopod has specific recharge from eating
    int sleepStart = 9; //Arthopods sleep starting at 9
    int sleepEnd = 17; 	//Arthopods wake at 17
public:
    ECArthopods() = delete; 	//Arthopod default constructor deleted
    ~ECArthopods() = default; 	//Arthopod destructor default
    ECArthopods(std::string &name){ name = name;}; //Arthopod cutom constructor with name
};

//Mammal class to generalize mammal behaviors
class ECMammals: virtual public ECOrganism {
    float work0 = 10; 	//Mammals work0 is 10 vitality run
    float work1 = 0; 	//Mammal work1 is undefined
    float recharge = 50; //all mammals recharge 50 from eating
    int sleepStart = sleepEnd = 0; //start and end time for mammals sleep
public:
    ECMammals() = delete;
    ~ECMammals() = default;
    ECMammals(std::string &name){name = name;};
}
#endif /* ECOrganism_h */
