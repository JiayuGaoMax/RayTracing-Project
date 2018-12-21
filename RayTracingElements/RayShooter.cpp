#include "RayShooter.h"
#include "CoordinateSystemTranlation.h"
//
// Created by galax on 2018-10-10.
//

RayShooter::RayShooter() {
    Mcw = Matrix4D();
    Mwc = Matrix4D();
}

RayShooter::RayShooter(Point4D VRP, Point4D PointLookAt, Vector4d VPN) {
    Mcw = GenerateCameraToWorld(VRP, PointLookAt, VPN);
    Mwc = GenerateWorldToCamera(VRP, PointLookAt, VPN);
}


Point4D RayShooter::mapToScreenCoordinate(int row, int col) {
    float xDelta = (xmax - xmin) / ROW;
    float yhDelta = (ymax - ymin) / COL;
    return Point4D(xmin + xDelta * row, ymin + col * yhDelta, focalLength);

}

Point4D RayShooter::transferRayOrigin(Point4D origin) {
    return Mcw * origin;
}

Point4D RayShooter::transferRayDirection(Point4D rayPointTo) {
    return Mcw * rayPointTo;
}

Ray4D RayShooter::getRay(int row, int col) {
    Point4D screenPoint = mapToScreenCoordinate(row, col);
    Point4D origin = transferRayOrigin(Point4D());
    Point4D cameraCoordinatePoint = transferRayDirection(screenPoint);
    return Ray4D(origin, (cameraCoordinatePoint - origin).unitLength());

}

void RayShooter::operator=(RayShooter other) {
    this->Mwc = other.Mwc;
    this->Mcw = other.Mcw;
}

void RayShooter::print() {
    Mcw.print();
    Mwc.print();
}
