#include "ECCaterpillar.h"

void ECCaterpillar::Work(double hour, int type)
{
    if (vitality > 0 && !IsSleeping(hour))
    {
        if (type == 0)
        {
            vitality -= work0;
        }
        else
        {
            vitality -= work1;
        }
    }
}


