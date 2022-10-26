//
//  ECOrganism.h
//  
//

#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>

// ********************************************************
// Generic organism

class ECOrganism
{
public:
    // your code here

    // work and consume energy
    virtual void Work(double hour, int type);
    // eat and gain energy
    virtual void Eat(double hour);
    // is sleeping at this hour?
    virtual bool IsSleeping(double hour) const = 0;

protected:
  // your code

private:
  // your code
};


#endif /* ECOrganism_h */
