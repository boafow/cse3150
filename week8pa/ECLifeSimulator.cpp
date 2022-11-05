#include "ECLifeSimulator.h"
#include "ECOrganism.h"
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//implement operator< for ECDailyEvent
bool ECDailyEvent::operator<(const ECDailyEvent &rhs) const
{
	return hours < rhs.hours;
}

void ECLifeSimulator::Initialize()
{
	orgs.clear();
	events.clear();
}

int ECLifeSimulator::AddOrganism(ECOrganism *ptr)
{
	orgs.push_back(ptr);	// add pointer to organism to orgs
	return orgs.size() - 1; // return index
}

void ECLifeSimulator::AddDailyEvent(double hours, int indexOrganism, int type, int subtype)
{
	ECDailyEvent event(hours, indexOrganism, type, subtype);
	events.push_back(event);
	std::sort(events.begin(), events.end());
}

double ECLifeSimulator::Simulate(double hoursStart, double timeLimit)
{
	std::set<std::string> orgsAlive;
	//cout timestart and timne limit
	cout << "Time Start: " << hoursStart << endl;
	cout << "Time Limit: " << timeLimit << endl;
	double i = 0;
	for (auto org : orgs)
	{
		orgsAlive.insert(org->GetName());
	}

	//for event in events, cout each attribute
	for (auto event : events)
	{
		cout << orgs[event.indexOrganism]->GetName() << " : " << orgs[event.indexOrganism]->species << 
		" vitality " << orgs[event.indexOrganism]->vitality << 
		" hour " << event.hours << 
		" index " << event.indexOrganism << 
		" type " << event.type << 
		" type1 " << event.subtype << endl;
	}

	while (i + hoursStart < timeLimit)
	{
		for (auto event : events)
		{
			if (event.hours == fmod(i + hoursStart, 24.0))
			{

				if (event.type == 0)
				{
					//call eat if orgs[event.indexOrganism] eatLimit is not 0
					if (orgs[event.indexOrganism]->eatLimit != 0)
					{
						orgs[event.indexOrganism]->Eat(fmod(i + hoursStart, 24.0), orgs[event.indexOrganism]->recharge);
						//reduce eatLimit by 1
						orgs[event.indexOrganism]->eatLimit--;
					}
					//cout vitality after eating
					cout << orgs[event.indexOrganism]->GetName() << " vitality after eating: " << orgs[event.indexOrganism]->vitality << endl;
				}
				else
				{
					orgs[event.indexOrganism]->Work(fmod(i + hoursStart, 24.0), event.subtype);
					//cout vitality after working
					cout << orgs[event.indexOrganism]->GetName() << " vitality after working: " << orgs[event.indexOrganism]->vitality << endl;
				}
			}
		}
		GetAliveOrganisms(orgsAlive);
		if (orgsAlive.size() == 0)
		{
			return i;
		}
		i += 0.5;
	}

	return timeLimit;
}

void ECLifeSimulator::GetAliveOrganisms(std::set<string> &setAlives) const
{
	setAlives.clear();
	for (auto org : orgs)
	{
		if (GetVitalityFor(org->GetName()) > 0)
		{
			setAlives.insert(org->GetName());
		}
	}
}

double ECLifeSimulator::GetVitalityFor(const std::string &orgName) const
{
	for (auto org : orgs)
	{ 
		if (org->GetName() == orgName)
		{
			if (org->vitality > 0)
			{
				return org->vitality;
			}
		}
	}
	return 0;
}
