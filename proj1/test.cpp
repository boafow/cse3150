#include "ECTriangle.h"
#include "ECConvexPolygon.h"
#include "ECAbstractConvexPolygon.h"
#include "ECLineSegment.h"
#include <iostream>
using namespace std;

int main()
{
	EC2DPoint p1(0, 0), p2(2, 2), p3(5, 3), p4(5, 0), p5(8, 2), p6(10, 0), p7(5, -3);
	vector<EC2DPoint> listNodes1, listNodes2, listNodes3, listNodes4, listNodes5, listNodes6;

	listNodes1.push_back(p1);
	listNodes1.push_back(p2);
	listNodes1.push_back(p5);
	listNodes1.push_back(p4);
	ECConvexPolygon poly1(listNodes1);

	listNodes2.push_back(p3);
	listNodes2.push_back(p4);
	listNodes2.push_back(p6);
	listNodes2.push_back(p5);
	ECConvexPolygon poly2(listNodes2);

	listNodes3.push_back(p4);
	listNodes3.push_back(p6);
	listNodes3.push_back(p7);
	ECConvexPolygon poly3(listNodes3);

	cout << ( poly1.IsIntersecting(poly2) == true) << endl;
	cout << ( poly2.IsIntersecting(poly1) == true) << endl;
	cout << ( poly2.IsIntersecting(poly3) == true) << endl;
	cout << ( poly3.IsIntersecting(poly2) == true) << endl;
	cout << ( poly1.IsIntersecting(poly3) == true) << endl;
	cout << ( poly3.IsIntersecting(poly1) == true) << endl;

	// test triangle intersection
	// here, intersection occurs at edge
	EC2DPoint pa1(0, 0), pa2(2, 2), pa3(5, 0);
	EC2DPoint pa4(1, 1), pa5(0, -1), pa6(4, -1);
	vector<EC2DPoint> listNodes1a, listNodes2a;

	listNodes1a.push_back(pa1);
	listNodes1a.push_back(pa2);
	listNodes1a.push_back(pa3);
	ECConvexPolygon poly1a(listNodes1a);

	listNodes2a.push_back(pa4);
	listNodes2a.push_back(pa5);
	listNodes2a.push_back(pa6);
	ECConvexPolygon poly2a(listNodes2a);
	cout << ( poly1a.IsIntersecting(poly2a) == true) << endl;
	cout << ( poly2a.IsIntersecting(poly1a) == true) << endl;

	// here, intersection is one containing the other
	EC2DPoint pb1(0, 0), pb2(3, 10), pb3(15, 0);
	EC2DPoint pb4(1, 1), pb5(2, 2), pb6(3, 1);
	vector<EC2DPoint> listNodes1b, listNodes2b;

	listNodes1a.push_back(pb1);
	listNodes1a.push_back(pb2);
	listNodes1a.push_back(pb3);
	ECConvexPolygon poly1b(listNodes1b);

	listNodes2a.push_back(pb4);
	listNodes2a.push_back(pb5);
	listNodes2a.push_back(pb6);
	ECConvexPolygon poly2b(listNodes2b);
	cout << ( poly1b.IsIntersecting(poly2b) == true) << endl;
	cout << ( poly2b.IsIntersecting(poly1b) == true) << endl;
}
