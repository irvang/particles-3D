//
//  Attractor.hpp
//  particles-3D-1
//
//  Created by Irving Angulo on 11/12/17.
//
//

#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "ofMain.h"
#include "particle.hpp"

class Particle;

class Attractor {
    
public:
    Attractor ();
    
    Attractor(float x, float y, float z, float mass, ofColor color);
    
    void calculateAttraction (Particle & p) ;
    void update();
    void displayIt();
    void edges(const float &width, const float &height);
    
    /// ofPoint is a typedef (alias) of ofVec3f
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float mass {1};
    float initialMass {1};
    ofColor color;//probably an of color instead
    float rAcc = 5;// random acceleration
    float rVel = 5;
    
//    ofVec3f reference;
    
    int count {0};
    int counterShift {30}; //a random number
    
    static float scalM;
    static float elapsed;//elapsed between frames
    static int nbAtrctr;
    static vector<Attractor>arr;
private:
};

#endif

/// *Normalization* means to scale the vector so that its length
/// (magnitude) is exactly 1, at which stage all that is left is the
/// direction. A normalized vector is usually called a *unit vector*, and
/// can be used to represent a pure direction (heading).


// subtracts second from first

/// Super easy vector subtraction. Returns a new vector
/// ('x'-'vec.x','y'-'vec.y','z'-'vec.z').
///
/// ~~~~{.cpp}
/// ofVec3f v1 = ofVec3f(40, 20, 10);
/// ofVec3f v2 = ofVec3f(25, 50, 10);
/// ofVec3f v3 = v1 - v2; // v3 is (15, -30, 0)
/// ~~~~
//ofVec3f  operator-( const ofVec3f& vec ) const;


/// Return the length (magnitude) of this vector.
///
/// ~~~~{.cpp}
/// ofVec3f v(3, 4, 1);
/// float len = v.length(); // len is 5.0990
/// ~~~~
///
/// `length' involves a square root calculation, which is one of the
/// slowest things you can do in programming. If you don't need an exact
/// number but rather just a rough idea of a length (for example when
/// finding the shortest distance of a bunch of points to a reference
/// point, where it doesn't matter exactly what the lengths are, you just
/// want the shortest), you can use lengthSquared() instead.
///


/// \brief Return a copy of this vector with its length (magnitude) restricted to a
/// maximum of 'max' units by scaling down if necessary.
///
/// ~~~~{.cpp}
/// ofVec3f v1(5, 0, 1); // length is about 5.1
/// ofVec3f v2(2, 0, 1); // length is about 2.2
/// ofVec3f v1Limited = v1.getLimited(3);
/// // v1Limited is (2.9417, 0, 0.58835) which has length of 3 in the same direction as v1
/// ofVec3f v2Limited = v2.getLimited(3);
/// // v2Limited is (2, 0, 1) (same as v2)
/// ~~~~
