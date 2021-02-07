//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Vec2D

// Vec2D represents a two dimensional vector
// and is commonly used in representing the
// positions of objects in the game environment

// It can also be used to represent relative
// positions in relation to an origin position

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
    //Gets the L1Distance (min steps) needed to take to reach to its indicated position 
    //pre: None
    //Post: None
    int getL1DistanceTo(Vec2D vec2d);
    
    //Update position
    //pre: None
    //Post: The position of the object is updated
    void updatePosition(int magnitudeX, int magnitudeY);
    
    //Rotates 90 degree anti clockwise of its current position
    //pre: None
    //Post: The X or Y value will change according to its current facing direction
    void transformACW90();
    
     //Rotates 90 degree clockwise of its current position
    //pre: None
    //Post: The X or Y value will change according to its current facing direction
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