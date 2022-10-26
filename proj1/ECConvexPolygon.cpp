#include "ECConvexPolygon.h"
#include <cmath>
using namespace std;

//constructor
ECConvexPolygon::ECConvexPolygon(const std::vector<EC2DPoint> &nodes){
    for(auto node : nodes){
        this->AddNode(node);
    }
}

double ECConvexPolygon::CrossProduct(double ax, double ay, double bx, double by, double cx, double cy) const
{
        int BAx = ax - bx;
        int BAy = ay - by;
        int BCx = cx - bx;
        int BCy = cy - by;
        return (BAx * BCy - BAy * BCx);
}

bool ECConvexPolygon::IsConvex() const
{

    int N = nodes.size();
 
    double prev = 0;
 
    double curr = 0;
 
    for (int i = 0; i < N; i++) {

        vector<EC2DPoint> temp
            = { nodes[i],
                nodes[(i + 1) % N],
                nodes[(i + 2) % N] };
 
        curr = CrossProduct(nodes[i].GetX(), nodes[i].GetY(), nodes[(i + 1) % N].GetX(), nodes[(i + 1) % N].GetY(), nodes[(i + 2) % N].GetX(), nodes[(i + 2) % N].GetY());
 
        if (curr != 0) {
 
            if (curr * prev < 0) {
                return false;
            }
            else {
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
