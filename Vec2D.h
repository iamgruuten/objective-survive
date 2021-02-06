#ifndef vec2d_h
#define vec2d_h
#include <string>

class Vec2D {
public:
    int x;
    int y;

    Vec2D() {}
    Vec2D(int magnitudeX, int magnitudeY) : x(magnitudeX), y(magnitudeY) {}

    // class methods
    int getL1DistanceTo(Vec2D vec2d);
    void updatePosition(int magnitudeX, int magnitudeY);
    void transformACW90();
    void transformCW90();
    
    // operator methods
    Vec2D operator+(Vec2D rhs);
    Vec2D operator-(Vec2D rhs);
    Vec2D operator*(Vec2D rhs);
    bool operator==(Vec2D rhs);

    // cast operators
    operator std::string();

};

#endif