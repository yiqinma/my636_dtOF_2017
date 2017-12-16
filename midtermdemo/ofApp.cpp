#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    f = 0;
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = balls.size() - 1;i >= 0;i--){
        balls[i].update(f);
        if(balls[i].isDone()){
            balls.erase(balls.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    float cenX = ofGetWidth()/2;
    float cenY = ofGetHeight()/2;
    for (int i= 0; i<700; i++) {
        ofSetColor(i/2,i/2,i/2);
        ofDrawRectangle(cenX + i*cos(PI*(i*8+f)/180),cenY + i*sin(PI*(i*8+f)/180),1+i*0.06,1+i*0.06);
    }
    f -= 0.5;
    for(int i = balls.size() - 1;i >= 0;i--){
        balls[i].display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    balls.push_back(Ball());
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
