#include "ECOrganism.h"
#include <iostream>
bool ECOrganism::IsSleeping(double hour) const
{
	if (sleepEnd < sleepStart)
	{
		double newEnd = sleepEnd + 24;
		return ((hour + 24) <= newEnd && (hour + 24) >= sleepStart);
	}
	return (hour <= sleepEnd && hour >= sleepStart);
}

void ECOrganism::Eat(double hour, int recharge = 0)
{
	if (vitality <= 0 || eatLimit <= 0 || vitality >= 100)
	{
		return;
	}
	else if (!IsSleeping(hour))
	{
		vitality += recharge;
		if(vitality > 100)
		{
			vitality = 100;
		}
		std::cout << eatLimit << std::endl;
		std::cout << vitality << std::endl;
	}

}