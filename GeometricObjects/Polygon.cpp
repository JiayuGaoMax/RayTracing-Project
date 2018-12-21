//
// Created by galax on 2018-10-10.
//
#include "Polygon.h"
#include <iostream>

Polygon::Polygon() {
    numOfVertex = 0;
    vtx = nullptr;
    kDefuse = Vector4d(1, 1, 1);
}

Polygon::Polygon(int numofV, Point4D *vert, Vector4d kd1, Vector4d ks) {
    numOfVertex = numofV;
    vtx = new Point4D[numofV];
    for (int i = 0; i < numofV; i++)
        vtx[i] = vert[i];
    kDefuse = kd1;
    kSpecular = ks;
}

Polygon::~Polygon() {
    std::cout << "Destractor are called" << endl;
    delete[] vtx;
}

int Polygon::getNumOfVertex() const {
    return numOfVertex;
}

Point4D *Polygon::getVertexs() const {
    return vtx;
}

Point4D Polygon::getVertex(int n) const {
    return vtx[n];
}

Vector4d Polygon::getNormal() {
    Vector4d V1 = vtx[1] - vtx[0];
    Vector4d V2 = vtx[2] - vtx[0];
    return (V1 * V2).unitLength();
}

Vector4d Polygon::getKd() const {
    return kDefuse;
}

void Polygon::setNumOfVertex(int newNum) {
    numOfVertex = newNum;
}

void Polygon::setVertex(int nthVertex, Point4D newVertex) {
    vtx[nthVertex] = newVertex;
}

void Polygon::setkd(Vector4d kd1) {
    kDefuse = kd1;
}

Vector4d Polygon::getKs() const {
    return kSpecular;
}

float Polygon::computeD() {
    return -(getNormal().dotProduct(vtx[0].PointToVector()));
}


float Polygon::computeIntersectionPoint(Ray4D inComingRay) {
    Vector4d Normal = getNormal();
    float Denominator = Normal.dotProduct(inComingRay.getDirection());
    if (Denominator == 0.0f)//This is because of polygon is parallel with the Ray, no intersect
        return NULL;
    float Numerator = Normal.dotProduct(inComingRay.getOrigin().PointToVector());

    return -(Numerator / Denominator);
}


Point4D Polygon::ProjectIntersectionPoint(Point4D intersectionPoint) {
    Vector4d Normal = getNormal();
    float x = Normal.getX(), y = Normal.getY(), z = Normal.getZ();
    if (x >= y && x >= z)
        return Point4D(intersectionPoint.getY(), intersectionPoint.getZ(), 0);
    else if (y >= x && y >= z)
        return Point4D(intersectionPoint.getX(), intersectionPoint.getZ(), 0);
    else if (z >= x && z >= y)
        return Point4D(intersectionPoint.getX(), intersectionPoint.getY(), 0);

}

Point4D *Polygon::projectPolygonTo2D() {
    Vector4d Normal = getNormal();
    float x = Normal.getX(), y = Normal.getY(), z = Normal.getZ();
    if (x >= y && x >= z)//X is greatest
        return ProjectionX();
    else if (y >= x && y >= z)//Y is greatest
        return ProjectionY();
    else if (z >= x && z >= y)//Z is greatest
        return ProjectionZ();
    return nullptr;
}

Point4D *Polygon::ProjectionX() {
    Point4D *projectedVertexs = new Point4D[numOfVertex];
    for (int i = 0; i < numOfVertex; i++) {
        //Project them to temporary 2D's x, y axis system, for easier implementation later
        projectedVertexs[i].setX(vtx[i].getY());
        projectedVertexs[i].setY(vtx[i].getZ());
    }
    return projectedVertexs;
}

Point4D *Polygon::ProjectionY() {
    Point4D *projectedVertexs = new Point4D[numOfVertex];
    for (int i = 0; i < numOfVertex; i++) {
        //Project them to temporary 2D's x, y axis system, for easier implementation later
        projectedVertexs[i].setX(vtx[i].getX());
        projectedVertexs[i].setY(vtx[i].getZ());
    }
    return projectedVertexs;
}

Point4D *Polygon::ProjectionZ() {
    Point4D *projectedVertexs = new Point4D[numOfVertex];
    for (int i = 0; i < numOfVertex; i++) {
        //Project them to temporary 2D's x, y axis system, for easier implementation later
        projectedVertexs[i].setX(vtx[i].getX());
        projectedVertexs[i].setY(vtx[i].getY());
    }
    return projectedVertexs;
}

void Polygon::freeProjectedPoints(Point4D *p) {
    delete[] p;
}

Point4D *Polygon::transformProjectedShapeToOriginAccordingToP(Point4D *projectedPoints, Point4D projectedP) {
    Point4D *transformedVertexs = new Point4D[numOfVertex];
    Matrix4D transformMat = Matrix4D::generateTransformatgionMatrix(-projectedP.PointToVector());
    for (int i = 0; i < numOfVertex; i++) {
        transformedVertexs[i] = transformMat * projectedPoints[i];
    }
    return transformedVertexs;
}

bool Polygon::isCrossXAxis(Point4D a, Point4D b) {
    if (a.getY() * b.getY() < 0)
        return true;
        //if the two sign is different the result is negative there fore the edge formed by these vertex cross the X axis
    else return false;
}

int Polygon::crossEdgeCounter(Point4D *projectedAndTransformedPoints) {
    int numberOfPointsIntersectedPositiveXAxis = 0;
    float xFinal;
    for (int i = 0; i < numOfVertex; i++) {
        xFinal = 0.0f;
        //Assign thisPoint and nextPoint because code look much nicer
        Point4D thisPoint = projectedAndTransformedPoints[i];
        Point4D nextPoint = projectedAndTransformedPoints[(i + 1) % numOfVertex];

        //If one of the Y value less than 0 and other is greater than 0 therefor it intersected
        if (isCrossXAxis(thisPoint, nextPoint)) {
            Vector4d vec2D = nextPoint - thisPoint;//a vector from this point to next point
            float ySlop = vec2D.getX() / vec2D.getY();
            float deltaX = thisPoint.getY() * ySlop;
            xFinal = thisPoint.getX() + deltaX;
        }
        if (xFinal > 0)
            numberOfPointsIntersectedPositiveXAxis++;

    }
    return numberOfPointsIntersectedPositiveXAxis;
}

bool Polygon::isPointInsidePolygom(Point4D intersectionPoint) {
    Point4D *ProjectedVertex = projectPolygonTo2D();//Project to 2 d
    Point4D projectedIntersectionPoint = ProjectIntersectionPoint(intersectionPoint);
    Point4D *projectedAndTransformedIntersectionPoint = transformProjectedShapeToOriginAccordingToP(ProjectedVertex,
                                                                                                    projectedIntersectionPoint);
    freeProjectedPoints(ProjectedVertex);
    if (crossEdgeCounter(projectedAndTransformedIntersectionPoint) % 2 == 0) {
        freeProjectedPoints(projectedAndTransformedIntersectionPoint);
        return false;//if intersection point count is even, return false else return true
    } else {
        freeProjectedPoints(projectedAndTransformedIntersectionPoint);
        return true;
    }
}

CollisionResult Polygon::rayPolygonIntersection(Ray4D inComingRay) {
    float t = computeIntersectionPoint(inComingRay);
    if (t < 0) {
        return CollisionResult();
    }

    if (isPointInsidePolygom(inComingRay.pointOnRay(t)))
        return CollisionResult(t, getNormal(), kDefuse, kSpecular);
    else
        return CollisionResult();
}

Polygon &Polygon::operator=(const Polygon &other) {
    numOfVertex = other.numOfVertex;
    vtx = new Point4D[other.numOfVertex];
    for (int i = 0; i < other.numOfVertex; i++) {
        vtx[i] = other.vtx[i];
    }
    kDefuse = other.kDefuse;
    return *this;
}

void Polygon::print() {
    cout << "Number of vertex is " << numOfVertex << endl;
    cout << "each vertex are" << endl;
    for (int i = 0; i < numOfVertex; i++) {
        vtx[i].print();
    }
    kDefuse.print();
}


