#pragma once
#include "ofMain.h"


class Hexagon
{
public:
	Hexagon();
	Hexagon(float px, float py);

	void update();
	void draw();

	float edgeLength;
	float x, y;
	float dirX, dirY;

	ofColor color;
    float windSpeedX;
    float windSpeedY;
    
    void setWindSpeed(float px , float py);
    void addWindForce();
    
};
