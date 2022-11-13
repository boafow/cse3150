#include "ECConvexPolygon.h"
#include <cmath>
using namespace std;

bool ECConvexPolygon::IsConvex() const
{
    double prev = 0;
    double curr = 0;
    int N = listNodes.size();

    for (int i = 0; i < N; ++i)
    {

        int a = i;
        int b = (i + 1) % N;
        int c = (i + 2) % N;

        curr = CrossProduct(listNodes[a], listNodes[b], listNodes[c]);

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
    for (int i = 0; i < listNodes.size(); i++)
    {
        int j = (i + 1) % listNodes.size();
        totalArea += listNodes[i].GetX() * listNodes[j].GetY() - listNodes[j].GetX() * listNodes[i].GetY();
    }
    return abs(totalArea / 2);
}

