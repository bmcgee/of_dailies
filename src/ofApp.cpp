#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofBackground(255);
	
	//ofEnableBlendMode(OF_BLENDMODE_ADD);

	vtpts.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	vtpts.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushStyle();
	ofSetColor(255, 255, 255, 200);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofPopStyle();
	
	vtpts.draw();

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
