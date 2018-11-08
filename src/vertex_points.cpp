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
	
	for(int i = 0; i < total_pts; i++) {
		ofVec2f temp(0, 0);
		pts.push_back(temp);
	}
	//path.newSubPath();
}

void VertPoints::update(){
	for(int i = 0; i < total_pts; i++) {
		
		float fr = ofGetElapsedTimef();
		
		//rad = ofMap((sin(fr*2) * 1.2) * 50;
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
	path.clear();
	
	auto commands = path.getCommands();
	
	path.moveTo(pts[9]);
	path.curveTo(pts[0]);
	for(int i = 0; i < 3; i++){
		ofSetColor(0);
		ofNoFill();
		ofPoint temp = pts[i];
		//ofDrawCircle(pts[i], 2);
		line.addVertex(temp);
		path.curveTo(pts[i]);
		ofDrawBitmapString(ofToString(i), pts[i].x, pts[i].y);

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
