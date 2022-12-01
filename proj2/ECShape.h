#ifndef ECSHAPE_H
#define ECSHAPE_H

#include <vector>
#include <map>
#include <iostream>

class ECShape
{
public:
    virtual ~ECShape() {}
};

class ECRectangle : public ECShape
{
    int x1, y1, x2, y2;
    bool filled;

public:
    ECRectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2), filled(false){};
};

class ECCircle : public ECShape
{
    int xcenter, ycenter;
    double radius;
    bool filled;

public:
    ECCircle(int xcenter, int ycenter, double radius) : xcenter(xcenter), ycenter(ycenter), radius(radius), filled(false){};
};

class ECEllipse : public ECShape
{
    int xcenter, ycenter;
    double radiusx, radiusy;
    bool filled;

public:
    ECEllipse(int xcenter, int ycenter, double radiusx, double radiusy) : xcenter(xcenter), ycenter(ycenter), radiusx(radiusx), radiusy(radiusy), filled(false){};
};

#endif /* ECSHAPE_H */