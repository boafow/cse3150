#include "ECTriangle.h"
#include <cmath>
#include <vector>
using namespace std;

// your code goes here
ECTriangle :: ECTriangle(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3){
	triangle.push_back(p1);
	triangle.push_back(p2);
	triangle.push_back(p3);
}

EC2DPoint ECTriangle :: GetP1() const{
	return triangle[0];
}

EC2DPoint ECTriangle :: GetP2() const{
	return triangle[1];
}

EC2DPoint ECTriangle :: GetP3() const{
	return triangle[2];
}

double ECTriangle :: GetArea() const {
	double x1 = triangle[0].GetX();
	double x2 = triangle[1].GetX();
	double x3 = triangle[2].GetX();
	double y1 = triangle[0].GetY();
	double y2 = triangle[1].GetY();
	double y3 = triangle[2].GetY();

	return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
}

double ECTriangle :: CalculateArea(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const{
	double x1 = p1.GetX();
        double x2 = p2.GetX();
        double x3 = p3.GetX();
        double y1 = p1.GetY();
        double y2 = p2.GetY();
        double y3 = p3.GetY();

        return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
}

bool ECTriangle :: IsPointInside(const EC2DPoint &pt) const {
	auto v1 = triangle[0];
	auto v2 = triangle[1];
	auto v3 = triangle[2];

	auto a1 = CalculateArea(pt, v1, v2);
	auto a2 = CalculateArea(pt, v2, v3);
	auto a3 = CalculateArea(pt, v1, v3);
	auto a  = CalculateArea(v1, v2, v3);

	return (a == a1 + a2 + a3);
}

double ECTriangle :: Direction(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const {
	return ((p1.GetX() - p3.GetX()) * (p2.GetY() - p3.GetY())-
		(p2.GetX() - p3.GetX()) * (p1.GetY() - p3.GetY()));
}

bool ECTriangle :: IsContaining(const ECTriangle &rhs) const {
	auto p1 = rhs.GetP1();
	auto p2 = rhs.GetP2();
	auto p3 = rhs.GetP3();
	return (IsPointInside(p1) && IsPointInside(p2) && IsPointInside(p3));
}

bool ECTriangle :: IsIntersecting(const ECTriangle &rhs) const {

	auto v1 = triangle[0];
	auto v2 = triangle[1];
	auto v3 = triangle[2];
	auto u1 = rhs.GetP1();
	auto u2 = rhs.GetP2();
	auto u3 = rhs.GetP3();
	ECTriangle t1(v1, v2, v3);
	if(IsContaining(rhs) || rhs.IsContaining(t1)) return true;

	ECLineSegment l1(v1,v2);
	ECLineSegment l2(v2,v3);
	ECLineSegment l3(v3,v1);
	ECLineSegment l4(u1,u2);
	ECLineSegment l5(u2,u3);
	ECLineSegment l6(u3,u1);

	vector<ECLineSegment> vlines{l1, l2, l3};
	vector<ECLineSegment> ulines{l4, l5, l6};

	for(auto vline : vlines){
		for(auto uline : ulines){
			if(vline.IsIntersect(uline)){
				return true;
			}
		}
	}

	return false;

}

