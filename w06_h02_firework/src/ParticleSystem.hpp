//
//  ParticleSystem.hpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem
{
public:
    ParticleSystem(float size,float spread,float x,float y);
    ParticleSystem();
    vector<Particle> particles;
    ofVec2f loc;
    ofColor color;
    
    void draw();
    void update();
    bool isFinished();
    
};
