#include "ECAbstractConvexPolygon.h"
#include <iostream>

using namespace std;

//constructor
ECAbstractConvexPolygon::ECAbstractConvexPolygon(const std::vector<EC2DPoint> &listNodes){
	for(auto node : listNodes){
		this->AddNode(node);
	}
}    
bool ECAbstractConvexPolygon::IsPointInside(const EC2DPoint &pt) const{
	//calculate area with pt and each pair of nodes

	//check if pt.getx and pt.gety is equal to any of the nodes
	for (int i = 0; i < listNodes.size(); i++) {
		if (pt.GetX() == listNodes[i].GetX() && pt.GetY() == listNodes[i].GetY()) {
			return true;
		}
	}

	//check if pt is on line between any two nodes, if so return true
	for (int i = 0; i < listNodes.size(); i++) {
		int j = (i + 1) % listNodes.size();
		if (OnSegment(listNodes[i], listNodes[j], pt)) {
			return true;
		}
	}
	
	double totalArea = 0;
	for (int i = 0; i < listNodes.size(); i++){
		//calculate area of the triangle
		totalArea += CalculateArea(pt, listNodes[i], listNodes[(i+1)%listNodes.size()]);
	}
	//if the total area is equal to the polygon area, then the point is inside
	if (totalArea == GetArea()){
		return true;
	}
	return false;
}
//onsesgment function
bool ECAbstractConvexPolygon::OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
	if (pk.GetX() <= max(pi.GetX(), pj.GetX()) && pk.GetX() >= min(pi.GetX(), pj.GetX()) && pk.GetY() <= max(pi.GetY(), pj.GetY()) && pk.GetY() >= min(pi.GetY(), pj.GetY())) {
		return true;
	}
	return false;
}

//calculate area of the polygon
double ECAbstractConvexPolygon::CalculateArea(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const{
		double x1 = p1.GetX();
        double x2 = p2.GetX();
        double x3 = p3.GetX();
        double y1 = p1.GetY();
        double y2 = p2.GetY();
        double y3 = p3.GetY();

        return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
}

//is equal function
bool ECAbstractConvexPolygon::IsEqual(const ECAbstractConvexPolygon &rhs) const{
	//loop through the nodes of the polygon and rhs, if they are not equal return false
	for (int i = 0; i < listNodes.size(); i++) {
		if (listNodes[i].GetX() != rhs.listNodes[i].GetX() || listNodes[i].GetY() != rhs.listNodes[i].GetY()) {
			return false;
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

