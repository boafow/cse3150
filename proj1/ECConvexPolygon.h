#ifndef ECConvexPolygon_h
#define ECConvexPolygon_h

#include <vector>
#include "ECLineSegment.h"
#include "ECAbstractConvexPolygon.h"

class ECConvexPolygon : public ECAbstractConvexPolygon
{
public:
    ECConvexPolygon(const std::vector<EC2DPoint> &nodes);
    virtual bool IsConvex() const;
    virtual double GetArea() const;
    //implement direction of the line
    double CrossProduct(double ax, double ay, double bx, double by, double cx, double cy) const;

private:
    std::vector<EC2DPoint> nodes;
};

#endif
