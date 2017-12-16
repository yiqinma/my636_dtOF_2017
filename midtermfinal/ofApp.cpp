#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = jellyfishs.size()-1;i>=0;i--)
    {
        jellyfishs[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    for(int i = jellyfishs.size()-1;i>=0;i--)
    {
        jellyfishs[i].display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        jellyfishs.push_back(Jellyfish(ofGetWidth()/2,ofGetHeight()/2));
    }else if(key == 'm'){
        jellyfishs.push_back(Jellyfish(ofGetMouseX(),ofGetMouseY()));
    }else if(key == 'r'){
        jellyfishs.push_back(Jellyfish());
    }
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
    for(int i = jellyfishs.size()-1;i>=0;i--)
    {
        ofVec2f temp = ofVec2f(ofGetMouseX(),ofGetMouseY());
        jellyfishs[i].dir = temp - jellyfishs[i].loc;
        jellyfishs[i].dir.normalize();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
