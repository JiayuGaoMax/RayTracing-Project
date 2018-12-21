//
// Created by Jiayu Gao on 2018-09-23.
//

#ifndef ASSIGNMENT1_POINT4D_H
#define ASSIGNMENT1_POINT4D_H

#include "Vector4D.h"

class Point4D {
private:
    float p[4];
public:
    //constructors
    Point4D();

    Point4D(float x, float y, float z);

    Point4D(float x, float y, float z, float w);

    //Setters
    void setX(float x);

    void setY(float y);

    void setZ(float z);

    void setW(float w);

    //getter
    float getX();

    float getY();

    float getZ();

    float getW();

    Vector4d PointToVector();

    static Vector4d PointToVector(Point4D pt);

    Vector4d operator-(Point4D other);

    Point4D &operator=(const Point4D &other);

    //point and vector interaction
    Point4D operator+(Vector4d other);

    Point4D operator-(Vector4d other);

    static float pointToPointDistance(Point4D one, Point4D andAnother);

    void print();

    friend class Matrix4D;
};

#endif //ASSIGNMENT1_POINT4D_H
