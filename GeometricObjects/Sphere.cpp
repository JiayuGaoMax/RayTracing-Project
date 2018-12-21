//
// Created by Jiayu Gao on 2018-10-08.
//
#include "Shpere.h"

Sphere::Sphere() {
    center = Point4D();
    radius = 1.0f;
    kDefuse = Vector4d(1, 1, 1);
    kSpecular= Vector4d(1, 1, 1);
}

Sphere::Sphere(Point4D pos, float rad, Vector4d kd, Vector4d ks) {
    center = pos;
    radius = rad;
    kDefuse = kd;
    kSpecular = ks;
}

void Sphere::setCenter(Point4D pos) {
    center = pos;
}

void Sphere::setradius(float rad) {
    radius = rad;
}

void Sphere::setDefuse(Vector4d kd) {
    kDefuse = kd;
}

Point4D Sphere::getpPosition() {
    return center;
}

float Sphere::getRadius() {
    return radius;
}

Vector4d Sphere::getDefuse() {
    return kDefuse;
}

Vector4d Sphere::getKs() const {
    return kSpecular;
}

bool
Sphere::isRayIntersected(Ray4D inComingRay, float &projectionDistanceFromCenterOfSphereToOriginOfRay,
                         float &distanceFromClosestPointOnRayToSphereCenter) {
    Vector4d rayDirection = inComingRay.getDirection();
    Point4D rayStartPoint = inComingRay.getOrigin();

    Vector4d vectorRayToSphereCenter =
            center - rayStartPoint;//A vector from Start point of the ray to center of this sphere

    projectionDistanceFromCenterOfSphereToOriginOfRay = vectorRayToSphereCenter.dotProduct(
            rayDirection);// Distance from  Sphere center to center of ray
    if (projectionDistanceFromCenterOfSphereToOriginOfRay < 0)
        return false;
    distanceFromClosestPointOnRayToSphereCenter = Point4D::pointToPointDistance(
            inComingRay.pointOnRay(projectionDistanceFromCenterOfSphereToOriginOfRay),
            center);
    if (distanceFromClosestPointOnRayToSphereCenter > radius)
        return false;// If the distance from ray to sphere center is greater than radius return false, which no inter section.
    else return true;// else return true cuz it have at least one intersection.
}

CollisionResult Sphere::raySphereIntersection(Ray4D inComingRay) {
    float raySphereProjectionDistance = 0.0f;
    float tca = 0.0f;
    if (isRayIntersected(inComingRay, tca, raySphereProjectionDistance)) {// If is intersected is true find out the T
        float thc = sqrt(radius * radius - raySphereProjectionDistance * raySphereProjectionDistance);
        float t0 = tca - thc;
        float t1 = tca + thc;
        if (t0 <= t1)
            return CollisionResult(t0, (inComingRay.pointOnRay(t0) - center).unitLength(), kDefuse, kSpecular);
            //either t0 or t1 is smaller return the smaller one, normal of sphere is the intersection point - center of sphere
        else
            return CollisionResult(t1, (inComingRay.pointOnRay(t1) - center).unitLength(), kDefuse, kSpecular);
    } else//Else return 0
        return CollisionResult();//If no collision then return default result where distance is null.


}

Sphere &Sphere::operator=(const Sphere &other) {
    this->kDefuse = other.kDefuse;
    this->radius = other.radius;
    this->center = other.center;
    this->kSpecular = other.kSpecular;
    return *this;
}

void Sphere::print() {
    center.print();
    cout << "Radius is " << radius << endl;
    kDefuse.print();

}