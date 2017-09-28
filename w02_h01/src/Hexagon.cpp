#include "Hexagon.h"

Hexagon::Hexagon()
{
	edgeLength = ofRandom(30, 90);

	float red = ofRandom(0, 255);
	float green = ofRandom(0, 255);
	float blue = ofRandom(0, 255);
	color = ofColor(red, green, blue);

	x = ofRandom(edgeLength, ofGetWidth() - edgeLength);
	y = ofRandom(edgeLength, ofGetHeight() - edgeLength * sqrt(3) / 2);

	dirX = ofRandom(-10, 10);
	dirY = ofRandom(-10, 10);
}

void Hexagon::update()
{
	x += dirX;
	y += dirY;

	if (x <= edgeLength)
	{
		x = edgeLength;
		dirX = -dirX;
	}

	else if (x >= ofGetWidth() - edgeLength)
	{
		x = ofGetWidth() - edgeLength;
		dirX = -dirX;
	}

	if (y <= edgeLength * sqrt(3) / 2)
	{
		y = edgeLength * sqrt(3) / 2;
		dirY = -dirY;
	}

	else if (y >= ofGetHeight() - edgeLength * sqrt(3) / 2)
	{
		y = ofGetHeight() - edgeLength * sqrt(3) / 2;
		dirY = -dirY;
	}
}

void Hexagon::draw()
{
	ofPath path;
	path.setColor(color);
	path.newSubPath();
	float i = 0;
	while (i < TWO_PI) 
	{
		float px = x + edgeLength * cos(i);
		float py = y + edgeLength * sin(i);
		path.lineTo(ofVec2f(px, py));
		i += PI / 3;
	}
	path.close(); // close the shape
	path.draw();
}

