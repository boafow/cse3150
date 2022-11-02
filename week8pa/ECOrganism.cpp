#include "ECOrganism.h"

bool ECArthopods::IsSleeping(double hour) const{
        //If the hour is among the sleeping hours, then return truei
	if(sleepEnd < sleepStart){
		double newEnd = sleepEnd + 24;
		return ((hour + 24) <= newEnd && (hour + 24) >= sleepStart);
	}
        return (hour <= sleepEnd && hour >= sleepStart);
}

void ECArthopods::Eat(double hour, int recharge = 0){
	//If vitality is 0, or eatLimit has been reached, do nothing
	if(vitality == 0 || eatLimit == 0){ return; }
	//If the animal is not sleeping then eat and reduce eatLimit
	else if(!IsSleeping(hour)){ vitality += recharge; eatLimit -= 1;}
}

double ECArthopods::GetVit(){
	return vitality;
}

bool ECMammals::IsSleeping(double hour) const {
        //If the hour is among the sleeping hours, then return truei
        if(sleepEnd < sleepStart){
                double newEnd = sleepEnd + 24;
                return ((hour + 24) <= newEnd && (hour + 24) >= sleepStart);
	}
        return (hour <= sleepEnd && hour >= sleepStart);
}

void ECMammals::Eat(double hour, int recharge = 0){
        //If vitality is 0, or eatLimit has been reached, do nothing
        if(vitality == 0 || eatLimit == 0){ return; }
        //If the animal is not sleeping then eat and reduce eatLimit
        else if(!IsSleeping(hour)){ vitality += recharge; eatLimit -= 1;}
}

double ECMammals::GetVit(){
        return vitality;
}

