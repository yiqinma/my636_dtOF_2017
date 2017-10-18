#pragma once
#include "ofMain.h"

class Self
{
public:
    Self();
    ofColor bgcolor;
    ofColor hairColor;
    float eyeAngle = 30;
    
    void draw();
    void update();
    void changeBackground();
    void drawHair();
    void changeHairColor();
    void drawFace();
    void drawEyebow();
    void drawEyes();
    void drawNose();
    void drawMouth();
    void drawBody();
    void changeEyeAngle();
};
