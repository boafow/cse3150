#ifndef ECAbstractConvexPolygon_h
#define ECAbstractConvexPolygon_h

#include <vector>
#include "ECLineSegment.h"

class ECAbstractConvexPolygon
{
public:
    ECAbstractConvexPolygon(){};
    
    // ordered sequentially (either clockwise or counter clockwise
    ECAbstractConvexPolygon(const std::vector<EC2DPoint> &listNodes);
    
    // Test if the polygon is convex? Return false if not
    // NOTE: ALL OTHER METHODS OF THIS CLASS ASSUME THE POLYGON IS CONVEX
    virtual bool IsConvex() const = 0;
    
    // Calculate total area of the polygon (you can assume it is indeed convex)
    virtual double GetArea() const = 0;
    
    // Test if a point is inside the polygon (if on the edge, consider it is inside)
    bool IsPointInside(const EC2DPoint &pt) const;
    
    // Test if the passed-in polygon is contained within this polygon
    // again, if the polygon (rhs) has vertex on the side of this polygon, it is allowed (considered to be contained)
    bool IsContaining(const ECAbstractConvexPolygon &rhs) const;
    
    // Test if two polygons intersect (i.e. has non-empty common area)
    bool IsIntersecting(const ECAbstractConvexPolygon &rhs) const;
    
    // add node (should add sequentially)
    void AddNode(const EC2DPoint &node) { listNodes.push_back(node); }
    
    // Your code here...
    //calculate area of the polygon
    double CalculateArea(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3) const;
    bool OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
    bool IsEqual(const ECAbstractConvexPolygon &rhs) const;
    bool IsIntersect(const ECLineSegment &line1, const ECLineSegment &line2) const;
    double CrossProduct(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
private:
    std::vector<EC2DPoint> listNodes;
};


#endif
