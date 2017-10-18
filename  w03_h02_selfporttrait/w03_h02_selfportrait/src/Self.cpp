#include "Self.h"

Self::Self()
{
    float red    = ofRandom(0,255);
    float green    = ofRandom(0,255);
    float blue    = ofRandom(0,255);
    bgcolor = ofColor(red, green, blue);
    hairColor = ofColor(0,0,0);
}

void Self::draw()
{
    ofSetColor(bgcolor); 
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    drawBody();
    drawHair();
    drawFace();
    drawEyebow();
    drawEyes();
    drawNose();
    drawMouth();
}

void Self::update()
{
    
}

void Self::drawFace()
{
    ofPath face;
    face.setColor(ofColor(218,186,173));
    face.newSubPath();
    face.lineTo(ofVec2f( ofGetWidth(), 200));
    face.lineTo(ofVec2f( ofGetWidth() - 200, 0));
    face.lineTo(ofVec2f( 265, 123));
    face.lineTo(ofVec2f( 265, 521));
    face.lineTo(ofVec2f( 400, 773));
    face.lineTo(ofVec2f( 550, 773));
    face.lineTo(ofVec2f( ofGetWidth(), 550));
    face.close();
    face.draw();
}

void Self::drawNose()
{
    ofSetColor(ofColor(213,170,153));
    ofDrawTriangle( 415, 521, 530, 521, 415, 230);
    ofSetColor(ofColor(205,150,143,100));
    ofDrawRectangle( 265, 371, 150, 150);
    ofDrawRectangle( 530, 371, 150, 150);
}

void Self::drawEyes()
{
    ofPath eyeLD;
    ofPath eyeRD;
    eyeLD.setColor(ofColor(0,0,0));
    eyeLD.newSubPath();
    eyeRD.setColor(ofColor(0,0,0));
    eyeRD.newSubPath();
    eyeLD.arc( 340, 296, 75, 75, eyeAngle, 180 - eyeAngle);
    eyeRD.arc( 605, 296, 75, 75, eyeAngle, 180 - eyeAngle);
    eyeLD.close();
    eyeLD.draw();
    eyeRD.close();
    eyeRD.draw();
    ofPath eyeL;
    ofPath eyeR;
    eyeL.setColor(ofColor(213,170,153));
    eyeL.newSubPath();
    eyeR.setColor(ofColor(213,170,153));
    eyeR.newSubPath();
    eyeL.arc( 340, 296, 75, 75, 180 - eyeAngle, 360 + eyeAngle);
    eyeR.arc( 605, 296, 75, 75, 180 - eyeAngle, 360 + eyeAngle);
    eyeL.close();
    eyeL.draw();
    eyeR.close();
    eyeR.draw();
    ofSetColor(ofColor(213,170,153));
    ofDrawTriangle( 340, 296, 340 + 75 * cos(PI*(180 - eyeAngle)/180), 296 + 75 * sin(PI*(180 - eyeAngle)/180), 340 + 75 * cos(PI*(360 + eyeAngle)/180), 296 + 75 * sin(PI*(360 + eyeAngle)/180));
    ofDrawTriangle( 605, 296, 605 + 75 * cos(PI*(180 - eyeAngle)/180), 296 + 75 * sin(PI*(180 - eyeAngle)/180), 605 + 75 * cos(PI*(360 + eyeAngle)/180), 296 + 75 * sin(PI*(360 + eyeAngle)/180));
}

void Self::drawBody()
{
    ofSetColor(ofColor(218,186,173));
    ofDrawRectangle( 265, 371, 1500, 1500);
    ofDrawTriangle( 265, 773, 265, ofGetHeight(),265-(ofGetHeight()-773),ofGetHeight());
    ofSetColor(ofColor(194,84,113));
    ofDrawRectangle(265, 773, 135, ofGetHeight()-773);
    ofPath shadow;
    shadow.setColor(ofColor(187,135,121,100));
    shadow.newSubPath();
    shadow.lineTo(ofVec2f( ofGetWidth(), ofGetHeight()));
    shadow.lineTo(ofVec2f( ofGetWidth(), 550));
    shadow.lineTo(ofVec2f( 550, 773));
    shadow.lineTo(ofVec2f( 400, 773));
    shadow.lineTo(ofVec2f( 400 + ofGetHeight()-773, ofGetHeight()));
    shadow.close();
    shadow.draw();
}

void Self::drawMouth()
{
    ofSetColor(ofColor(205,150,143,100));
    ofDrawRectangle(400, 623, 150, 150);
    ofSetColor(ofColor(194,84,113));
    ofDrawRectangle(400, 578, 150, 60);
    ofDrawTriangle( 550, 578, 610, 578, 550, 638);
}

void Self::drawEyebow()
{
    ofSetColor(ofColor(0,0,0));
    ofDrawRectangle(265, 200, 123, 20);
    ofDrawRectangle(540, 200, 123, 20);
}

void Self::drawHair()
{
    ofSetColor(hairColor);
    ofDrawTriangle(ofGetWidth(), 0,ofGetWidth() - 200, 0,ofGetWidth(), 200);
    ofDrawTriangle(ofGetWidth() - 200, 0, 265, 123, 265, 0);
    ofDrawTriangle(142, 123, 265, 123, 265, 0);
    ofDrawRectangle(142, 123, 123, 650);
    ofDrawTriangle(265, 521, 265, 773, 400, 773);
    ofDrawTriangle(142, 650, 142, 773, 50, 773);
}

void Self::changeHairColor()
{
    float red    = ofRandom(0,255);
    float green    = ofRandom(0,255);
    float blue    = ofRandom(0,255);
    hairColor = ofColor(red, green, blue);
}

void Self::changeBackground()
{
    float red    = ofRandom(0,255);
    float green    = ofRandom(0,255);
    float blue    = ofRandom(0,255);
    bgcolor = ofColor(red, green, blue);
}

void Self::changeEyeAngle()
{
    eyeAngle += 5;
    if(eyeAngle >= 90)
        eyeAngle = 0;
}

