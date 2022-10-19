#include "ECAbstractConvexPolygon.h"
#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------
// Convex polygon on 2D plane: interface class
// your code here

ECAbstractConvexPolygon();
    
ECAbstractConvexPolygon(const std::vector<EC2DPoint> &listNodes);
    
virtual bool IsConvex() const = 0;
    
virtual double GetArea() const = 0;
    
bool IsPointInside(const EC2DPoint &pt) const;
    
bool IsContaining(const ECAbstractConvexPolygon &rhs) const;
    
bool IsIntersecting(const ECAbstractConvexPolygon &rhs) const;

