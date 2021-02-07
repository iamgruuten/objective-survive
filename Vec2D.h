//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef vec2d_h
#define vec2d_h
#include <string>

class Vec2D {
private:
    int cantor_pairing_function(float x, float y);
public:
    int x;
    int y;

    Vec2D() {}
    Vec2D(int magnitudeX, int magnitudeY) : x(magnitudeX), y(magnitudeY) {}
    Vec2D(const Vec2D& vec2d);
    ~Vec2D();

    // class methods
    int getL1DistanceTo(Vec2D vec2d);
    void updatePosition(int magnitudeX, int magnitudeY);
    void transformACW90();
    void transformCW90();
    
    // transforms the vector by 90 degree rotations.
    // positive values rotate the vector clockwise, while negative values rotate the vector anti-clockwise.
    void transformRotations(int rot);
    
    // operator methods
    Vec2D operator+(Vec2D rhs);
    Vec2D operator-(Vec2D rhs);
    Vec2D operator*(Vec2D rhs);
    bool operator==(Vec2D rhs);

    // cast operators
    operator std::string();
    operator int();

};

#endif