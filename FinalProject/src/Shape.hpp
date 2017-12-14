#pragma once
#include "ofMain.h"

class Shape{
public:
    Shape();
    Shape(float r,float g,float b);
    ofColor color;
    ofVec2f loc;
    ofVec2f dir;
    float diameter;
    float speed;
    float SPEED;
    int number;
    
    void draw();
    void update(float x,float y,float dia);
};
