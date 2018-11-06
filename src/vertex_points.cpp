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
		
		float fr = ofGetElapsedTimef();
		
		rad = (sin(fr*2) * 1.2) * 50;
		//cout << sin(fr);
		
		float r = rad + (ofNoise(fr*radFreq, i)*radAmp);

		float theta = (ofNoise(fr*thetaFreq, -i) * thetaAmp);
		theta = ((360 / total_pts * i ) + theta) ;
		
		float x = r * cos(ofDegToRad(theta));
		float y = r * sin(ofDegToRad(theta));
		//working on implenting theta coordiantes.
		
		pts[i].x = ofMap(x, 0, 1, 0, ofGetWidth());
		pts[i].y = ofMap(y, 0, 1, 0, ofGetHeight());

		float xCenter = ofMap(ofNoise(fr*transAmp), 0, 1, 0, ofGetWidth());
		float yCenter = ofMap(ofNoise(-fr*transAmp), 0, 1, 0, ofGetHeight());
		pts[i].x = x + xCenter;
		pts[i].y = y + yCenter;

		
	}
	
}

void VertPoints::draw(){
	//draw pts
	line.clear();
	for(int i = 0; i < pts.size(); i++){
		ofSetColor(0);
		ofNoFill();
		ofPoint temp = pts[i];
		ofDrawCircle(pts[i], 2);
		line.addVertex(temp);

	}
	line.close();
	ofSetColor(0, 0, 0, 100);
	ofNoFill();
	line.draw();
	
}
