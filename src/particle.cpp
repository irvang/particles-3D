//
//  particle.cpp
//  particles-3D-1
//
//  Created by Irving Angulo on 11/13/17.
//
//

#include "particle.hpp"
Particle::Particle () { };

//constructor
Particle::Particle (float x, float y, float z, ofColor color):
color{color},
mass {ofRandom(2,1)},
initialMass { mass},
limit{ofRandom(7, 12)},
pos {ofPoint(x, y, z)},
vel {ofPoint(0, 0, 0)},
acc {ofPoint(0, 0, 0)},
force {ofPoint(1,1, 1)}
{
    // all initialized above
}

//====STATIC PROPERTIES
//  -----------------------------------
float Particle::scalM = 1;
float Particle::elapsed = 1;
int Particle::nbPtcls = 1;
vector<vector<Particle> > Particle::arr;

//====FUNCTIONS
//  -----------------------------------
void Particle::applyForce () {
    force = force / mass;
    acc += force;
}

//  -----------------------------------
void Particle::update () {
    vel += acc;
    vel.limit(limit);
    ofPoint storeVel = vel * Particle::elapsed;
    pos += storeVel;
    acc *= 0;
}

//  -----------------------------------
void Particle::display () {
    ofSetColor(color);
    ofDrawSphere(pos.x, pos.y, pos.z, mass * Particle::scalM);
}
