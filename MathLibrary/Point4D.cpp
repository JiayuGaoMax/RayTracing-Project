//
// Created by Jiayu Gao on 2018-09-23.
//
#include "Point4D.h"

Point4D::Point4D() {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 1;
}

Point4D::Point4D(float x, float y, float z) {
    p[0] = x;
    p[1] = y;
    p[2] = z;
    p[3] = 1;
}

Point4D::Point4D(float x, float y, float z, float w) {
    p[0] = x;
    p[1] = y;
    p[2] = z;
    p[3] = w;
}

void Point4D::setX(float x) {
    p[0] = x;
}

void Point4D::setY(float y) {
    p[1] = y;
}

void Point4D::setZ(float z) {
    p[2] = z;
}

void Point4D::setW(float w) {
    p[3] = w;
}

float Point4D::getX() {
    return p[0];
}

float Point4D::getY() {
    return p[1];
}

float Point4D::getZ() {
    return p[2];
}

float Point4D::getW() {
    return p[3];
}

Vector4d Point4D::PointToVector() {
    return Vector4d(p[0], p[1], p[2], p[3]);
}

Vector4d Point4D::PointToVector(Point4D pt) {
    return Vector4d(pt.p[0], pt.p[1], pt.p[2], pt.p[3]);
}

//point subtract a point is a vector
Vector4d Point4D::operator-(Point4D other) {
    return Vector4d(p[0] - other.p[0], p[1] - other.p[1], p[2] - other.p[2], 1);
}


//point and vector interaction
Point4D Point4D::operator+(Vector4d other) {
    return Point4D(p[0] + other.v[0], p[1] + other.v[1], p[2] + other.v[2]);
}

Point4D Point4D::operator-(Vector4d other) {
    return Point4D(p[0] - other.v[0], p[1] - other.v[1], p[2] - other.v[2]);
}

Point4D &Point4D::operator=(const Point4D &other) {
    this->p[0] = other.p[0];
    this->p[1] = other.p[1];
    this->p[2] = other.p[2];
    this->p[3] = 1;
    return *this;
}

float Point4D::pointToPointDistance(Point4D one, Point4D andAnother) {
    return abs((one - andAnother).length());
}

void Point4D::print() {

    cout << this->p[0] << " ";
    cout << this->p[1] << " ";
    cout << this->p[2] << " ";
    cout << this->p[3] << endl;

}