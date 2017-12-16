//
//  Firework.hpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"
#include "ParticleSystem.hpp"

class Firework
{
public:
    Firework(float _cenX,float _cenY,int _size);
    Firework();
    ParticleSystem particleSystem;
    ofVec2f seedLoc;
    ofVec2f loc;
    int size;
    
    void draw();
    void update();
    void drawSeed();
    void updateSeed();
    bool isFinished();
    bool isInPosition();
};
