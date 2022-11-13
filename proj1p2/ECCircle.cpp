#include "ECCircle.h"
#include <iostream>
#include <cmath>
using namespace std;

//*************************************************************************************
// Circle

void ECCircle::GetBoundingBox(double &xUpperLeft, double &yLowerRight, double &xLowerRight, double &yUpperLeft) const
{
    xUpperLeft = xcenter - radius;
    yUpperLeft = ycenter + radius;
    xLowerRight = xcenter + radius;
    yLowerRight = ycenter - radius;

    //print out the bounding box
    cout << "Bounding Box: " << endl;
	cout << "Upper Left: (x: " << xUpperLeft << ", y: " << yUpperLeft << ")" << endl;
	cout << "Lower Right: (x: " << xLowerRight << ", y: " << yLowerRight << ")" << endl;

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
    double xUpperLeft, xLowerRight, yUpperLeft, yLowerRight;
    GetBoundingBox(xUpperLeft, xLowerRight, yUpperLeft, yLowerRight);
    xc = (xUpperLeft + yUpperLeft) / 2;
    yc = (xLowerRight + yLowerRight) / 2;
}

double ECCircle::GetArea() const
{
    return M_PI * radius * radius;
}

//*************************************************************************************
// Ellipse

// your code here

void ECEllipse::GetBoundingBox(double &xUpperLeft, double &yLowerRight, double &xLowerRight, double &yUpperLeft) const
{
    xUpperLeft = xcenter - radiusx;
    yUpperLeft = ycenter + radiusy;
    xLowerRight = xcenter + radiusx;
    yLowerRight = ycenter - radiusy;

    //print out the bounding box
    cout << "Bounding Box: " << endl;
    cout << "Upper Left: (x: " << xUpperLeft << ", y: " << yUpperLeft << ")" << endl;
    cout << "Lower Right: (x: " << xLowerRight << ", y: " << yLowerRight << ")" << endl;
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

//get the center of the bounding box using the GetBoundingBox function and xUpperLeft, xLowerRight, yUpperLeft, yLowerRight
void ECEllipse::GetCenter(double &xc, double &yc) const
{
    double xUpperLeft, xLowerRight, yUpperLeft, yLowerRight;
    GetBoundingBox(xUpperLeft, xLowerRight, yUpperLeft, yLowerRight);
    xc = (xUpperLeft + yUpperLeft) / 2;
    yc = (xLowerRight + yLowerRight) / 2;
}

double ECEllipse::GetArea() const
{
    return M_PI * radiusx * radiusy;    
}