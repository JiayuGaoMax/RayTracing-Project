//
// Created by galax on 2018-10-14.
//
#include "Light.h"

Light::Light() {
    color.red = 0;
    color.green = 0;
    color.blue = 0;
    Position = Point4D();
}

Light::Light(rgb_t c, Point4D p) {
    color = c;
    Position = p;
}

rgb_t Light::getColor() {
    return color;
}

Point4D Light::getPosition() {
    return Position;
}

void Light::setPosition(Point4D other) {
    Position = other;
}

void Light::setColor(rgb_t other) {
    color = other;
}
