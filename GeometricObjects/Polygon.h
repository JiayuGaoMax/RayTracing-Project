//
// Created by galax on 2018-10-10.
//
#include "RayTracingElements/Ray4D.h"
#include "CollisionResult.h"
#include "MathLibrary/Matrix4D.h"
#include "../bitmap_image.hpp"


#ifndef ASSIGNMENT2_POLYGON_H
#define ASSIGNMENT2_POLYGON_H

class Polygon {
private:
    int numOfVertex;
    Point4D *vtx;
    Vector4d kDefuse;
    Vector4d kSpecular;
public:
    Polygon();

    Polygon(int, Point4D *, Vector4d kd,Vector4d ks);

    ~Polygon();

    int getNumOfVertex() const;

    Point4D *getVertexs() const;

    Point4D getVertex(int n) const;

    Vector4d getNormal();

    Vector4d getKd() const;

    Vector4d getKs() const;

    void setNumOfVertex(int newNum);

    void setVertex(int nthVertex, Point4D newVertex);

    void setkd(Vector4d kd1);

    float computeD();

    float computeIntersectionPoint(Ray4D inComingRay);

    Point4D ProjectIntersectionPoint(Point4D intersectionPoint);

    Point4D *projectPolygonTo2D();

    Point4D *ProjectionX();

    Point4D *ProjectionY();

    Point4D *ProjectionZ();

    void freeProjectedPoints(Point4D *);

    Point4D *transformProjectedShapeToOriginAccordingToP(Point4D *projectedPoints, Point4D p);

    bool isCrossXAxis(Point4D a, Point4D b);

    int crossEdgeCounter(Point4D[]);//This function count how many times the 2D shape cross positive x axis

    bool isPointInsidePolygom(Point4D intersectionPoint);

    CollisionResult rayPolygonIntersection(Ray4D inComingRay);

    Polygon &operator=(const Polygon &other);

    void print();


};

#endif //ASSIGNMENT2_POLYGON_H
