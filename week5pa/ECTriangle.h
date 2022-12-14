#ifndef ECTriangle_h
#define ECTriangle_h

#include "ECLineSegment.h"
#include <vector>
class ECTriangle
{
public:
    ECTriangle(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3);

    EC2DPoint GetP1() const;
    EC2DPoint GetP2() const;
    EC2DPoint GetP3() const;

    // Get area of the triangle
    double GetArea() const;
    
    // Test if a point is inside the triangle (if on the edge, consider it is inside)
    bool IsPointInside(const EC2DPoint &pt) const;
    
    // Test if the passed-in triangle is contained within this triangle
    // again, if the triangle (rhs) has vertex on the side of this triangle, it is allowed (considered to be contained)
    bool IsContaining(const ECTriangle &rhs) const;
    
    // Test if two triangles intersects (i.e. has non-empty common area)
    bool IsIntersecting(const ECTriangle &rhs) const;
    
private:
    std::vector<EC2DPoint> triangle;
    double Direction(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const;
    double CalculateArea(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const;
};


#endif /* ECTriangle_h */
