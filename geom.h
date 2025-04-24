#pragma once

#include <iostream>

//---------- struct Point --------------------

struct Point {
    double x = 0.0;
    double y = 0.0;
};

Point ReadPoint();

void PrintPoint(Point p);

//---------- struct Vector2D --------------------

struct Vector2D{
    double x = 0, y = 0;
};

Vector2D PointDifference(Point p1, Point p2);

void PrintVector(Vector2D v);
double FindLength(Vector2D v);

//---------- struct Triangle --------------------

struct Triangle{
    Point p1, p2, p3;
};

Triangle ReadTriangle();

double FindPerimeter(const Triangle& t);