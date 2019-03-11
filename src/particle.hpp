//
//  particle.hpp
//  particles-3D-1
//
//  Created by Irving Angulo on 11/13/17.
//
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h" /* particle_hpp */
#include "Attractor.hpp"

class Particle {
public:
    Particle();
    
    Particle (float x, float y, float z, ofColor color);
    void applyForce ();
    void update ();
    void display ();
    
    ofPoint pos, vel, acc, force;
    float mass, limit, initialMass;
    
    ofColor color;
    
    static float scalM;
    static float elapsed;
    static int nbPtcls;
    static vector<vector<Particle> >arr;
private:
};

#endif
