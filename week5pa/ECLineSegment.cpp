#include "ECLineSegment.h"
#include <cmath>
#include <algorithm>
using namespace std;

// Point on 2D plane
EC2DPoint :: EC2DPoint(double x, double y){
	point.first = x;
	point.second = y;
}

double EC2DPoint :: GetX() const {
	return point.first;
}

double EC2DPoint :: GetY() const {
	return point.second;
}

// -----------------------------------------------------------------------------
// Line segment on 2D plane
ECLineSegment :: ECLineSegment(const EC2DPoint &pStart, const EC2DPoint &pEnd): segment(pStart, pEnd) {}

EC2DPoint ECLineSegment :: GetP1() const{
       return segment.first;
}

EC2DPoint ECLineSegment :: GetP2() const{
	return segment.second;
}

bool ECLineSegment :: IsIntersect(const ECLineSegment &rhs) const{
	EC2DPoint p1 = segment.first;
	EC2DPoint p2 = segment.second;
	EC2DPoint p3 = rhs.GetP1();
	EC2DPoint p4 = rhs.GetP2();

	double d1 = Direction(p3, p4, p1);
	double d2 = Direction(p3, p4, p2);
	double d3 = Direction(p1, p2, p3);
	double d4 = Direction(p1, p2, p4);

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))){
		return true;
	} else if(d1 == 0 && OnSegment(p3, p4, p1)){
		return true;
	} else if(d2 == 0 && OnSegment(p3, p4, p2)){
		return true;
	} else if(d3 == 0 && OnSegment(p1, p2, p3)){
		return true;
	} else if(d4 == 0 && OnSegment(p1, p2, p4)){
		return true;
	} else {
		return false;
	}
}

double ECLineSegment :: Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
	return ((pj.GetX() - pi.GetX()) * (pk.GetY() - pi.GetY())) - ((pk.GetX() - pi.GetX())*(pj.GetY() - pi.GetY()));
}

bool ECLineSegment :: OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
	if(((min(pi.GetX(), pj.GetX()) <= pk.GetX()) && (pk.GetX() <= max(pi.GetX(), pj.GetX())))
			&& ((min(pi.GetY(), pj.GetY()) <= pk.GetY()) && (pk.GetY() <= max(pi.GetY(), pj.GetY())))){
		return true;
	}
	return false;
}
