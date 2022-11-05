#include "ECOrganism.h"
#include "ECSpider.h"

void ECSpider::Work(double hour, int type)
{
	if (vitality > 0 && !IsSleeping(hour))
	{
		if (type == 0)
		{
			vitality -= work0;
		}
		else
		{
			trap(prey);
		}
	}
}

void ECSpider::trap(ECOrganism *rhs)
{
	if (rhs == nullptr)
		return;
	if (rhs != nullptr || rhs->vitality > 0)
	{
		if (rhs->species == "grasshopper" ||
			rhs->species == "spider" ||
			rhs->species == "caterpilar")
		{
			prey = nullptr;
			rhs->vitality = 0;
		}
	}
	vitality -= work1;
}
