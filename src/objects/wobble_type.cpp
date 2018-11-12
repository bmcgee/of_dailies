//
//  bmc_type.cpp
//  dailies
//
//  Created by Brian McGee on 11/8/18.
//

#include "wobble_type.hpp"

WobbleType::WobbleType() { };


void WobbleType::setup() {
	//load fonts
	font.load("manuka.otf", fontsize, true, true, true);
	font.setLetterSpacing(1.2);
	
	//load paths and polylines//
	
	//draw shapes
	paths = font.getStringAsPoints(s);
	
	for (int i = 0; i < paths.size(); i++){
		// for every character break it out to polylines
		//set poly winding mode
		paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
		
		
		//polyline manipulation
		for (int j = 0; j < polylines.size(); j++){
			//point manipulation
		}
	}
}

void WobbleType::update() {
	for (int i = 0; i < paths.size(); i++) {
		polylines = paths[i].getOutline();
		for (int j = 0; j < polylines.size(); j++) {
			for (int k = 0; i < polylines[j].size(); k++){
				polylines[j][k].x += ofNoise(ofGetElapsedTimef(), k);
				polylines[j][k].y += ofNoise(ofGetElapsedTimef(), -k);
			}
		}
	}
	
}

void WobbleType::draw() {
	
	//translation to center point
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2 - font.stringWidth(s)/2, ofGetHeight()/2 - font.stringHeight(s)/2);
	ofSetColor(0);
	for (int i = 0; i < paths.size(); i++) {
		
	}
	ofPopMatrix();
}
