//
// Created by galax on 9/18/2018.
//

#ifndef ASSIGNMENT1_MATRIX4D_H
#define ASSIGNMENT1_MATRIX4D_H

#include "Vector4D.h"
#include "Point4D.h"

class Matrix4D {
private:
    float m[4][4];
public:
    //Default of init constructors
    Matrix4D();

    Matrix4D(float[][4]);

    //Matrix Matrix Operations
    Matrix4D operator+(const Matrix4D);

    Matrix4D operator-(const Matrix4D);

    Matrix4D operator*(const Matrix4D);

    Matrix4D &operator=(const Matrix4D);

    //Generate Transformation,scale and Rotation Matrix
    static Matrix4D generateTransformatgionMatrix(Vector4d);

    static Matrix4D generateRotationXMatrix(float angle);

    static Matrix4D generateRotationYMatrix(float angle);

    static Matrix4D generateRotationZMatrix(float angle);

    static Matrix4D generateScaleMatrix(float ratio);

    static Matrix4D generateViewpMatrix(Point4D originPoint, Point4D pointToWhere, Vector4d UpVec);

    static Matrix4D
    generateUVNSystemMatrix(Point4D fromOriginalPoint, Point4D toOriginPoint, Point4D pointToWhere,
                            Vector4d UpVec);

    static Matrix4D
    generateInverseUVNSystemMatrix(Point4D toOriginPoint, Point4D fromOriginPoint, Point4D priviousPointLookAt,
                                   Vector4d priviousUpVec);

    //Matrix self implementation operators
    void operator+=(const Matrix4D);

    void operator-=(const Matrix4D);

    void operator*=(const Matrix4D);

    void operator+=(const float);

    void operator-=(const float);

    void operator*=(const float);

    void operator/=(const float);

    Matrix4D transpose();

    void print();

    //Matrix Vector operations
    Vector4d operator*(Vector4d);
    //Matrix Point operations
    Point4D operator*(Point4D);


    //General purpose Operation
    void swap(float &, float &);

};

#endif //ASSIGNMENT1_MATRIX4D_H
