//
//  ECOrganism.h
//
//

#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>
#include <vector>
#include <utility>
using namespace std;

// ********************************************************
// Generic organism

class ECOrganism
{
public:
  // your code here
  ECOrganism(string name) : name(name){};
  // work and consume energy
  virtual void Work(double hour, int type) = 0;
  // eat and gain energy
  virtual void Eat(double hour) = 0;
  // is sleeping at this hour?
  virtual bool IsSleeping(double hour) const = 0;

  virtual bool IsDead()
  {
    if (vitality <= 0)
    {
      return true;
    }
    return false;
  }

  virtual string GetName()
  {
    return name;
  }

  virtual string GetType() = 0;


  virtual float GetVitality()
  {
    return vitality;
  }
  vector<pair<int, double> > schedule;
  string name;
  float vitality = 100;

};

#endif /* ECOrganism_h */

