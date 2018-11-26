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

void bmcLetter::draw(ofTrueTypeFont f) {
	//letter draw
	bb = f.getStringBoundingBox(ltr, 0, 0);

	ofPushMatrix();
		//bb = f.getBoundingBox
	
		//ofRotateRad(rot);
		ofTranslate(pos.x, pos.y);
		ofRotateDeg( -ofRadToDeg(ang) + 90 );
		ofSetColor(0, 255, 0);
		ofDrawRectangle(0, 0, 5, 5);

		ofTranslate(-bb.width/2, bb.height/2);
		if(bg) {
			ofSetColor(bgc);
			//ofDrawRectangle(bb);
		}
		ofSetColor(c);
	
		// DRAW STRING METHOD
		f.drawString(ltr, 0, 0);

		//DRAW VBO ATTEMPT
//		ofVboMesh mesh;
//		f.getStringMesh(ltr, 0, 0);
//
//		f.getFontTexture().bind();
//		mesh.draw();
//		f.getFontTexture().unbind();

	ofPopMatrix();
}

//word
bmcWordCircle::bmcWordCircle(string s) {
	str = s;
	for(int i=0; i < str.size(); i++) {
		bmcLetter ltr(str.substr(i, 1));

		//add to word
		letters.push_back(ltr);
	}
}

void bmcWordCircle::setup() {

}

void bmcWordCircle::update() {
	//circle stuff
	int i = 0;
	for( auto &ltr : letters) {
		float ang = ofDegToRad(360/str.size() * i);
		ltr.pos.x = rad * cos(ang);
		ltr.pos.y = rad * sin(ang);
		ltr.ang = -(ang);
		++i;
	}
}

void bmcWordCircle::draw(ofTrueTypeFont f) {
	for(int i=0; i < letters.size(); i++) {
		bmcLetter ltr = letters[i];
		ltr.draw(f);
	}
}
