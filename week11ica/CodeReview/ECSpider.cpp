//
//  ECSpider.cpp
//
//

#include "ECSpider.h"
#include <iostream>
#include <utility>
using namespace std;

ECSpider::ECSpider(string name) : ECOrganism(name)
{
    name = name;
}

ECSpider::ECSpider(string name, ECOrganism* o) : ECOrganism(name)
{
    name = name;
    prey = o;
}



bool ECSpider::IsSleeping(double hour) const
{
    if (hour >= 9 && hour <= 17)
    {
        return true;
    }
    return false;
}

void ECSpider::Eat(double hour)
{
    if (timesEaten < 5)
    {
        vitality += 20;
        if (vitality > 100)
        {
            vitality = 100;
        }
        timesEaten++;
    }
    cout << "spider eats at hour " << hour << endl;
}

void ECSpider::Work(double hour, int type)
{
    if (type == 0)
    {
        Weave();
        vitality -= 10;
    }
    if (type == 1)
    {
        Hunt();
        cout << "Spider " << name << " attempted Hunt at hour " << hour <<endl;
    }
}

void ECSpider::Weave()
{
    cout << "Spider" << name << " Weaving!" << endl;
}


void ECSpider::Hunt()
{
    
    if (dynamic_cast<const ECOrganism*>(prey) != nullptr){
        if (prey->vitality > 0)
        {
            vitality -= 30;
            if (prey->GetType() == "Spider" || prey->GetType() == "Grasshopper" || prey->GetType() == "Caterpillar"){
                cout << "Spider" << name << " Hunting!" << endl;
                prey->vitality = 0;
            }
        }
        if(vitality < 0){
            vitality = 0;
        }
        
    }
       
}

