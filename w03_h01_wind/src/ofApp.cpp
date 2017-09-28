#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor::peachPuff);
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < hexes.size(); ++i)
	{
		hexes[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < hexes.size(); ++i)
	{
		hexes[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        for (int i = 0; i < hexes.size(); ++i)
        {
            hexes[i].setWindSpeed(4, 0);
            hexes[i].addWindForce();
        }
    }
    if(key == 'd'){
        for (int i = 0; i < hexes.size(); ++i)
        {
            hexes[i].setWindSpeed(-4, 0);
            hexes[i].addWindForce();
        }
    }
    if(key == 'w'){
        for (int i = 0; i < hexes.size(); ++i)
        {
            hexes[i].setWindSpeed(0, 4);
            hexes[i].addWindForce();
        }
    }
    if(key == 's'){
        for (int i = 0; i < hexes.size(); ++i)
        {
            hexes[i].setWindSpeed(0, -4);
            hexes[i].addWindForce();
        }
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	hexes.push_back(Hexagon(x, y));
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
