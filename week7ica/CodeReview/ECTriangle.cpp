// Part of ECTriangle.cpp
bool ECTriangle::IsPointInside(const EC2DPoint &pt) const{
    double area1 = GetArea();
    double area2 = area(pt.x, pt.y, t2.x, t2.y, t3.x, t3.y);
    double area3 = area(t1.x, t1.y, pt.x, pt.y, t3.x, t3.y);
    double area4 = area(t1.x, t1.y, t2.x, t2.y, pt.x, pt.y);
    return (area1 == area2 + area3 + area4);
}

bool ECTriangle::IsContaining(const ECTriangle &rhs) const{
    const EC2DPoint t1 = rhs.t1;
    const EC2DPoint t2 = rhs.t2;
    const EC2DPoint t3 = rhs.t3;
    bool p1 = IsPointInside(t1);
    bool p2 = IsPointInside(t2);
    bool p3 = IsPointInside(t3);
    if(p1 && p2 && p3){
        return true;
    }
    return false;
}

bool ECTriangle::IsIntersecting(const ECTriangle &rhs) const{
    if(t1.x == rhs.t1.x && t1.y == rhs.t1.y){
        return true;
    }
    if(t1.x == rhs.t2.x && t1.y == rhs.t2.y){
        return true;
    }
    if(t1.x == rhs.t3.x && t1.y == rhs.t3.y){
        return true;
    }
    if(t2.x == rhs.t2.x && t2.y == rhs.t2.y){
        return true;
    }
    if(t2.x == rhs.t3.x && t2.y == rhs.t3.y){
        return true;
    }
    if(t3.x == rhs.t3.x && t3.y == rhs.t3.y){
        return true;
    }


    ECLineSegment t1t2(t1, t2);
    ECLineSegment t1t3(t1, t3);
    ECLineSegment t2t3(t2, t3);

    ECLineSegment t1t2_(rhs.t1, rhs.t2);
    ECLineSegment t1t3_(rhs.t1, rhs.t3);
    ECLineSegment t2t3_(rhs.t2, rhs.t3);

    bool res1 = t1t2.IsIntersect(t1t2_);
    bool res2 = t1t2.IsIntersect(t1t3_);
    bool res3 = t1t2.IsIntersect(t2t3_);
    bool res4 = t1t3.IsIntersect(t1t3_);
    bool res5 = t1t3.IsIntersect(t2t3_);
    bool res6 = t2t3.IsIntersect(t2t3_);

    if(res1 || res2 || res3 || res4 || res5 || res6){
        return true;
    }
    return false;    
}

