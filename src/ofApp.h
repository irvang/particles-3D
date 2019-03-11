#pragma once

#include "ofMain.h"
//#include "ofxGui.h"
#include "Attractor.hpp"
#include "particle.hpp"
//A struct to hold my global variables, only one, therefore no type_name is really needed, only using it for reference
struct MyG {//My Global
public:
    float width = 0;
    float height = 0;
    float attMass, randMass, elapsed, newTime, oldTime;
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    //====UTILS
    void create ();
    void updateAll();
    void displayAll();
    
    void windowResized(int w, int h);

    MyG myg; //my global, line 8    
    
    ofEasyCam cam;
};
