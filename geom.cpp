#include <cmath>
#include "geom.h"

//---------- struct Point --------------------

Point ReadPoint(){
    Point p;
    std::cin >> p.x >> p.y;
    return p;
}

void PrintPoint(Point p){
    std::cout << '{' << p.x << ", " << p.y << '}';
}

//---------- struct Vector2D --------------------

Vector2D PointDifference(Point p1, Point p2){
    return {p2.x - p1.x, p2.y - p1.y};
}

void PrintVector(Vector2D v){
    std::cout << '(' << v.x << ", " << v.y << '}';
}

double FindLength(Vector2D v){
    return std::hypot(v.x, v.y);
}

//---------- struct Triangle --------------------

Triangle ReadTriangle(){
    Triangle t;
    std::cin >> t.p1.x >> t.p1.y >> t.p2.x >> t.p2.y >> t.p3.x >> t.p3.y;
    return t;
}

double FindPerimeter(const Triangle& t){
    return FindLength(PointDifference(t.p1, t.p2)) +
        FindLength(PointDifference(t.p2, t.p3)) +
        FindLength(PointDifference(t.p3, t.p1));
}
