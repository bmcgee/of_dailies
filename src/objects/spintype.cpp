//
//  vertex_points.cpp
//  dailies
//
//  Created by Brian McGee on 10/30/18.
//

#include "spintype.hpp"

VertPoints::VertPoints(){
}

void VertPoints::setup(){
	cout << "Setting up:" << endl;
	
	font.load("manuka.otf", fontsize, true, true, true);
	
	Word tempWord("BRIAN");
	str_input.push_back(tempWord);
}

void VertPoints::update(){
	float fr = ofGetElapsedTimef();

	for(int i = 0; i < str_input.size(); i++) {
		Word *word = &str_input[i];
		for(int j = 0; j < word->size(); j++)  {
			float theta = (360/word->size()) * j;
			float x = str_input[i].r * cos(ofDegToRad(theta));
			float y = str_input[i].r * sin(ofDegToRad(theta));
			str_input[i].pos[j].x = x;
			str_input[i].pos[j].y = y;
		}
	}
	
}

void VertPoints::draw(){
	float fr = ofGetElapsedTimef();

	ofSetColor(0);
	
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	for(int i = 0; i < str_input.size(); i++) {
		Word *word = &str_input[i];
		word->draw(font);
	}
	line.close();
	//path.close();
	
	path.setFilled(true);
	path.setFillColor(ofColor(0,0,0,10));
	path.setStrokeWidth(2);
	path.setStrokeColor(ofColor(0,0,0));
	
	path.draw();
	
	//line.draw();
	
}

void VertPoints::Word::draw(ofTrueTypeFont font) {
	ofPushMatrix();
	ofRotateDeg(ofGetElapsedTimef()*2);
	for(int i = 0; i < life; i++ ) {
		ofTranslate(0, 0, 10);
		for(int j = 0; j < str.size(); j++) {
			ofFill();
			ofColor a = ofColor(255, 150, 0, 100);
			ofColor b = ofColor(31, 82, 224, 100);
			ofColor c = a.lerp(b, ofMap(i, 0, life, 0, 1));
			ofSetColor(c);
			font.drawStringAsShapes(str.substr(j, 1), pos[j].x, pos[j].y);
			ofNoFill();
		//	ofSetColor(255, 0, 0, ofMap(i, 0, life, 255, 0));
			font.drawStringAsShapes(str.substr(j, 1), pos[j].x, pos[j].y);
		}
	}
	ofPopMatrix();

}

