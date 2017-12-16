
#include "Moon.hpp"
Moon::Moon(ofVec2f _cen)
{
    cenLoc = _cen;
    size = ofRandom(30,50);
    r = ofRandom(150,600);
    angle = ofRandom(TWO_PI);
    speed = ofRandom(0.005,0.02);
    loc.x = cenLoc.x + r*cos(angle);
    loc.y = cenLoc.y + r*sin(angle);
    startLoc = loc;
    color = ofColor(255,ofRandom(255),255);
}

Moon::Moon()
{
}

void Moon::draw()
{
    ofSetColor(color);
    ofDrawEllipse(int(loc.x), int(loc.y), int(size+size/10), int(size+size/10));
    ofPath half;
    half.setColor(ofColor(61,44,108));
    half.arc(loc.x, loc.y,int(size/2),int(size/2),-45,180-45);
    half.close();
    half.draw();
    int temp = size/10;
    int times = 0;
    for(int i = -size/2+1.5*temp;i < size/2-1.5*temp;i += temp)
    {
        if(times % 2 == 0)
            ofSetColor(color);
        else
            ofSetColor(61, 44, 108);
        ofSetLineWidth(temp);
        float tempLength = ofNoise(1000+times/2.0)*size/3;
        ofVec2f tempCenter = ofVec2f(loc.x+i*cos(-PI/4),loc.y+i*sin(-PI/4));
        ofDrawLine(tempCenter.x+tempLength*cos(PI/4), tempCenter.y+tempLength*sin(PI/4), tempCenter.x-tempLength*cos(PI/4), tempCenter.y-tempLength*sin(PI/4));
        times ++;
    }
}

void Moon::update()
{
    if(isBack){
        loc.x = cenLoc.x + r*cos(angle);
        loc.y = cenLoc.y + r*sin(angle);
        angle += speed;
    }
}

void Moon::changeLocation(ofVec2f dir)
{
    loc += dir;
}

void Moon::back()
{
    if(loc.x != startLoc.x || loc.y != startLoc.y)
    {
        loc += (startLoc - loc)/20;
    }
    
    if(cenLoc.distance(loc) < 2*r)
        isBack = true;
    else
        isBack = false;
}

