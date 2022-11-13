#include "ECTriangle.h"
#include <cmath>
using namespace std;


double ECTriangle::GetArea()  const{
        double x1 = p1.GetX();
        double x2 = p2.GetX();
        double x3 = p3.GetX();
        double y1 = p1.GetY();
        double y2 = p2.GetY();
        double y3 = p3.GetY();

        return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
}

//direction of the point p3 from the line p1-p2
int ECTriangle::Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
        return ((pj.GetX() - pi.GetX()) * (pk.GetY() - pi.GetY())) - ((pk.GetX() - pi.GetX()) * (pj.GetY() - pi.GetY()));
}

bool ECTriangle::IsConvex() const{
        //check if the triangle is convex
        int d1 = Direction(p1, p2, p3);
        int d2 = Direction(p2, p3, p1);
        int d3 = Direction(p3, p1, p2);
        return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
}
