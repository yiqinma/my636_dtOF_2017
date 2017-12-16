
#include "Sky.hpp"

Sky::Sky()
{
    sunLoc = ofVec2f(3*ofGetWidth()/4,3*ofGetHeight()/4);
    starNumber = 100;
    for(int i = 0; i < starNumber;i ++)
    {
        stars.push_back(Star());
    }
    moonNumber = 10;
    for(int i = 0; i < moonNumber;i ++)
    {
        moons.push_back(Moon(sunLoc));
    }
}

void Sky::draw()
{
    for(int i = 0; i < stars.size();i++)
    {
        stars[i].draw();
    }
    for(int i = 0; i < moons.size();i++)
    {
        moons[i].draw();
    }
    drawSun();
}

void Sky::drawSun()
{
    ofSetColor(227,252,150);
    ofDrawCircle(sunLoc.x, sunLoc.y, 100);
    ofSetColor(61,44,108);
    ofDrawCircle(sunLoc.x, sunLoc.y, 90);
    ofPath half;
    half.setColor(ofColor(144,44,173));
    half.arc(sunLoc.x, sunLoc.y,90,90,135,135+180);
    half.close();
    half.draw();
    int temp = 10;
    int times = 0;
    for(int i = -90+1.5*temp;i < 90-1.5*temp;i += temp)
    {
        if(times % 2 == 0)
            ofSetColor(144, 44, 173);
        else
            ofSetColor(61, 44, 108);
        ofSetLineWidth(temp);
        float tempLength = ofNoise(1000+times/2.0)*50;
        ofVec2f tempCenter = ofVec2f(sunLoc.x+i*cos(-PI/4),sunLoc.y+i*sin(-PI/4));
        ofDrawLine(tempCenter.x+tempLength*cos(PI/4), tempCenter.y+tempLength*sin(PI/4), tempCenter.x-tempLength*cos(PI/4), tempCenter.y-tempLength*sin(PI/4));
        times ++;
    }
}

void Sky::update()
{
    for(int i = 0; i < stars.size();i++)
    {
        stars[i].update();
    }
    for(int i = 0; i < moons.size();i++)
    {
        moons[i].update();
    }
}

void Sky::sack(ofVec2f loc)
{
    
    for(int i = 0; i < stars.size();i++)
    {
        ofVec2f dir = (loc - stars[i].loc)/30;
        stars[i].changeLocation(dir);
    }
    for(int i = 0; i < moons.size();i++)
    {
        ofVec2f dir = (loc - moons[i].loc)/30;
        moons[i].changeLocation(dir);
    }
    ofVec2f dir = (loc - sunLoc)/30;
    changeSunLocation(dir);
}

void Sky::back()
{
    for(int i = 0; i < stars.size();i++)
    {
        stars[i].back();
    }
    for(int i = 0; i < moons.size();i++)
    {
        moons[i].back();
    }
    sunBack();
}

void Sky::changeSunLocation(ofVec2f dir)
{
    sunLoc += dir;
}
void Sky::sunBack()
{
    ofVec2f startLoc = ofVec2f(3*ofGetWidth()/4,3*ofGetHeight()/4);
    sunLoc += (startLoc - sunLoc)/20;
}
