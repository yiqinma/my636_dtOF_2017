#pragma once
#include "ofMain.h"
#include "Star.hpp"
#include "Moon.hpp"

class Sky
{
public:
    Sky();
    int starNumber;
    int moonNumber;
    ofVec2f sunLoc;
    
    void draw();
    void update();
    void sack(ofVec2f loc);
    void back();
    void drawSun();
    void changeSunLocation(ofVec2f dir);
    void sunBack();
    
    vector<Star> stars;
    vector<Moon> moons;
};
