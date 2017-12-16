//
//  Particle.hpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//

#pragma once
#include "ofMain.h"

class Particle
{
public:
    Particle(ofVec2f _loc,float size,int r0,int g0,int b0);
    Particle();
    ofColor color;
    int limit;
    int r;
    float g;
    ofVec2f loc;
    ofVec2f velocity;
    
    void draw();
    void update();
    bool isFinished();
};
