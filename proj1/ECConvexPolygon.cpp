#include "ECConvexPolygon.h"
#include <cmath>
using namespace std;

// constructor
ECConvexPolygon::ECConvexPolygon(const std::vector<EC2DPoint> &nodes): ECAbstractConvexPolygon(nodes)
{
    this->nodes = nodes;
}

double ECConvexPolygon::CrossProduct(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const
{
    return ((pj.GetX() - pi.GetX()) * (pk.GetY() - pi.GetY())) - ((pk.GetX() - pi.GetX()) * (pj.GetY() - pi.GetY()));
}

bool ECConvexPolygon::IsConvex() const
{
    double prev = 0;
    double curr = 0;
    int N = nodes.size();

    for (int i = 0; i < N; i++)
    {

        int a = i;
        int b = (i + 1) % N;
        int c = (i + 2) % N;

        curr = CrossProduct(nodes[a], nodes[b], nodes[c]);

        if (curr != 0)
        {

            if (curr * prev < 0)
            {
                return false;
            }
            else
            {
                prev = curr;
            }
        }
    }
    return true;
}

double ECConvexPolygon::GetArea() const
{
    double totalArea = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        int j = (i + 1) % nodes.size();
        totalArea += nodes[i].GetX() * nodes[j].GetY() - nodes[j].GetX() * nodes[i].GetY();
    }
    return abs(totalArea / 2);
}
