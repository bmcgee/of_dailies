#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(true);
	ofBackground(0);
	ofEnableAlphaBlending();
	ofSetFrameRate(framerate);
	ofEnableSmoothing();
	
	gui.setup();
	gui.add(radius.setup("radius", .5, 0, 10));
	gui.add(rotation.setup("rotation", .5, 0, 10));
	gui.add(emit.setup("emit", 10, 0, 100));

	
	//wobble.setup();
	font.load("GT Zirkon Black", 40, true, true, true);
	
	firstWord.rad = radius;
	//words.push_back(firstWord);
}

//--------------------------------------------------------------
void ofApp::update(){
	//framerate
	int frame = int(ofGetFrameNum());
	int fps = int(ofGetFrameRate());
	
	std::stringstream strm;
	strm << "fps: " << int(ofGetFrameRate()) << " f: " << frame;
	ofSetWindowTitle(strm.str());
	
	//wobble.update();
	firstWord.pos = {ofGetMouseX(), ofGetMouseY()};
	if ( frame % emit == 0) { words.push_back(firstWord); }
	
	for (int i=0; i < words.size(); i++) {
		bmcStringCircle *word = &words[i];
//		word->rad = word->rad + radius;
		word->rot = word->rot + rotation;
		word->life++;
		word->update();
		if (word->life == word->maxLife) {
			words.erase(words.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//wobble.draw();
	
	for (int i=0; i < words.size(); i++) {
		
		ofPushMatrix();
		
			//center drawing
			//ofTranslate(ofGetMouseX(), ofGetMouseY());
		words[i].draw(font);
		
		ofPopMatrix();
	}
	
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		words.clear();
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
