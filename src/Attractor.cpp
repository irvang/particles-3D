//
//  Attractor.cpp
//  particles-3D-1
//
//  Created by Irving Angulo on 11/12/17.
//
//

#include "Attractor.hpp"

//  -----------------------------------
Attractor::Attractor () {
    
}

//  -----------------------------------
Attractor::Attractor (float x, float y, float z, float mass, ofColor color):
mass{mass}, //same as this->mass {mass}
initialMass{this->mass},  //uses member 'mass' to initialize
count{0},
counterShift{0},
color {color},
pos{ofPoint(x, y, z)},
acc {ofPoint(ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc))},
vel {ofPoint(ofRandom(-rVel, rVel), ofRandom(-rVel, rVel), ofRandom(-rVel, rVel))}

{
    //all initialized above
}

//====STATIC PROPERTIES
//  -----------------------------------
float Attractor::scalM = 1;
float Attractor::elapsed = 1;
int Attractor::nbAtrctr = 0;
vector<Attractor>Attractor::arr;

//====FUNCTIONS
//  -----------------------------------
void Attractor::calculateAttraction(Particle & p) {
    // this should be a particle funciton
    
    p.force = this->pos - p.pos;//subtract attractor pos - particle pos
    float distance = p.force.length();
    distance = ofClamp(distance, 2.0, 7.0);
    
    p.force.normalize();
    
    float strength = (this->mass * p.mass) / (distance * distance);
    
    p.force = p.force * strength;
}

//  -----------------------------------
void Attractor::update() {
    
    if (count >= counterShift-1) {
        acc = ofPoint(ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc));
        counterShift = ofRandom(15, 240);
    }
    
//    acc = ofPoint(ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc), ofRandom(-rAcc, rAcc));
    
    vel += acc;// implied this->
    vel.limit(rAcc);
    ofPoint storeVel = vel * Attractor::elapsed;
    
    pos += storeVel;
    acc *= 0;
    
    count++;
    count = count % counterShift;
}

//  -----------------------------------
void Attractor::displayIt() {
//    ofDrawEllipse(<#float x#>, <#float y#>, <#float z#>, <#float width#>, <#float height#>)
    ofSetColor(255, 0, 100, 30);
    ofSetColor(color);
    ofDrawSphere(pos.x, pos.y, pos.z, mass * Attractor::scalM);
}

//  -----------------------------------
void Attractor::edges(const float &width, const float &height) {
    
    float edges = 300;
    
    if ((pos.y + mass) > edges) {
        vel.y *= -1;
//        pos.y = height - mass;
    }
    
    if ((pos.y - mass) < -edges) {
        vel.y *= -1;
//        pos.y = mass;
    }
    
    if ((pos.x + mass) > edges) {
        vel.x *= -1;
//        pos.x = width - mass;
    }
    
    if ((pos.x - mass) < -edges) {
        vel.x *= -1;
//        pos.x = mass;
    }
    
    if ((pos.z + mass) > edges) {
        vel.z *= -1;
        //        pos.x = width - mass;
    }
    
    if ((pos.z - mass) < -edges) {
        vel.z *= -1;
//        pos.x = mass;
    }
    
//    if ((pos.y + mass) > height) {
//        vel.y *= -1;
//        pos.y = height - mass;
//    }
//    
//    if ((pos.y - mass) < 0) {
//        vel.y *= -1;
//        pos.y = mass;
//    }
//    
//    if ((pos.x + mass) > width) {
//        vel.x *= -1;
//        pos.x = width - mass;
//    }
//    
//    if ((pos.x - mass) < 0) {
//        vel.x *= -1;
//        pos.x = mass;
//    }
}




