#include "ECOrganism.h"
#include "ECFox.h"

void ECFox::Work(double hour, int type)
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

void ECFox::hunt(ECOrganism *rhs)
{
    if (rhs == nullptr)
        return;
    if (rhs != nullptr || rhs->vitality > 0)
    {
        if (rhs->species == "mouse")
        {
            prey = nullptr;
            rhs->vitality = 0;
        }
        vitality -= work1;
    }
}
