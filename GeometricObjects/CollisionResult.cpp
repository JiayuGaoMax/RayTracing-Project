//
// Created by galax on 2018-10-11.
//

#include "CollisionResult.h"

CollisionResult::CollisionResult() {
    collisionDistance = NULL;
    normal = Vector4d();
    kd = Vector4d();
}

CollisionResult::CollisionResult(float distance, Vector4d normal1, Vector4d kd1, Vector4d ks) {
    collisionDistance = distance;
    normal = normal1;
    kd = kd1;
    kSpecular = ks;
}

void CollisionResult::setCollisionDistance(float distance) {
    collisionDistance = distance;
}

void CollisionResult::setNormal(Vector4d normal1) {
    normal = normal1;
}

void CollisionResult::setKd(Vector4d kd1) {
    kd = kd1;
}

float CollisionResult::getCollisionDistance() {
    return collisionDistance;
}

Vector4d CollisionResult::getNormal() {
    return normal;
}

Vector4d CollisionResult::getKd() {
    return kd;
}

Vector4d CollisionResult::getKs() {
    return kSpecular;
}

CollisionResult &CollisionResult::operator=(const CollisionResult &other) {
    this->collisionDistance = other.collisionDistance;
    this->kd = other.kd;
    this->kSpecular = other.kSpecular;
    this->normal = other.normal;
    return *this;
}

void CollisionResult::print() {
    cout << "Collision distance " << collisionDistance << endl;
    normal.print();
    kd.print();

}