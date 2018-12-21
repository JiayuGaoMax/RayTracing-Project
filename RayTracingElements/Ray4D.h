//
// Created by galax on 10/6/2018.
//

#ifndef ASSIGNMENT2_RAY4D_H
#define ASSIGNMENT2_RAY4D_H

#include "MathLibrary/Point4D.h"
#include "MathLibrary/Vector4D.h"

class Ray4D {
private:
    Point4D o;
    Vector4d d;
public:
    Ray4D();

    Ray4D(Point4D origin, Vector4d direction);

    Point4D getOrigin();

    Vector4d getDirection();

    static Ray4D getReflectionRay(Point4D NewStartPoint, Vector4d RayDirection, Vector4d Normal);

    void setOrigin(Point4D);

    void setDirection(Vector4d);

    Point4D pointOnRay(float t);

    void print();
};

#endif //ASSIGNMENT2_RAY4D_H
