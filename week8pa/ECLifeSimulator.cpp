#include "ECLifeSimulator.h"
#include "ECSpider.h"
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

void ECLifeSimulator::Initialize(){
	orgs.clear();
	events.clear();
}

int ECLifeSimulator::AddOrganism(ECOrganism *ptr){
	orgs.push_back(ptr); //add pointer to organism to orgs
	return orgs.size()-1; //return index
}

void ECLifeSimulator::AddDailyEvent(double hours, int indexOrganism, int type, int subtype) {
	ECDailyEvent event(hours, indexOrganism, type, subtype);
	events.push_back(&event);
}

double ECLifeSimulator::Simulate(double hoursStart, double timeLimit){
	std::set<std::string> orgsAlive;
	cout << orgs[0]->name << endl;
	int countAlive = 0;
	double currentHours;
	for(int i = hoursStart; i < timeLimit; ++i){
		currentHours = i;
		for(auto event : events){
			if(event->type == 0){
				orgs[event->indexOrganism]->Eat(fmod(currentHours, 24.0));
			} else {
				orgs[event->indexOrganism]->Work(fmod(currentHours, 24.0), event->subtype);
			}
			
		}
		for(auto org : orgs){
			if(org->vitality > 0) countAlive += 1;
		}
		if(countAlive == 0){
			return (currentHours - hoursStart);
		}
		
	}
	return (timeLimit - hoursStart);
}	

void ECLifeSimulator::GetAliveOrganisms(std::set<string> &setAlives) const {
	setAlives.clear();
	for(auto organism : orgs){
		if(organism->vitality > 0){
			setAlives.insert(organism->name);
		}
	}
}

double ECLifeSimulator::GetVitalityFor(const std::string &orgName) const {
	for(auto org : orgs){
		cout <<  "name: " << dynamic_cast<ECArthopods *>(org)->name << endl;
		cout <<  "vitality: " << org->vitality << endl;
		cout <<  "eatlimit: " << org->eatLimit << endl;
		if(org->name == orgName){
			return org->vitality;
		}
	}
}


