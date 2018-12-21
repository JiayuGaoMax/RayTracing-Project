//
// Created by galax on 2018-10-10.
//
#include "RayTracingElements/Ray4D.h"
#include "MathLibrary/Matrix4D.h"

#ifndef ASSIGNMENT2_RAYSHOOTER_H
#define ASSIGNMENT2_RAYSHOOTER_H

class RayShooter {
private:
    //Camera Elements
    const float xmin = 0.0175f;
    const float ymin = -0.0175f;
    const float xmax = -0.0175f;
    const float ymax = 0.0175f;
    const float focalLength = 0.05f;
    static const int ROW = 512, COL = 512;
    //Local element
    Matrix4D Mcw;
    Matrix4D Mwc;
public:
    RayShooter();

    RayShooter(Point4D VRP, Point4D PointLookAt, Vector4d VPN);

    Point4D mapToScreenCoordinate(int row, int col);

    Point4D transferRayOrigin(Point4D origin);

    Point4D transferRayDirection(Point4D);

    Ray4D getRay(int row, int col);

    void print();

    void operator=(RayShooter other);

};

#endif //ASSIGNMENT2_RAYSHOOTER_H
