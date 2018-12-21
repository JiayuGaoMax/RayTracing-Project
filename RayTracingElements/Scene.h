//
// Created by galax on 2018-10-15.
//

#ifndef ASSIGNMENT2_SCENE_H
#define ASSIGNMENT2_SCENE_H

#include <GeometricObjects/Shpere.h>
#include <GeometricObjects/Polygon.h>
#include "RayTracingElements/Light.h"
#include "RayTracingElements/RayShooter.h"
#include "bitmap_image.hpp"
#include "Node.h"

class Scene {
private:
    int numOfObj;
    Node *n;
    Light l;
    RayShooter rayShooter;
    rgb_t **colors;
public:
//Hard coded Object
    Scene();

    ~Scene();

    rgb_t shading(Point4D intersectionPoint, Vector4d pointNorma, Vector4d kDefuse,Vector4d,Vector4d,Vector4d viewDirection);

    CollisionResult rayObjectIntersection(Ray4D inComingRay);

    void draw();//Generate image store in the hard drive

    //loop through the 512*512 light and call Ray object intersection to calculate point and shading to set color of pixes
    rgb_t rayTracing(Ray4D currentRay, int level);

    bool hideInTheShaldow(Point4D CollisionPoint,Vector4d CollisionNormal);

    void Scan();
};

#endif //ASSIGNMENT2_SCENE_H
