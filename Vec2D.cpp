//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Vec2D.h"
#include <math.h>
#include <string>

int Vec2D::getL1DistanceTo(Vec2D vec2d) {
    return abs(vec2d.x - x) + abs(vec2d.y - y);
}

void Vec2D::updatePosition(int magnitudeX, int magnitudeY) {
    x = magnitudeX;
    y = magnitudeY;
}

void Vec2D::transformACW90() {
    int tx = -y;
    int ty = x;
    x = tx; y = ty;
}

void Vec2D::transformCW90() {
    int tx = y;
    int ty = -x;
    x = tx; y = ty;
}

void Vec2D::transformRotations(int rot) {
    bool clockwise = rot > 0;
    rot = abs(rot);
    for(int _=0; _<rot; _++) {
        if(clockwise) {
            transformCW90();
        } else {
            transformACW90();
        }
    }
}

Vec2D Vec2D::operator+(Vec2D rhs) {
    return Vec2D(x+rhs.x, y+rhs.y);
}

Vec2D Vec2D::operator-(Vec2D rhs) {
    return Vec2D(x-rhs.x, y-rhs.y);
}

Vec2D Vec2D::operator*(Vec2D rhs) {
    return Vec2D(x*rhs.x, y*rhs.y);
}

bool Vec2D::operator==(Vec2D rhs) {
    return x == rhs.x && y == rhs.y;
}

Vec2D::operator std::string() {
    return "<" + std::to_string(x) + ", " + std::to_string(y) + ">";
}