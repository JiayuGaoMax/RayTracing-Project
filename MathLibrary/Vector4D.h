//
// Created by galax on 9/17/2018.
//

#ifndef ASSIGNMENT1_VECTOR4D_H
#define ASSIGNMENT1_VECTOR4D_H

#include <cmath>
#include <iostream>

using namespace std;

class Vector4d {
private:
    float v[4];
public:
    //Constructor
    Vector4d();

    Vector4d(float, float, float, float);

    Vector4d(float, float, float);
    //Setters
    void setX(float x);

    void setY(float y);

    void setZ(float z);

    void setW(float w);

    //Getter
    float getX();

    float getY();

    float getZ();

    float getW();

    //Vec to Vec operators
    Vector4d operator+(const Vector4d);

    Vector4d operator-(const Vector4d);

    //unary - Operator return a negetive of current vector
    Vector4d operator-();

    Vector4d operator*(const Vector4d);

    Vector4d &operator=(const Vector4d);

    void operator+=(const Vector4d);

    void operator-=(const Vector4d);

    void operator*=(const Vector4d);

    //Vec to float operators
    void operator+=(const float);

    void operator-=(const float);

    void operator*=(const float);

    void operator/=(const float);

    Vector4d operator*(const float);

    Vector4d operator/(const float);

    //Vector operations
    float dotProduct(const Vector4d);

    float length();

    Vector4d unitLength();

    void print();

    friend class Matrix4D;

    friend class Point4D;

    //Static operation that could use with out Vector class been created
};

#endif //ASSIGNMENT1_VECTOR4D_H
