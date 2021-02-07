//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "Vec2D.h"
#include <math.h>
#include <string>

Vec2D::Vec2D(const Vec2D& vec2d) {
    x = vec2d.x;
    y = vec2d.y;
}

Vec2D::~Vec2D() {
    // Destructor
}

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

// https://en.wikipedia.org/wiki/Pairing_function
// "...uniquely encodes two natural numbers into a single natural number."
int Vec2D::cantor_pairing_function(float x, float y) {
    return (int) (0.5 * (x + y) * (x + y + 1)) + 1;
}

Vec2D::operator int() {
    return cantor_pairing_function(x, y);
}