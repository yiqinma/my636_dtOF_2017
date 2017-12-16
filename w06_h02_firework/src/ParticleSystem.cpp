//
//  ParticleSystem.cpp
//  fireworks
//
//  Created by MaYiqin on 15/11/17.
//
//
#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
    
}

ParticleSystem::ParticleSystem(float size,float spread,float x,float y)
{
    loc = ofVec2f(x,y);
    float r = ofRandom(190)+35;
    float g = ofRandom(190)+35;
    float b = ofRandom(190)+35;
    color = ofColor(r,g,b);
    
    for(int i = 0; i < size; i ++)
    {
        particles.push_back(Particle(loc,spread,r,g,b));
    }
    
}

void ParticleSystem::draw()
{
    for(int i = particles.size() - 1; i >= 0;i--)
    {
        if(particles[i].isFinished()){
            particles.erase(particles.begin()+i);
        }else{
            particles[i].draw();
        }
    }
}

void ParticleSystem::update()
{
    for(int i = particles.size() - 1; i >= 0;i--)
    {
        particles[i].update();
    }
}

bool ParticleSystem::isFinished()
{
    if(particles.size() == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
