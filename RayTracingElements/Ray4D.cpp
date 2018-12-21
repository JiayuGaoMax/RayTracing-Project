//
// Created by galax on 10/6/2018.
//
#include "Ray4D.h"

Ray4D::Ray4D() {
    o = Point4D();
    d = Vector4d();
}

Ray4D::Ray4D(Point4D origin, Vector4d direction) {
    o = origin;
    d = direction;
}

void Ray4D::setOrigin(Point4D newO) {
    o = newO;
}

void Ray4D::setDirection(Vector4d newD) {
    d = newD;
}

Point4D Ray4D::getOrigin() {
    return o;
}

Vector4d Ray4D::getDirection() {
    return d;
}

Point4D Ray4D::pointOnRay(float t) {
    return o + (d * t);
}

void Ray4D::print() {
    cout << "The origin of the ray is: ";
    o.print();
    cout << "The direction of the ray is: ";
    d.print();
}

Ray4D Ray4D::getReflectionRay(Point4D NewStartPoint, Vector4d RayDirection, Vector4d Normal) {
    float scale = RayDirection.unitLength().dotProduct(Normal.unitLength());
    Vector4d refVector = (RayDirection-(Normal * scale * 2)).unitLength();
    NewStartPoint = NewStartPoint + Normal*.001;
//The origin does not change, the vector become the opposite related base on normal
    return
            Ray4D(NewStartPoint, refVector);

}