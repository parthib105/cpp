// Calculate the distance between two points using classes and constructors
#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    double x, y;
    friend void distance(Point, Point);
    public:
        Point(double a, double b)
        {
            x = a;
            y = b;
        }
};

void distance(Point p1, Point p2)
{
    cout << "The distance between the given points = " << sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)) << endl;
}

int main()
{
    Point x1(3, 4), x2(7, 2);
    distance(x1, x2);
    return 0;
}