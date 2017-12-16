
#include "Shape.hpp"

Shape::Shape(){
    loc = ofVec2f(ofRandomWidth(),ofRandom(-150,50));
    dir = ofVec2f(0, 0);
    color = ofColor(227,255,ofRandom(255),ofRandom(150,255));
    diameter = ofRandom(20,30);
    speed = ofRandom(4,7);
    SPEED = speed;
    number = int(ofRandom(3,6));
}

Shape::Shape(float r,float g,float b){
    loc = ofVec2f(ofRandomWidth(),ofRandom(-150,50));
    dir = ofVec2f(0, 0);
    color = ofColor(r,g,b,ofRandom(150,255));
    diameter = ofRandom(20,30);
    speed = ofRandom(4,7);
    SPEED = speed;
    number = int(ofRandom(3,6));
    
}

void Shape::draw(){
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofPath s;
    s.setColor(color);
    s.newSubPath();
    for(int i = 0;i < number;i++){
        ofVec2f t = ofVec2f(cos(i*TWO_PI/number)*diameter,sin(i*TWO_PI/number)*diameter);
        s.lineTo(t);
    }
    s.close();
    s.draw();
    ofPopMatrix();
}

void Shape::update(float x,float y,float dia){
    ofVec2f face = ofVec2f(x,y);
    if(loc.distance(face)<dia/2+diameter){
        if(face.distance(ofVec2f(ofGetWidth()/2,ofGetHeight()/2)) > 50){
            dir.y *= -1;
            dir.x = ofMap((loc.x-x), -(dia/2+diameter), dia/2+diameter, -0.5, 0.5);
        }
    }
    if(face.distance(ofVec2f(ofGetWidth()/2,ofGetHeight()/2)) > 50){
        dir.y += 0.05;
    }else{
        dir = ofVec2f(ofGetWidth()/2-loc.x,ofGetHeight()/2-loc.y);
        dir.normalize();
    }
    ofVec2f vel = ofVec2f(dir.x,dir.y);
    vel *= speed;
    loc += vel;
    if(face.distance(ofVec2f(ofGetWidth()/2,ofGetHeight()/2)) < 50){
        if(loc.distance(face)<dia/2){
            loc = ofVec2f(ofRandomWidth(),ofRandom(-150,50));
            dir = ofVec2f(0, 0);
        }
    }else{
        if(loc.y > ofGetHeight()){
            loc = ofVec2f(ofRandomWidth(),ofRandom(-150,50));
            dir = ofVec2f(0, 0);
        }
    }
}

