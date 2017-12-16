
#include "Star.hpp"

Star::Star()
{
    interval = int(ofRandom(20,50));
    loc = ofVec2f(ofRandomWidth(),ofRandomHeight());
    startLoc = loc;
    size = int(ofRandom(5,10));
}

void Star::draw()
{
    if(count % interval <= interval/2)
    {
        ofSetColor(255,100);
        ofDrawEllipse(int(loc.x), int(loc.y), size, size);
    }
}

void Star::update()
{
    count++;
}

void Star::changeLocation(ofVec2f dir)
{
    loc += dir;
}

void Star::back()
{
    if(loc.x != startLoc.x || loc.y != startLoc.y)
    {
        loc += (startLoc - loc)/20;
    }
}


