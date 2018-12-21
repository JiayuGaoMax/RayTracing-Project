//
// Created by galax on 2018-10-14.
//
#include "bitmap_image.hpp"
#include "MathLibrary/Point4D.h"

#ifndef ASSIGNMENT2_LIGHT_H
#define ASSIGNMENT2_LIGHT_H

class Light {
private:
    rgb_t color;
    Point4D Position;
public:
    Light();

    Light(rgb_t, Point4D);

    rgb_t getColor();

    Point4D getPosition();

    void setPosition(Point4D other);

    void setColor(rgb_t other);

};

#endif //ASSIGNMENT2_LIGHT_H
