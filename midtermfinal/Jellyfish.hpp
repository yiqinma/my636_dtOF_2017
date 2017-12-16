//
//  Jellyfish.hpp
//  Jellfish
//
//  Created by MaYiqin on 28/11/17.
//
//
#pragma once
#include "ofMain.h"

class Jellyfish
{
public:
    ofVec2f loc;
    ofVec2f dir;
    ofColor c;
    float speed;
    float size;
    float t;
    ofVec2f normal;
    float tRandom;
    ofPolyline tail;
    ofPolyline tail1;
    ofPolyline tail2;
    ofPolyline tail3;
    ofPolyline tail4;
    float a0;
    float a1;
    float a2;
    float a3;
    float a4;
    int interval;
    
    Jellyfish();
    Jellyfish(float x,float y);
    void display();
    void update();
};
