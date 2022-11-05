#include "ECOrganism.h"
#include "ECGrasshopper.h"

void ECGrasshopper::Work(double hour, int type)
{
    if (vitality > 0 && !IsSleeping(hour))
    {
        if (type == 0)
        {
            vitality -= work0;
        }
        else
        {
            bite(prey);
        }
    }
}

void ECGrasshopper::bite(ECOrganism *rhs)
{
    if (rhs == nullptr)
        return;
    if (rhs->vitality > 0)
    {
        if (rhs->species == "grasshopper" ||
            rhs->species == "spider" ||
            rhs->species == "caterpilar")
        {
            prey = nullptr;
            rhs->vitality = 0;
        }
        else if (rhs->species == "mouse")
        {
            rhs->vitality -= 5;
        }
        vitality -= work1;
    }
}