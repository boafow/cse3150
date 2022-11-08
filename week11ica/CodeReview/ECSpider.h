//
//  ECSpider.h
//
//

#ifndef ECSpider_h
#define ECSpider_h

#include "ECOrganism.h"
#include <string>

class ECSpider : public ECOrganism
{
public:
    ECSpider(string name);
    ECSpider(string name, ECOrganism* prey);
    virtual void Work(double hour, int type);
    virtual void Eat(double hour);
    virtual bool IsSleeping(double hour) const;
    void Weave();
    void Hunt();
    virtual void kill()
    {
        vitality = 0;
    }
    virtual string GetType()
    {
        return "Spider";
    }

private:
    int timesEaten = 0;
    ECOrganism* prey;

};

#endif /* ECSpider_h */

