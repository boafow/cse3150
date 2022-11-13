#ifndef ECConvexPolygon_h
#define ECConvexPolygon_h

#include <vector>
#include "ECLineSegment.h"
#include "ECAbstractConvexPolygon.h"

class ECConvexPolygon : public ECAbstractConvexPolygon
{
public:
    ECConvexPolygon(const std::vector<EC2DPoint> &listNodes): ECAbstractConvexPolygon(listNodes){};
    bool IsConvex() const;
    double GetArea() const;
};

#endif
