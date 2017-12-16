//
//  Particle.cpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//

#include "Particle.hpp"

Particle::Particle()
{
    
}

Particle::Particle(ofVec2f _loc,float size,int r0,int g0,int b0)
{
    loc = _loc;
    float a = ofRandom(0,TWO_PI);
    float vel = ofRandom(0,size);
    r = 3;
    g = 0.05;
    limit = 0;
    velocity = ofVec2f(vel*cos(a),vel*sin(a));
    
    color = ofColor( r0+round(ofRandom(-30,30)),
                    g0+round(ofRandom(-30,30)),
                    b0+round(ofRandom(-30,30)));
}

void Particle::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofDrawEllipse(int(loc.x), int(loc.y), r, r);
    ofPopStyle();
}

void Particle::update()
{
    limit++;
    velocity += ofVec2f(0,g);
    loc += velocity;
    
}

bool Particle::isFinished ()
{
    if(ofRandom(0,limit) > 50)
    {
        return true;
    }else
    {
        return false;
    }
}


