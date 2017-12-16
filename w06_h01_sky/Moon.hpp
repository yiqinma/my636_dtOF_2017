#pragma once
#include "ofMain.h"

class Moon
{
public:
    Moon();
    Moon(ofVec2f _cen);
    ofVec2f loc;
    ofVec2f cenLoc;
    ofVec2f startLoc;
    ofColor color;
    int r;
    int size;
    float angle;
    float speed;
    bool isBack = true;
    
    void draw();
    void update();
    void changeLocation(ofVec2f dir);
    void back();
};
