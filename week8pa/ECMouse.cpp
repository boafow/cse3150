#include "ECOrganism.h"
#include "ECMouse.h"

void ECMouse::Work(double hour, int type)
{
        if (vitality > 0 && !IsSleeping(hour))
        {
                if (type == 0)
                {
                        vitality -= work0;
                }
                else
                {
                        hunt(prey);
                }
        }
}

void ECMouse::hunt(ECOrganism *rhs)
{
        if (rhs == nullptr)
                return;
        if (rhs != nullptr || rhs->vitality > 0)
        {
                if (rhs->species == "grasshopper")
                {
                        prey = nullptr;
                        rhs->vitality = 0;
                }
        }
        vitality -= work1;
}
