#include "ECAbstractConvexPolygon.h"
#include <iostream>

using namespace std;

//constructor   
bool ECAbstractConvexPolygon::IsPointInside(const EC2DPoint &pt) const{
	double before = 0;
	double current = 0;
	int n = listNodes.size();
	for(int i = 0; i < n; ++i){
		int a = i;
		int b = (i + 1) % n;
		current = CrossProduct(pt, listNodes[a], listNodes[b]);
		if(current != 0){
			if(current * before < 0){
				return false;
			} else {
				before = current;
			}
		}
	}
	return true;
}

bool ECAbstractConvexPolygon::IsContaining(const ECAbstractConvexPolygon &rhs) const{
	//check if the rhs is inside the polygon
	for (int i = 0; i < rhs.listNodes.size(); i++) {
		if (!IsPointInside(rhs.listNodes[i])) {
			return false;
		}
	}
	return true;
}
    
bool ECAbstractConvexPolygon::IsIntersecting(const ECAbstractConvexPolygon &rhs) const {
	//make line segments from the vertices of rhs
	int n = rhs.listNodes.size();
	vector<ECLineSegment> rhsLineSegments;
	for(int i = 0; i < n; i++){
		rhsLineSegments.push_back(ECLineSegment(rhs.listNodes[i], rhs.listNodes[(i+1)%n]));
	}

	//make line segments from the vertices of this
	n = listNodes.size();
	vector<ECLineSegment> thisLineSegments;
	for(int i = 0; i < n; i++){
		thisLineSegments.push_back(ECLineSegment(listNodes[i], listNodes[(i+1)%n]));
	}

	//return true if iscontaining rhs or if rhs iscpntaining this
	if(IsContaining(rhs) || rhs.IsContaining(*this)){
		return true;
	}

	for ( auto rhsSegment: rhsLineSegments){
		for ( auto thisSegment: thisLineSegments){
			if(rhsSegment.IsIntersect(thisSegment)){
				return true;
			}
		}
	}
	return false;
}

double ECAbstractConvexPolygon::CrossProduct(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
	return (pk.GetY() - pi.GetY()) * (pj.GetX() - pi.GetX()) - (pj.GetY() - pi.GetY()) * (pk.GetX() - pi.GetX());
}

void ECAbstractConvexPolygon::GetBoundingBox(double &xUpperLeft, double &yUpperLeft, double &xLowerRight, double &yLowerRight) const{
	xUpperLeft = listNodes[0].GetX();
	yUpperLeft = listNodes[0].GetY();
	xLowerRight = listNodes[0].GetX();
	yLowerRight = listNodes[0].GetY();

	for (int i = 1; i < listNodes.size(); i++) {
		if (listNodes[i].GetX() < xUpperLeft) {
			xUpperLeft = listNodes[i].GetX();
		}
		if (listNodes[i].GetY() > yUpperLeft) {
			yUpperLeft = listNodes[i].GetY();
		}
		if (listNodes[i].GetX() > xLowerRight) {
			xLowerRight = listNodes[i].GetX();
		}
		if (listNodes[i].GetY() < yLowerRight) {
			yLowerRight = listNodes[i].GetY();
		}
	}
}

void ECAbstractConvexPolygon::GetCenter(double &xc, double &yc) const{
	double xUpperLeft, yUpperLeft, xLowerRight, yLowerRight;
	GetBoundingBox(xUpperLeft, yUpperLeft, xLowerRight, yLowerRight);
	xc = (xUpperLeft + xLowerRight) / 2;
	yc = (yUpperLeft + yLowerRight) / 2;
}
