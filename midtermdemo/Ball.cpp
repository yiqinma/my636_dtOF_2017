
#include "Ball.h"

Ball::Ball()
{
    f = 0;
    float cenX = ofGetWidth()/2;
    float cenY = ofGetHeight()/2;
    int i = int(ofRandom(2100))%500;
    i = 300;
    speed = 40;
    id = i;
    loc = ofVec2f(cenX + i*cos(PI*(i*8+f)/180),cenY + i*sin(PI*(i*8+f)/180));
    i --;
    ofVec2f temp = ofVec2f(cenX + i*cos(PI*(i*8+f)/180),cenY + i*sin(PI*(i*8+f)/180));
    velocity = (temp-loc)/speed;
    //stairSpeed();
    bounce();
    //loc = loc + velocity;
}

void Ball::display()
{
    float cenX = ofGetWidth()/2;
    float cenY = ofGetHeight()/2;
    ofSetColor(255,0,0,id/2);
    ofDrawCircle(loc.x,loc.y,0.02*id);
}

void Ball::update(float ff)
{
    float cenX = ofGetWidth()/2;
    float cenY = ofGetHeight()/2;
    int i = id - 1;
    f = ff;
    ofVec2f temp = ofVec2f(cenX + i*cos(PI*(i*8+f)/180),cenY + i*sin(PI*(i*8+f)/180));
    if(ofDist(loc.x,loc.y,temp.x,temp.y)<10)
    {
        id --;
        i = id - 1;
        speed -= 0.7;
        temp = ofVec2f(cenX + i*cos(PI*(i*8+f)/180),cenY + i*sin(PI*(i*8+f)/180));
        velocity = (temp-loc)/speed;
        //stairSpeed();
        bounce();
    }
    gravity();
    loc = loc + velocity;
}

void Ball::stairSpeed()
{
    float cenX = ofGetWidth()/2;
    float cenY = ofGetHeight()/2;
    ofVec2f s = ofVec2f(cenX + id*cos(PI*(id*8+f)/180),cenY + id*sin(PI*(id*8+f)/180)) - ofVec2f(cenX + id*cos(PI*(id*8+f-0.5)/180),cenY + id*sin(PI*(id*8+f-0.5)/180)) ;
    velocity = -s;
}

void Ball::bounce()
{
    float a = 0.1*speed/2;
    ofVec2f b = ofVec2f(cos(PI*(id*8+f)/180),sin(PI*(id*8+f)/180));
    b *= a;
    velocity += b;
}

void Ball::gravity()
{
    float a = 0.1;
    ofVec2f g = ofVec2f(ofGetWidth()/2-loc.x,ofGetHeight()/2-loc.y);
    g.normalize();
    g *= a;
    velocity += g;
}

bool Ball::isDone()
{
    if(ofDist(ofGetWidth()/2,ofGetHeight()/2,loc.x,loc.y) < 10)
        return true;
    else
        return false;
}
