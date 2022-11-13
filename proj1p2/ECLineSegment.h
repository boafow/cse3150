#ifndef ECLineSegment_h
#define ECLineSegment_h

#include <utility>

class EC2DPoint
{
public:
    EC2DPoint(double x, double y);
    double GetX() const;
    double GetY() const;

private:
    std::pair<double, double> point;
};


class ECLineSegment
{
public:
    ECLineSegment(const EC2DPoint &pStart, const EC2DPoint &pEnd);

    // Is this segment intersect with the other?
    bool IsIntersect(const ECLineSegment &rhs) const;
    double GetSlope() const;
    EC2DPoint GetP1() const;
    EC2DPoint GetP2() const;
private:
    std::pair<EC2DPoint, EC2DPoint> segment;

    bool OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;

    double Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
};


#endif

