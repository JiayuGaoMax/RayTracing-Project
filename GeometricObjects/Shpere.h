//
// Created by Jiayu Gao on 2018-10-07.
//
#include "RayTracingElements/Ray4D.h"
#include "CollisionResult.h"

#ifndef ASSIGNMENT2_SHPERE_H
#define ASSIGNMENT2_SHPERE_H

class Sphere {
private:
    Point4D center;
    float radius;
    Vector4d kDefuse;
    Vector4d kSpecular;
public:
    Sphere();

    Sphere(Point4D pos, float rad, Vector4d kd, Vector4d ks);

    void setCenter(Point4D cen);

    void setradius(float rad);

    void setDefuse(Vector4d kd);

    Point4D getpPosition();

    float getRadius();

    Vector4d getDefuse();

    Vector4d getKs() const;

    bool isRayIntersected(Ray4D inComingRay, float &distanceFromCenterOfSphereToOriginOfRay, float &distance);

    CollisionResult raySphereIntersection(Ray4D inComingRay);

    Sphere &operator=(const Sphere &other);

    void print();
};

#endif //ASSIGNMENT2_SHPERE_H
