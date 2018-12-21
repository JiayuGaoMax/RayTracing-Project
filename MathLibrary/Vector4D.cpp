//
// Created by galax on 9/17/2018.
//
#include "Vector4D.h"

Vector4d::Vector4d() {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 1;
};

Vector4d::Vector4d(float x, float y, float z, float w) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;

}

Vector4d::Vector4d(float x, float y, float z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1;

}

void Vector4d::setX(float x) {
    v[0] = x;
}

void Vector4d::setY(float y) {
    v[1] = y;
}

void Vector4d::setZ(float z) {
    v[2] = z;
}

void Vector4d::setW(float w) {
    v[3] = w;
}

float Vector4d::getX() {
    return v[0];
}

float Vector4d::getY() {
    return v[1];
}

float Vector4d::getZ() {
    return v[2];
}

float Vector4d::getW() {
    return v[3];
}

Vector4d Vector4d::operator+(const Vector4d other) {
    return Vector4d(
            v[0] + other.v[0],
            v[1] + other.v[1],
            v[2] + other.v[2],
            1
    );
}

Vector4d Vector4d::operator-(const Vector4d other) {

    return Vector4d(
            v[0] - other.v[0],
            v[1] - other.v[1],
            v[2] - other.v[2],
            1
    );
}

Vector4d Vector4d::operator-() {
    return Vector4d(-this->v[0], -this->v[1], -this->v[2], 1);

}

Vector4d Vector4d::operator*(const Vector4d other) {
    return Vector4d(
            v[1] * other.v[2] - v[2] * other.v[1],
            v[2] * other.v[0] - v[0] * other.v[2],
            v[0] * other.v[1] - v[1] * other.v[0],
            1
    );
}

Vector4d &Vector4d::operator=(const Vector4d other) {
    this->v[0] = other.v[0],
    this->v[1] = other.v[1],
    this->v[2] = other.v[2],
    this->v[3] = 1;
    return *this;
}

void Vector4d::operator+=(const Vector4d other) {
    v[0] += other.v[0];
    v[1] += other.v[1];
    v[2] += other.v[2];
    v[3] = 1;
}

void Vector4d::operator-=(const Vector4d other) {
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    v[2] -= other.v[2];
    v[3] = 1;
}

void Vector4d::operator*=(const Vector4d other) {
    float tempV[4];
    tempV[0] = v[1] * other.v[2] - v[2] * other.v[1];
    tempV[1] = v[2] * other.v[0] - v[0] * other.v[2];
    tempV[2] = v[0] * other.v[1] - v[1] * other.v[0];
    v[0] = tempV[0];
    v[1] = tempV[1];
    v[2] = tempV[2];
    v[3] = 1;
}

void Vector4d::operator+=(const float value) {
    v[0] += value;
    v[1] += value;
    v[2] += value;
    v[3] = 1;
}

void Vector4d::operator-=(const float value) {
    v[0] -= value;
    v[1] -= value;
    v[2] -= value;
    v[3] = 1;
}

void Vector4d::operator*=(const float value) {
    v[0] *= value;
    v[1] *= value;
    v[2] *= value;
    v[3] = 1;
}

void Vector4d::operator/=(const float value) {
    v[0] /= value;
    v[1] /= value;
    v[2] /= value;
    v[3] = 1;
}

Vector4d Vector4d::operator*(const float value) {
    return Vector4d(
            v[0] * value,
            v[1] * value,
            v[2] * value,
            v[3] = 1
    );
}

Vector4d Vector4d::operator/(const float value) {
    return Vector4d(
            v[0] / value,
            v[1] / value,
            v[2] / value,
            v[3] = 1
    );
}

float Vector4d::dotProduct(const Vector4d other) {
    return (
            v[0] * other.v[0]
            + v[1] * other.v[1]
            + v[2] * other.v[2]
    );
}

float Vector4d::length() {
    return (sqrt(
            v[0] * v[0]
            + v[1] * v[1]
            + v[2] * v[2]
    ));
}

Vector4d Vector4d::unitLength() {
    Vector4d temp;
    temp = *this;
    if (temp.length() == 0) {
        return Vector4d(0,0,0);
    }
    temp /= temp.length();
    return temp;

}

void Vector4d::print() {
    cout << this->v[0] << " ";
    cout << this->v[1] << " ";
    cout << this->v[2] << " ";
    cout << this->v[3] << " ";
    cout << endl;
}
