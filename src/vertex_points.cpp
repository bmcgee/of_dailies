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
	cout << "Setting up" << endl;
	
	for(int i = 0; i < total_pts; ++i) {
		ofVec2f temp(0, 0);
		pts.push_back(temp);
	}
}

void VertPoints::update(){
	for(int i = 0; i < total_pts; ++i) {
		float x = ofNoise(ofGetElapsedTimef()/10, i);
		float y = ofNoise(ofGetElapsedTimef()/10, -i);
		
		pts[i].x = ofMap(x, 0, 1, 0, ofGetWidth());
		pts[i].y = ofMap(y, 0, 1, 0, ofGetHeight());
		
	}

}

void VertPoints::draw(){
	for(int i = 0; i < pts.size(); ++i){
		ofSetColor(0);
		ofNoFill();
		ofDrawCircle(pts[i], 2);
	}
	
}
