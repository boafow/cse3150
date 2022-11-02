#include "ECSpider.h"


void ECSpider::Work(double hour, int type){
	if(vitality > 0 && !IsSleeping(hour)){
		if(type == 0){
			vitality -= work0;
		} else {
			vitality -= work1;
			weave(prey);
		}
	}
}

void ECSpider::weave(ECOrganism* rhs){
	if(rhs == nullptr) return;
	ECArthopods * arth = dynamic_cast<ECArthopods *>(rhs);
	if(arth != NULL){ rhs->vitality == 0; }
}
