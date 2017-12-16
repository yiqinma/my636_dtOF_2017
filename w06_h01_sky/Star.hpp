#pragma once
#include "ofMain.h"

class Star
{
public:
    Star();
    ofVec2f loc;
    ofVec2f startLoc;
    int interval;
    long count;
    int size;
    
    void draw();
    void update();
    void changeLocation(ofVec2f dir);
    void back();
};
