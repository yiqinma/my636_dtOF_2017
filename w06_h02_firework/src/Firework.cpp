//
//  Firework.cpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//
#include "Firework.hpp"

Firework::Firework()
{
    
}

Firework::Firework(float _cenX,float _cenY,int _size)
{
    //int size = int(ofRandom(100,1000));
    size = _size;
    loc = ofVec2f(_cenX,_cenY);
    seedLoc = ofVec2f(ofGetWidth()/2,ofGetHeight());
    particleSystem = ParticleSystem(size,ofRandom(.004*size,.006*size),loc.x,loc.y);
}

void Firework::draw()
{
    
    ofDrawRectangle(0, ofGetHeight(), 15, -(size/1000.0)*ofGetHeight());
    if(isInPosition())
        particleSystem.draw();
    else
        drawSeed();
}

void Firework::update()
{
    if(isInPosition())
        particleSystem.update();
    else
        updateSeed();
}

bool Firework::isFinished()
{
    if(particleSystem.isFinished())
        return true;
    else
        return false;
}

bool Firework::isInPosition()
{
    if(seedLoc.distance(loc) < 20){
        return true;
    }else
    {
        return false;
    }
}

void Firework::drawSeed()
{
    ofSetColor(255);
    ofDrawEllipse(seedLoc.x, seedLoc.y, 10, 10);
}

void Firework::updateSeed()
{
    ofVec2f temp = ofVec2f(loc.x - ofGetWidth()/2,loc.y - ofGetHeight());
    temp /= 30;
    seedLoc += temp;
}
