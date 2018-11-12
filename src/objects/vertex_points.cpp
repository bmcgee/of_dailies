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
	
	font.load("manuka.otf", fontsize, true, true, true);
	total_pts = str.size();
	
}

void VertPoints::update(){
	for(int i = 0; i < total_pts; i++) {
		
		float fr = ofGetElapsedTimef();
		
		
		float r = 100;
		float theta = (360/total_pts) * i;
		
		float x = r * cos(ofDegToRad(theta));
		float y = r * sin(ofDegToRad(theta));
		//working on implenting theta coordiantes.
		
		pts[i].x = ofMap(x, 0, 1, 0, ofGetWidth());
		pts[i].y = ofMap(y, 0, 1, 0, ofGetHeight());
		
		float xCenter = ofGetWidth()/2;
		float yCenter = ofGetHeight()/2;
		pts[i].x = x + xCenter;
		pts[i].y = y + yCenter;
		
		
	}
	
}

void VertPoints::draw(){

	auto commands = path.getCommands();

	for(int i = 0; i < total_pts; i++){
		ofSetColor(0);
		ofNoFill();
		ofPoint temp = pts[i];
		//ofDrawCircle(pts[i], 2);
		line.addVertex(temp);
		//path.curveTo(pts[i]);
		string tempstr = str.substr(i,1);
		font.drawString(tempstr, pts[i].x, pts[i].y);
		//ofDrawBitmapString(ofToString(i), pts[i].x+3, pts[i].y-1);
		
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
