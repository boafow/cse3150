#include "ECOrganism.h"

bool ECOrganism::IsSleeping(double hour){
        //If the hour is among the sleeping hours, then return true
        return (hour <= sleepEnd && hour >= sleepStart);
}

void ECOrganism::Work(double hour, int type){
	if(IsSleeping(hour) || vitality == 0) return;
	if(type == 0){
		vitality -= work0;
	} else if(type == 1){
		vitality -= work1;

	}
}

void ECOrganism::Eat(double hour){
	//If vitality is 0, or eatLimit has been reached, do nothing
	if(vitality == 0 || eatLimit == 0){ return; }
	//If the animal is not sleeping then eat and reduce eatLimit
	if(!IsSleeping(hour)){ vitality += recharge; eatLimit -= 1;}
	return;
}

