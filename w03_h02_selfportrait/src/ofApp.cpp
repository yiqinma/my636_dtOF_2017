#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    myself.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myself.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'e')
    {
        myself.changeEyeAngle();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' ')
    {
        myself.changeBackground();
    }
    if(key == 'h')
    {
        myself.changeHairColor();
    }
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
    printf("%d \n",mouseX);
    printf("%d \n",mouseY);
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
