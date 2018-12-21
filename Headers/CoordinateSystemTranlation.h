//
// Created by galax on 9/24/2018.
//
#include "MathLibrary/Matrix4D.h"

#ifndef ASSIGNMENT1_COORDINATESYSTEMTRANLATION_H
#define ASSIGNMENT1_COORDINATESYSTEMTRANLATION_H
/*
 * Generate a UVN system from origin, Point4D() create a origin, To camera point where camera is A point look at and
 * a up vector Those are same for forward generations
 * I implementa a inverse function which take same parameters will generate the invers matrix that M*inversM=I
 * */
Matrix4D GenerateWorldToCamera(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec);

Matrix4D GenerateCameraToWorld(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec);

Matrix4D GenerateWorldToLight(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec);

Matrix4D GenerateLightToWorld(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec);
/*
 * From Light to camera is basically transform from Light or camera to origin and then transfer again to camera or light
 * So it require a Inverse transformation to origin and a forward transformation as implementation below.
 */
Matrix4D GenerateLightToCamera(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec, Point4D CameraPoint,
                               Point4D CameraLookAt, Vector4d CameraUpVec);

Matrix4D GenerateCameraToLight(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec, Point4D LightPoint,
                               Point4D LightToward, Vector4d LightUpVec);

#endif //ASSIGNMENT1_COORDINATESYSTEMTRANLATION_H
