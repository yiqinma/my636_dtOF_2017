#pragma once
#include "ofMain.h"

class Ball{
    public:
        ofVec2f loc;
        ofVec2f velocity;
        Ball();
        float f;
        float speed;
        int id;
        void display();
        void update(float ff);
        bool isDone();
        void bounce();
        void gravity();
        void stairSpeed();
};


