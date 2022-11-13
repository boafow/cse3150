#include <iostream>
#include <cmath>
#include "ECCircle.h"
#include "ECTriangle.h"
#include "ECAbstractConvexPolygon.h"
#include "ECLineSegment.h"
#include "ECAbstract2DShape.h"
#include "ECConvexPolygon.h"
using namespace std;

int main()
{
    // test code

    EC2DPoint p1(0, 0), p2(0, 2), p3(2, 0), p4(2, 2), p5(3, 1), p6(3, 2), p7(3, 0), p8(5, 2), p9(9, 0);
    vector<EC2DPoint> listNodes1, listNodes2, listNodes3, listNodes4, listNodes5, listNodes6;
    double xul, yul, xlr, ylr;

    listNodes1.push_back(p6);
    listNodes1.push_back(p8);
    listNodes1.push_back(p9);
    listNodes1.push_back(p7);
    ECConvexPolygon poly1(listNodes1);
    poly1.GetBoundingBox(xul, yul, xlr, ylr);
    cout << (xul == 3) << endl;
    cout << (yul == 0) << endl;
    cout << (xlr == 9) << endl;
    cout << (ylr == 2) << endl;

    ECAbstract2DShape *cir1 = new ECCircle(0, 0, 1);
    cir1->GetBoundingBox(xul, yul, xlr, ylr);
    cout << (xul == -1) << endl;
    cout << (yul == -1) << endl;
    cout << (xlr == 1) << endl;
    cout << (ylr == 1)  << endl;
    delete cir1;

    ECAbstract2DShape *ecl1 = new ECEllipse(0, 0, 1, 2);
    ecl1->GetBoundingBox(xul, yul, xlr, ylr);
    cout << (xul == -1) << endl;
    cout << (yul == -2) << endl;
    cout << (xlr == 1) << endl;
    cout << (ylr == 2) << endl;
    delete ecl1;

    //my ymax and xmin are swapped
    ECAbstract2DShape *tri1 = new ECTriangle(p1, p2, p3);
    tri1->GetBoundingBox(xul, yul, xlr, ylr);
    cout << (xul == 0) << endl;
    cout << (yul == 0) << endl;
    cout << (xlr == 2) << endl;
    cout << (ylr == 2) << endl;
    delete tri1;
    return 0;
}