//
//  bmc_type.cpp
//  dailies
//
//  Created by Brian McGee on 11/12/18.
//

#include "bmc_type.hpp"

//letter setup
bmcLetter::bmcLetter(string letter) { ltr = letter; }

void bmcLetter::update(glm::vec2 p) {
	//letter update
	pos = p;
}

void bmcLetter::draw(ofTrueTypeFont &f) {
	//letter draw
	bb = f.getStringBoundingBox(ltr, 0, 0);

	ofPushMatrix();
	
		//ofRotateRad(rot);
		ofTranslate(pos.x, pos.y);
		ofRotateDeg( -ofRadToDeg(ang) + 90 );
		ofSetColor(0, 255, 0);
		//ofDrawRectangle(0, 0, 5, 5);

		ofTranslate(-bb.width/2, bb.height/2);
		if(bg) {
			bb.scaleFromCenter(1.2, 1.2);
			
			ofPopStyle();
				ofSetColor(bgc);
				ofFill();
				ofDrawRectangle(bb);
			ofPushStyle();
			
		}
	
		// DRAW STRING METHOD
		ofPopStyle();
		ofSetColor(c);
		fill ? ofFill() : ofNoFill();
		ofNoFill();
		f.drawString(ltr, 0, 0);
		ofPushStyle();

	ofPopMatrix();
}

//word
bmcStringCircle::bmcStringCircle(string s) {
	
	str = s;
	for(int i=0; i < str.size(); i++) {
		bmcLetter ltr(str.substr(i, 1));
		letters.push_back(ltr);
	}
}

void bmcStringCircle::setup() {
}

void bmcStringCircle::update() {
	//update color
	c = ofMap(life, 0, maxLife, 255, 0);
	
	//update rad on life
	rad = ofMap(life, 0, maxLife, 100, maxLife);
	
	//circle stuff
	int i = 0;
	for( auto &ltr : letters) {
		float ang = ofDegToRad(360/str.size() * i);
		ang = ang + ofDegToRad(rot);
		ltr.pos.x = rad * cos(ang) + pos.x;
		ltr.pos.y = rad * sin(ang) + pos.y;
		ltr.ang = -(ang);
		
		ltr.c = c;
		
		++i;
	}
}

void bmcStringCircle::draw(ofTrueTypeFont &f) {
	
	ofSetColor(c);
	ofNoFill();
	
	ofSetLineWidth(1);
	ofSetCircleResolution(100);
	
	ofDrawCircle(pos.x, pos.y, rad);
	
	if (fg) {
		for(int i=0; i < letters.size(); i++) {
			ofPopStyle();
				bmcLetter *ltr = &letters[i];
				if(fill) { ltr->fill = fill; };
			
				ltr->draw(f);
			
			ofPushStyle();
		}
	}
	
}
