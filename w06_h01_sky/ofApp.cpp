#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sky = Sky();
    sack = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(sack)
    {
        sky.sack(ofVec2f(mouseX,mouseY));
    }else
    {
        sky.back();
        sky.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(61,44,108);
    sky.draw();
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
    sack = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    sack = false;
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
