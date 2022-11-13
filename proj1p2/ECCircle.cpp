#include "ECCircle.h"
#include <cmath>
using namespace std;

//*************************************************************************************
// Circle

void ECCircle::GetBoundingBox(double &xMin, double &xMax, double &yMin, double &yMax) const
{
    xMin = xcenter - radius;
    xMax = xcenter + radius;
    yMin = ycenter - radius;
    yMax = ycenter + radius;
}

bool ECCircle::IsPointInside(const EC2DPoint &p) const
{
    double x = p.GetX();
    double y = p.GetY();
    double x0 = xcenter;
    double y0 = ycenter;
    double r = radius;

    return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r;
}

void ECCircle::GetCenter(double &xc, double &yc) const
{
    double xMin, xMax, yMin, yMax;
    GetBoundingBox(xMin, xMax, yMin, yMax);
    xc = (xMin + xMax) / 2;
    yc = (yMin + yMax) / 2;
}

double ECCircle::GetArea() const
{
    return M_PI * radius * radius;
}

//*************************************************************************************
// Ellipse

// your code here

void ECEllipse::GetBoundingBox(double &xMin, double &xMax, double &yMin, double &yMax) const
{
    xMin = xcenter - radiusx;
    xMax = xcenter + radiusx;
    yMin = ycenter - radiusy;
    yMax = ycenter + radiusy;
}

bool ECEllipse::IsPointInside(const EC2DPoint &p) const
{
    double x = p.GetX();
    double y = p.GetY();
    double x0 = xcenter;
    double y0 = ycenter;
    double rx = radiusx;
    double ry = radiusy;

    return (x - x0) * (x - x0) / (rx * rx) + (y - y0) * (y - y0) / (ry * ry) <= 1;
}

void ECEllipse::GetCenter(double &xc, double &yc) const
{
    double xMin, xMax, yMin, yMax;
    GetBoundingBox(xMin, xMax, yMin, yMax);
    xc = (xMin + xMax) / 2;
    yc = (yMin + yMax) / 2;
}

double ECEllipse::GetArea() const
{
    return M_PI * radiusx * radiusy;    
}