//
// Created by galax on 9/24/2018.
//
#include "../Headers/CoordinateSystemTranlation.h"

/*
 * Generate a UVN system from origin, Point4D() create a origin, To camera point where camera is A point look at and
 * a up vector Those are same for forward generations
 * I implement a inverse function which take same parameters will generate the inverse matrix that M*inversM=I
 * */
Matrix4D GenerateWorldToCamera(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec) {

    return Matrix4D::generateUVNSystemMatrix(Point4D(), CameraPoint, CameraLookAt, CameraUpVec);
}

Matrix4D GenerateCameraToWorld(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec) {
    return Matrix4D::generateInverseUVNSystemMatrix(Point4D(), CameraPoint, CameraLookAt, CameraUpVec);
}

Matrix4D GenerateWorldToLight(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec) {
    return Matrix4D::generateUVNSystemMatrix(Point4D(), LightPoint, LightToward, LightUpVec);
}

Matrix4D GenerateLightToWorld(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec) {
    return Matrix4D::generateInverseUVNSystemMatrix(Point4D(), LightPoint, LightToward, LightUpVec);
}
/*
 * From Light to camera is basically transform from Light or camera to origin and then transfer back to camera or light
 * So it require a Inverse transformation and a forward transformation as implementation below.
 */
Matrix4D GenerateLightToCamera(Point4D LightPoint, Point4D LightToward, Vector4d LightUpVec, Point4D CameraPoint,
                               Point4D CameraLookAt, Vector4d CameraUpVec) {
    return Matrix4D::generateUVNSystemMatrix(Point4D(), CameraPoint, CameraLookAt, CameraUpVec) *
           Matrix4D::generateInverseUVNSystemMatrix(Point4D(), LightPoint, LightToward, LightUpVec);
}

Matrix4D GenerateCameraToLight(Point4D CameraPoint, Point4D CameraLookAt, Vector4d CameraUpVec, Point4D LightPoint,
                               Point4D LightToward, Vector4d LightUpVec) {
    return Matrix4D::generateUVNSystemMatrix(Point4D(), LightPoint, LightToward, LightUpVec) *
            Matrix4D::generateInverseUVNSystemMatrix(Point4D(), CameraPoint, CameraLookAt, CameraUpVec);
}