//
// Created by galax on 2018-10-15.
//
#include "Scene.h"

rgb_t operator+(rgb_t color, rgb_t otherColor) {
    rgb_t newColor;
    newColor.red = (color.red + otherColor.red);
    newColor.green = (color.green + otherColor.green);
    newColor.blue = (color.blue + otherColor.blue);
    return newColor;
}

rgb_t operator*(rgb_t color, float c) {
    rgb_t newColor;
    newColor.red = (unsigned char) (color.red * c);
    newColor.green = (unsigned char) (color.green * c);
    newColor.blue = (unsigned char) (color.blue * c);
    return newColor;
}

rgb_t operator*(float c, rgb_t color) {
    rgb_t newColor;
    newColor.red = (unsigned char) (color.red * c);
    newColor.green = (unsigned char) (color.green * c);
    newColor.blue = (unsigned char) (color.blue * c);
    return newColor;
}

rgb_t operator*(rgb_t color, Vector4d c) {
    rgb_t newColor;
    newColor.red = (unsigned char) (color.red * c.getX());
    newColor.green = (unsigned char) (color.green * c.getY());
    newColor.blue = (unsigned char) (color.blue * c.getZ());
    return newColor;
}

Scene::Scene() {
    n = new Node[5];
    numOfObj = 5;

    Point4D polygonVertex[] = {
            Point4D(0, 0, 0),
            Point4D(0, 0, 3),
            Point4D(3, 0, 3),
            Point4D(3, 0, 0),

    };
    Point4D polygonVertex1[] = {
            Point4D(0, 0, 3),
            Point4D(3, 0, 3),
            Point4D(3, 3, 3),
            Point4D(0, 3, 3),

    };
    Polygon p = Polygon(4, polygonVertex, Vector4d(0, 1, 1), Vector4d(1, 1, 1));
    Polygon p1 = Polygon(4, polygonVertex1, Vector4d(1, 0, 1), Vector4d(1, 1, 1));

    //n[0] = Node(p, 'p');
    n[0].setPolygon(p);
    n[1].setSphere(Sphere(Point4D(2, 0.5, 1), 0.5f, Vector4d(1, 0, 0), Vector4d(1, 1, 1)));
    n[2].setSphere(Sphere(Point4D(1, 0.5, 1), 0.5f, Vector4d(0, 1, 0), Vector4d(1, 1, 1)));
    n[3].setPolygon(p1);
    //n[4].setSphere(Sphere(Point4D(0.5, 1, 1), 0.5f, Vector4d(0, 0, 1)));
    n[4].setSphere(Sphere(Point4D(1.5, 1, 1), 0.5f, Vector4d(0, 0, 1), Vector4d(1, 1, 1)));
    //n[6].setSphere(Sphere(Point4D(2.5, 1, 1), 0.5f, Vector4d(1, 0, 0)));

    rayShooter = RayShooter(Point4D(1.5, 7, 9), Point4D(0.0f, -0.7f, -0.9f), Vector4d(0, 0, 1));
    rgb_t lightColor;
    lightColor.blue = 255;
    lightColor.green = 255;
    lightColor.red = 255;

    l = Light(lightColor, Point4D(5, 4, 8));
    //allocate the colors
    colors = new rgb_t *[512];
    for (int i = 0; i < 512; i++)
        colors[i] = new rgb_t[512];
}

Scene::~Scene() {
    for (int i = 0; i < 512; i++) {
        delete[] colors[i];
    }
    delete[] colors;
}

rgb_t
Scene::shading(Point4D intersectionPoint, Vector4d pointNormal, Vector4d kDefuse, Vector4d refDirection, Vector4d kSpec,
               Vector4d viewDirection) {
    Vector4d vectorObjToLight = l.getPosition() - intersectionPoint;
    rgb_t Black;
    Black.blue = 0;
    Black.green = 0;
    Black.red = 0;
    if (pointNormal.unitLength().dotProduct(vectorObjToLight.unitLength()) < 0) return Black;
    rgb_t Defuse = l.getColor() * kDefuse * (pointNormal.unitLength().dotProduct(vectorObjToLight.unitLength()));


    rgb_t Specular = Black;
    if (refDirection.dotProduct(viewDirection) < 0)
        Specular = l.getColor() * kSpec * pow(refDirection.dotProduct(viewDirection), 10);
    return 1 * Defuse + 0.0 * Specular;
}

CollisionResult Scene::rayObjectIntersection(Ray4D inComingRay) {
    CollisionResult smallestDistCollisionResult;
    CollisionResult currentCollisionResult;

    for (int i = 0; i < numOfObj; i++) {//for each ray go through all the objects in the scene

        if (n[i].getType() == 's') {//If object is sphere, do ray sphere intersection
            currentCollisionResult = n[i].getSphere().raySphereIntersection(inComingRay);
        }
        if (n[i].getType() == 'p') {//if object is a polygon do polygon intersection
            currentCollisionResult = n[i].getPolygon().rayPolygonIntersection(inComingRay);
        }
        if (smallestDistCollisionResult.getCollisionDistance() == NULL &&
            currentCollisionResult.getCollisionDistance() != NULL)
            smallestDistCollisionResult = currentCollisionResult;


        if (currentCollisionResult.getCollisionDistance() != NULL &&
            smallestDistCollisionResult.getCollisionDistance() != NULL &&
            currentCollisionResult.getCollisionDistance() < smallestDistCollisionResult.getCollisionDistance())
            smallestDistCollisionResult = currentCollisionResult;//If the current object collision distance is smaller than smallest distance and not equal to Null then replace smallest collision result to current collision result
    }
    return smallestDistCollisionResult;
}


void Scene::draw() {

    bitmap_image image(512, 512);
    image.set_all_channels(255, 150, 50);
    for (unsigned int i = 0; i < 512; i++) {
        for (unsigned int j = 0; j < 512; j++) {
            image.set_pixel(i, j, colors[i][j]);
        }
    }
    image.save_image("rayTracing.bmp");
}

rgb_t Scene::rayTracing(Ray4D currentRay, int level) {
    rgb_t Background;
    Background.blue = 220;
    Background.green = 120;
    Background.red = 100;
    if (level == 0) {
        return Background;
    }
    CollisionResult currentCollisionResult = rayObjectIntersection(currentRay);
    if (currentCollisionResult.getCollisionDistance() == NULL) {
        return Background;
    } else {
        Point4D collisionPoint = currentRay.pointOnRay(currentCollisionResult.getCollisionDistance());
        Ray4D reflectRay = Ray4D::getReflectionRay(collisionPoint, currentRay.getDirection(),
                                                   currentCollisionResult.getNormal());

        rgb_t shadingMethod;

        if (hideInTheShaldow(collisionPoint, currentCollisionResult.getNormal())) {
            //If the current collision point is hide in the shadow return black
            rgb_t Black;
            Black.blue = 0;
            Black.green = 0;
            Black.red = 0;
            shadingMethod = Black;
        } else {
            Ray4D
                    lightReflectRay = Ray4D::getReflectionRay(collisionPoint,
                                                              (l.getPosition() - collisionPoint).unitLength(),
                                                              currentCollisionResult.getNormal());
            //If the current collision point is not hide in the shadow use stander shading
            shadingMethod = shading(collisionPoint,
                                    currentCollisionResult.getNormal(),
                                    currentCollisionResult.getKd(),
                                    lightReflectRay.getDirection(),
                                    currentCollisionResult.getKs(),
                                    (currentRay.getOrigin() - collisionPoint).unitLength());
        }
        rgb_t
                color =
                (0.5) * shadingMethod
                +
                (
                        (0.5) *
                        rayTracing(reflectRay, level - 1)
                );
        return color;
    }


}

void Scene::Scan() {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            Ray4D currentRay = rayShooter.getRay(i, j);
            colors[i][j] = rayTracing(currentRay, 2);
        }
    }
    draw();
}

bool Scene::hideInTheShaldow(Point4D CollisionPoint, Vector4d CollisionNormal) {
    Ray4D shaldowRay = Ray4D(CollisionPoint + CollisionNormal * 0.001, (l.getPosition() - CollisionPoint).unitLength());
    float collisionValue = NULL;
    collisionValue = rayObjectIntersection(shaldowRay).getCollisionDistance();
    if (collisionValue != NULL)
        return true;
    else return false;

}