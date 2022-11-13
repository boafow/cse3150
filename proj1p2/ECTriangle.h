#ifndef ECTriangle_h
#define ECTriangle_h

#include "ECLineSegment.h"
#include "ECAbstractConvexPolygon.h"

class ECTriangle : public ECAbstractConvexPolygon
{
public:
    ECTriangle(const EC2DPoint& p1, const EC2DPoint& p2, const EC2DPoint& p3): p1(p1), p2(p2), p3(p3){
        this->AddNode(p1);
        this->AddNode(p2);
        this->AddNode(p3);
    };
    virtual bool IsConvex() const;
    virtual double GetArea() const;
    //direction of the point p3 from the line p1-p2
    int Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
private:
    EC2DPoint p1;
    EC2DPoint p2;
    EC2DPoint p3;
};


#endif
