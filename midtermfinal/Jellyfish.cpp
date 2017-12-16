//
//  Jellyfish.cpp
//  Jellfish
//
//  Created by MaYiqin on 28/11/17.
//
//

#include "Jellyfish.hpp"

Jellyfish::Jellyfish()
{
    loc = ofVec2f(ofRandomWidth(), ofRandomHeight());
    dir = ofVec2f(ofRandom(-3,3),ofRandom(-3,3));
    dir.getNormalized();
    float alpha = ofRandom(50,150);
    c.set(10, ofRandom(100,255), ofRandom(200,255), alpha);
    speed = ofRandom(0.5,1);
    size = ofRandom(5,40);
    normal = ofVec2f(size/40,size/40);
    interval = int(ofRandom(100,300));
    t = 0;
    a0 = ofRandom(TWO_PI);
    a1 = ofRandom(TWO_PI);
    a2 = ofRandom(TWO_PI);
    a3 = ofRandom(TWO_PI);
    a4 = ofRandom(TWO_PI);
    tRandom = ofRandom(1);
    for (float i = 0; i < 2*size; i += 1 ) {
        tail.addVertex( 0, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail1.addVertex( -size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail2.addVertex( -2*size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail3.addVertex( size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail4.addVertex( 2*size/3, i);
    }
}

Jellyfish::Jellyfish(float x,float y)
{
    loc = ofVec2f(x, y);
    dir = ofVec2f(ofRandom(-3,3),ofRandom(-3,3));
    interval = int(ofRandom(100,300));
    dir.getNormalized();
    a0 = ofRandom(TWO_PI);
    a1 = ofRandom(TWO_PI);
    a2 = ofRandom(TWO_PI);
    a3 = ofRandom(TWO_PI);
    a4 = ofRandom(TWO_PI);
    float alpha = ofRandom(50,255);
    c.set(10, ofRandom(100,255), ofRandom(200,255), alpha);
    speed = ofRandom(0.5,1);
    size = ofRandom(5,40);
    normal = ofVec2f(size/40,size/40);
    t = 0;
    tRandom = ofRandom(1);
    for (float i = 0; i < 2*size; i += 1 ) {
        tail.addVertex( 0, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail1.addVertex( -size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail2.addVertex( -2*size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail3.addVertex( size/3, i);
    }
    for (float i = 0; i < 2*size; i += 1 ) {
        tail4.addVertex( 2*size/3, i);
    }
}

void Jellyfish::display()
{
    ofPushMatrix();
    
    ofSetLineWidth(1);
    ofTranslate(loc.x, loc.y);
    ofRotate(90-dir.angle(ofVec2f(1,0)));
    ofPath head;
    head.setColor(c);
    t = tRandom;
    for(float i = 0;i < TWO_PI;i+=0.005){
        float tempX = 0;
        float tempY = 0;
        if(i < 0.9*PI && i > 0.1*PI){
            tempX = size*cos(i);
            tempY = -size*0.5*sin(i) + 0.5*size;
            tempX += normal.x * sin(t)*cos(i);
            tempY += normal.y * sin(t)*sin(i);
            head.lineTo(ofVec2f(tempX,tempY));
        }
        else if(i > 1.1*PI && i < 1.9*PI){
            tempX = size*cos(i);
            tempY = size*sin(i);
            tempX += normal.x * sin(t)*cos(i);
            tempY += normal.y * sin(t)*sin(i);
            head.lineTo(ofVec2f(tempX,tempY));
        }
        
        t+=0.05;
        
    }
    tRandom += 0.1;
    head.close();
    head.draw();
    ofSetLineWidth(2);
    ofSetColor(c);
    tail.draw();
    tail1.draw();
    //tail2.draw();
    tail3.draw();
    //tail4.draw();
    ofPopMatrix();
    
    
}

void Jellyfish::update()
{
    if(ofGetFrameNum()%interval == 0){
        dir = ofVec2f(ofRandom(-3,3),ofRandom(-3,3));
        dir.getNormalized();
        speed = ofRandom(0.5,1);
    }
    ofVec2f velocity = ofVec2f(dir.x*speed,dir.y*speed);
    loc += velocity;
    if(loc.x < 0 || loc.x > ofGetWidth())
        dir.x *= -1;
    if(loc.y < 0 || loc.y > ofGetHeight())
        dir.y *= -1;
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < tail.size(); i++)
    {
        float temp = ofMap(speed, 0.5, 1, 2, 4);
        float sinTime    = sin(a0+i * 0.05 + time * temp);
        
        float motionPct = ofMap(i, 0, tail.size(), 0.2, 1.0);
        
        tail[i].x = sinTime * size/4 * motionPct;
    }
    
    for (int i = 0; i < tail1.size(); i++)
    {
        float temp = ofMap(speed, 0.5, 1, 2, 4);
        float sinTime    = sin(a1+i * 0.05 + time * temp);
        
        float motionPct = ofMap(i, 0, tail1.size(), 0.2, 1.0);
        
        tail1[i].x = -size/3+sinTime * size/4 * motionPct;
    }
    
    for (int i = 0; i < tail2.size(); i++)
    {
        float temp = ofMap(speed, 0.5, 1, 2, 4);
        float sinTime    = sin(a2+i * 0.05 + time * temp);
        
        float motionPct = ofMap(i, 0, tail2.size(), 0.2, 1.0);
        
        tail2[i].x = -2*size/3+sinTime * size/4 * motionPct;
    }
    
    for (int i = 0; i < tail3.size(); i++)
    {
        float temp = ofMap(speed, 0.5, 1, 2, 4);
        float sinTime    = sin(a3+i * 0.05 + time * temp);
        
        float motionPct = ofMap(i, 0, tail3.size(), 0.2, 1.0);
        
        tail3[i].x = size/3+sinTime * size/4 * motionPct;
    }
    
    for (int i = 0; i < tail4.size(); i++)
    {
        float temp = ofMap(speed, 0.5, 1, 2, 4);
        float sinTime    = sin(a4+i * 0.05 + time * temp);
        
        float motionPct = ofMap(i, 0, tail4.size(), 0.2, 1.0);
        
        tail4[i].x = 2*size/3+sinTime * size/4 * motionPct;
    }
}

