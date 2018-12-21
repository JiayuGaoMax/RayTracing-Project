//
// Created by galax on 9/18/2018.
//
#include "Matrix4D.h"

Matrix4D::Matrix4D() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

// Assignment operator will be used a lot so implementation in header way
Matrix4D::Matrix4D(float other[][4]) {
    m[0][0] = other[0][0];
    m[0][1] = other[0][1];
    m[0][2] = other[0][2];
    m[0][3] = other[0][3];
    m[1][0] = other[1][0];
    m[1][1] = other[1][1];
    m[1][2] = other[1][2];
    m[1][3] = other[1][3];
    m[2][0] = other[2][0];
    m[2][1] = other[2][1];
    m[2][2] = other[2][2];
    m[2][3] = other[2][3];
    m[3][0] = other[3][0];
    m[3][1] = other[3][1];
    m[3][2] = other[3][2];
    m[3][3] = other[3][3];
}

//Matrix Matrix Operations
Matrix4D Matrix4D::operator+(const Matrix4D other) {

    float temp[4][4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = m[i][j] + other.m[i][j];
    return Matrix4D(temp);
}

Matrix4D Matrix4D::operator-(const Matrix4D other) {

    float temp[4][4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = m[i][j] - other.m[i][j];
    return Matrix4D(temp);
}

// Multiplication use lazy implementation might change later
Matrix4D Matrix4D::operator*(const Matrix4D other) {
    float temp[4][4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                temp[i][j] += m[i][k] * other.m[k][j];

    return Matrix4D(temp);
}

Matrix4D &Matrix4D::operator=(const Matrix4D other) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] = other.m[i][j];

    return *this;
}

//Generate Transformation,scale and Rotation Matrix
Matrix4D Matrix4D::generateTransformatgionMatrix(Vector4d vec) {
    float rMatrix[4][4] = {
            {1, 0, 0, vec.v[0]},
            {0, 1, 0, vec.v[1]},
            {0, 0, 1, vec.v[2]},
            {0, 0, 0, vec.v[3]}
    };
    return Matrix4D(rMatrix);
}

Matrix4D Matrix4D::generateRotationXMatrix(float angle) {
    float degree = angle * 3.14159f / 180;
    float rMatrix[4][4] = {
            {1, 0,           0,            0},
            {0, cos(degree), -sin(degree), 0},
            {0, sin(degree), cos(degree),  0},
            {0, 0,           0,            1}
    };
    return Matrix4D(rMatrix);
}

Matrix4D Matrix4D::generateRotationYMatrix(float angle) {
    float degree = angle * 3.14159f / 180;
    float rMatrix[4][4] = {
            {cos(degree),  0, sin(degree), 0},
            {0,            1, 0,           0},
            {-sin(degree), 0, cos(degree), 0},
            {0,            0, 0,           1}
    };
    return Matrix4D(rMatrix);
}

Matrix4D Matrix4D::generateRotationZMatrix(float angle) {
    float degree = angle * 3.14159f / 180;
    float rMatrix[4][4] = {
            {cos(degree), -sin(degree), 0, 0},
            {sin(degree), cos(degree),  0, 0},
            {0,           0,            1, 0},
            {0,           0,            0, 1}
    };
    return Matrix4D(rMatrix);
}

Matrix4D Matrix4D::generateScaleMatrix(float ratio) {
    float rMatrix[4][4] = {
            {ratio, 0,     0,     0},
            {0,     ratio, 0,     0},
            {0,     0,     ratio, 0},
            {0,     0,     0,     1}
    };
    return Matrix4D(rMatrix);
}

Matrix4D Matrix4D::generateViewpMatrix(Point4D originPoint, Point4D pointLookAt, Vector4d UpVec) {
    Vector4d V1 = pointLookAt - originPoint;
    Vector4d V2 = UpVec;
    Vector4d n = V1.unitLength();
    Vector4d u = (V2 * V1).unitLength();
    Vector4d v = (n * u).unitLength();
    float rMatrix[4][4] = {
            {u.v[0], u.v[1], u.v[2], 0},
            {v.v[0], v.v[1], v.v[2], 0},
            {n.v[0], n.v[1], n.v[2], 0},
            {0,      0,      0,      1}
    };
    return Matrix4D(rMatrix);
}

Matrix4D
Matrix4D::generateUVNSystemMatrix(Point4D fromOldOriginalPoint, Point4D toNewOriginPoint, Point4D pointToWhere,
                                  Vector4d UpVec) {
    Vector4d transalationVec = fromOldOriginalPoint - toNewOriginPoint;
    //Move from new original point to old original point turn new original point to new original point (0,0,0)
    Matrix4D TranMatrix = Matrix4D::generateTransformatgionMatrix(transalationVec);
    Matrix4D rotationMatrix = Matrix4D::generateViewpMatrix(Point4D(), pointToWhere, UpVec);
    return rotationMatrix * TranMatrix;


}

Matrix4D
Matrix4D::generateInverseUVNSystemMatrix(Point4D fromOldOriginalPoint, Point4D toNewOriginalPoint,
                                         Point4D PointLookAt,
                                         Vector4d UpVec) {
    //Following two steps generate the inverse of the transformation matrix which use negative vector to generate Matrix
    Vector4d transalationVec = toNewOriginalPoint - fromOldOriginalPoint;
    Matrix4D TranMatrix = Matrix4D::generateTransformatgionMatrix(transalationVec);
    //Following one line generate the inverse of the rotation function which is transpose of the rotation function
    Matrix4D inverseRotationMatrix = Matrix4D::generateViewpMatrix(Point4D(), PointLookAt,
                                                                   UpVec).transpose();
    return TranMatrix * inverseRotationMatrix;
}


//Matrix self implementation operators
void Matrix4D::operator+=(const Matrix4D other) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] = this->m[i][j] + other.m[i][j];
}

void Matrix4D::operator-=(const Matrix4D other) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] = this->m[i][j] + other.m[i][j];
}

void Matrix4D::operator*=(const Matrix4D other) {
    float temp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                temp[i][j] += m[i][k] * other.m[k][i];
    *this = Matrix4D(temp);
}

void Matrix4D::operator+=(const float val) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] += val;
}

void Matrix4D::operator-=(const float val) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] -= val;
}

void Matrix4D::operator*=(const float val) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] *= val;
}

void Matrix4D::operator/=(const float val) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->m[i][j] /= val;
}

Matrix4D Matrix4D::transpose() {
    Matrix4D rMatrix = *this;
    swap(rMatrix.m[1][0], rMatrix.m[0][1]);
    swap(rMatrix.m[2][0], rMatrix.m[0][2]);
    swap(rMatrix.m[2][1], rMatrix.m[1][2]);
    return rMatrix;
}

void Matrix4D::print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << this->m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

//Matrix Vector operations
Vector4d Matrix4D::operator*(Vector4d vec) {
    float x, y, z, w;
    x = this->m[0][0] * vec.v[0] + this->m[0][1] * vec.v[1] + this->m[0][2] * vec.v[2] + this->m[0][3] * vec.v[3];
    y = this->m[1][0] * vec.v[0] + this->m[1][1] * vec.v[1] + this->m[1][2] * vec.v[2] + this->m[1][3] * vec.v[3];
    z = this->m[2][0] * vec.v[0] + this->m[2][1] * vec.v[1] + this->m[2][2] * vec.v[2] + this->m[2][3] * vec.v[3];
    w = this->m[3][0] * vec.v[0] + this->m[3][1] * vec.v[1] + this->m[3][2] * vec.v[2] + this->m[3][3] * vec.v[3];
    return Vector4d(x, y, z, w);
}

Point4D Matrix4D::operator*(Point4D pt) {
    float x, y, z, w;
    x = this->m[0][0] * pt.p[0] + this->m[0][1] * pt.p[1] + this->m[0][2] * pt.p[2] + this->m[0][3] * pt.p[3];
    y = this->m[1][0] * pt.p[0] + this->m[1][1] * pt.p[1] + this->m[1][2] * pt.p[2] + this->m[1][3] * pt.p[3];
    z = this->m[2][0] * pt.p[0] + this->m[2][1] * pt.p[1] + this->m[2][2] * pt.p[2] + this->m[2][3] * pt.p[3];
    w = this->m[3][0] * pt.p[0] + this->m[3][1] * pt.p[1] + this->m[3][2] * pt.p[2] + this->m[3][3] * pt.p[3];
    return Point4D(x, y, z, w);
}

//General purpose Operation
void Matrix4D::swap(float &a, float &b) {
    float temp;
    temp = a;
    a = b;
    b = temp;
}