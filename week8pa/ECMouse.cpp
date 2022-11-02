#include "ECMouse.h"


void ECMouse::Work(double hour, int type){
        if(vitality > 0 && !IsSleeping(hour)){
                if(type == 0){
                        vitality -= work0;
                } else {
                        vitality -= work1;
                        hunt(prey);
                }
        }
}

void ECSpider::weave(const ECOrganism *rhs){
        if(rhs == NULL) return;
        ECGrasshopper * grasshopper = dynamic_cast<ECGrasshopper *>(rhs);
        if(grasshopper != NULL){ rhs->vitality == 0; }
}

