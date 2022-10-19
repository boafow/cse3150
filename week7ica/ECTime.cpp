#include "ECTime.h"

ECTime::ECTime(int h, int m, int s):hour(h), min(m), sec(s){};	// (hour, minute, second)
ECTime::~ECTime(){};
void ECTime::GetTime(int &h, int &m, int &s) const{
	h=hour;
	m=min;
	s=sec;
};
ECTime ECTime::operator+(const ECTime &tmToAdd){
	ECTime res(tmToAdd.hour, tmToAdd.min, tmToAdd.sec);
	res.sec += sec;
	int carry = 0;
	if(res.sec >= 60){
		carry = 1;
		res.sec -= 60;
	}
	res.min += carry;
	res.min += min;
	if(res.min >= 60){
		carry = 1;
		res.min -= 60;
	}
	res.hour += carry + hour;
	return res;
}
