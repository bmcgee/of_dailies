#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(true);
	ofBackground(0);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	ofEnableSmoothing();
	
	//wobble.setup();
	font.load("GT Zirkon Black", 50, true, true, true);
	
	words.push_back(bmcWordCircle("BRIAN"));
}

//--------------------------------------------------------------
void ofApp::update(){
	//framerate
	int frame = ofGetFrameNum();
	
	std::stringstream strm;
	strm << "fps: " << int(ofGetFrameRate()) << " f: " << frame;
	ofSetWindowTitle(strm.str());
	
	//wobble.update();
	if ( frame % 10 == 0) { words.push_back(bmcWordCircle("BRIAN")); }
	
	for (int i=0; i < words.size(); i++) {
		bmcWordCircle *word = &words[i];
		word->rad++;
		word->update();
		if (word->rad == 300) {
			words.erase(words.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//wobble.draw();
	
	for (int i=words.size()-1; i > 0; i--) {
		
		ofPushMatrix();
		
		ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
		float fr = ofGetFrameNum() * 5;
		ofRotateDeg( fr );
		
		ofColor a{220, 20, 0};
		ofColor b{50, 50, 200};
		ofColor c = a.lerp(b, ofMap(i, 0, words.size(), 0, 1));
		
		ofSetColor(c);
		ofNoFill();
		
		ofSetLineWidth(2);
		ofSetCircleResolution(100);
		ofDrawCircle(0, 0, words[i].rad);
		
		ofFill();
		
		for(int l=0; l < words[i].size(); l++) {
			words[i].letters[l].c = c;
		}
		
		words[i].draw(font);
		
		ofPopMatrix();
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
