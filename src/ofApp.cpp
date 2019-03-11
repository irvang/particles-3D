#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    myg.width = ofGetWidth();
    myg.height = ofGetHeight();
    myg.attMass = 12;
    myg.randMass = 5;
    myg.elapsed = ofGetElapsedTimeMicros() * 0.001;
    myg.newTime = ofGetElapsedTimeMicros() * 0.001;
    myg.oldTime = ofGetElapsedTimeMicros() * 0.001;
    
    Attractor::nbAtrctr = 1;
    Particle::nbPtcls = 1000;
    
    
    create();
    
    cam.setDistance(400);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0);
    
        // elapsed: micros * 0.001 = millis in float
    myg.newTime = ofGetElapsedTimeMillis();
    
    myg.elapsed = (myg.newTime - myg.oldTime) * 0.06;

    Attractor::elapsed = myg.elapsed;
    Particle::elapsed = myg.elapsed;
    
    updateAll ();
    
    myg.oldTime = myg.newTime;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateX(ofRadToDeg(.0));
    ofRotateY(ofRadToDeg(-.0));
    
    ofFill();
    displayAll();
    
    
    ofSetColor(255, 255, 255, 20);
    
//    ofNoFill();
    ofDrawBox(0, 0, 0, 400, 400, 400);
//    ofDrawSphere(0, 0, 0, 300);
    cam.end();
}

//====UTILS
//  -----------------------------------
void ofApp::updateAll () {
    
    for (int i = 0; i< Attractor::nbAtrctr; ++i) {
        
        Attractor::arr[i].update();
        Attractor::arr[i].edges(myg.width, myg.height);
        
        for(int j = 0; j < Particle::nbPtcls; ++j) {
            Attractor::arr[i].calculateAttraction(Particle::arr[i][j]);
            Particle::arr[i][j].applyForce();
            Particle::arr[i][j].update();
        }
    }
}

//  -----------------------------------
void ofApp::displayAll () {
    
    for (int i = 0; i< Attractor::nbAtrctr; ++i) {
        Attractor::arr[i].displayIt();
        
        for(int j = 0; j < Particle::nbPtcls; ++j) {
            Particle::arr[i][j].display();
        }
    }
}

//  -----------------------------------
void ofApp::create () {
    
    for (int i = 0; i< Attractor::nbAtrctr; ++i) {

        ofColor color = (ofRandom(150,255),ofRandom(150,255),ofRandom(150,255));
        
        //Attractor::Attractor (float x, float y, float mass, ofColor color):
//        Attractor::arr.push_back(Attractor(100 * i, 100 * i, ofRandom(12, 17), color));
        
        Attractor::arr.push_back(Attractor(0, 0, 0, ofRandom(12, 17), color));
        
        vector<Particle > pVec;
        Particle::arr.push_back( pVec);
        
        color = (ofRandom(150,255),ofRandom(150,255),ofRandom(150,255), 200);
        for(int j = 0; j < Particle::nbPtcls; ++j) {
            Particle::arr[i].push_back(Particle(ofRandom(-myg.width/2, myg.width/2),ofRandom(-myg.height/2, myg.height/2), ofRandom(-myg.width/2, myg.width/2), color));
        }
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    myg.width = ofGetWidth();
    myg.height = ofGetHeight();
}

//--------------------------------------------------------------

