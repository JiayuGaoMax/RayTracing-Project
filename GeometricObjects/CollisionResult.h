//
// Created by galax on 2018-10-11.
//

#ifndef ASSIGNMENT2_COLLISIONRESULT_H
#define ASSIGNMENT2_COLLISIONRESULT_H

#include "MathLibrary/Point4D.h"

class CollisionResult {
private:
    float collisionDistance;
    Vector4d normal;
    Vector4d kd;
    Vector4d kSpecular;
public:
    CollisionResult();

    CollisionResult(float distance, Vector4d normal, Vector4d kd, Vector4d ks);

    void setCollisionDistance(float distance);

    void setNormal(Vector4d normal);

    void setKd(Vector4d kd1);

    float getCollisionDistance();

    Vector4d getNormal();

    Vector4d getKd();

    Vector4d getKs();

    CollisionResult &operator=(const CollisionResult &other);

    void print();

};

#endif //ASSIGNMENT2_COLLISIONRESULT_H
