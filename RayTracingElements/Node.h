//
// Created by galax on 2018-11-25.
//

#ifndef FINAL_PROJECT_NODE_H
#define FINAL_PROJECT_NODE_H


#include <GeometricObjects/Shpere.h>
#include <GeometricObjects/Polygon.h>

class Node {
private:
    char type;
    Sphere *sph;
    Polygon *poly;
public:
    Node();

    Node(Polygon, char);

    Node(Sphere, char);

    Sphere getSphere();

    Polygon& getPolygon();

    char getType();

    void setSphere(Sphere sp);

    void setPolygon(const Polygon & pl);

    void setType(char);

};


#endif //FINAL_PROJECT_NODE_H
