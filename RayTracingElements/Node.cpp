//
// Created by galax on 2018-11-25.
//

#include "Node.h"

Node::Node() {
    type = 'n';
    sph = nullptr;
    poly = nullptr;
}


Node::Node(Sphere newSph, char newtp) {
    *sph = newSph;
    type = newtp;
}

Node::Node(Polygon newPloy, char newtp) {
    poly = new Polygon(newPloy.getNumOfVertex(), newPloy.getVertexs(), newPloy.getKd(), newPloy.getKs());
    //*poly = newPloy;
    type = newtp;
}

char Node::getType() {
    return type;
}

Sphere Node::getSphere() {
    return *sph;
}

Polygon &Node::getPolygon() {
    //Why
    Polygon *temp = new Polygon();
    *temp = *poly;
    return *temp;
    //return *poly;
}

void Node::setSphere(Sphere sp) {
    sph = new Sphere();
    *sph = sp;
    type = 's';
}

void Node::setPolygon(const Polygon &pl) {
    poly = new Polygon(pl.getNumOfVertex(), pl.getVertexs(), pl.getKd(), pl.getKs());
    //(*poly).print();
    type = 'p';
}

void Node::setType(char newT) {
    type = newT;
}

