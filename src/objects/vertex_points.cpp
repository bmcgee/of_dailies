//
//  vertex_points.cpp
//  dailies
//
//  Created by Brian McGee on 10/30/18.
//

#include "vertex_points.hpp"

VertPoints::VertPoints(){
}

void VertPoints::setup(){
	cout << "Setting up:" << endl;
	
	font.load("manuka.otf", fontsize, true, true, true);
	
	Word tempWord("brian");
	str_input.push_back(tempWord);
}

void VertPoints::update(){
	float fr = ofGetElapsedTimef();

	for(int i = 0; i < str_input.size(); i++) {
		auto word = str_input[i];
		for(int j = 0; i < word.str.size(); j++)  {
			float theta = (360/word.str.size()) * i;
			float x = word.r * cos(ofDegToRad(theta));
			float y = word.r * sin(ofDegToRad(theta));
			word.pos[j] = {x, y};
		}
	}
	
}

void VertPoints::draw(){
	float fr = ofGetElapsedTimef();

	ofSetColor(0);
	ofNoFill();
	
	for(int i = 0; i < str_input.size(); i++) {
		auto word = str_input[i];
		for(int j = 0; i < word.str.size(); j++)  {
			font.drawString(word.str.substr(j, 1), word.pos[j].x, word.pos[j].y);
		}
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
