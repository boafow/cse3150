#include <iostream>
#include "ECLineSegment.h"
int main() {
	EC2DPoint p1 = EC2DPoint(0,5);
	EC2DPoint p2 = EC2DPoint(5,0);
	EC2DPoint p3 = EC2DPoint(2,4);
	EC2DPoint p4 = EC2DPoint(5,5);

	ECLineSegment l1 = ECLineSegment(p1, p2);
	ECLineSegment l2 = ECLineSegment(p3, p4);

	std::cout << l1.IsIntersect(l2) << std::endl;

	return 0;
}
