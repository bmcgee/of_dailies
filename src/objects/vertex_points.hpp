//
//  vertex_points.hpp
//  dailies
//
//  Created by Brian McGee on 10/30/18.
//

#ifndef vertex_points_hpp
#define vertex_points_hpp

#include <stdio.h>
#include "ofMain.h"

class VertPoints{
	
public:
	void setup();
	void update();
	void draw();
	
	//ofVec2f update(ofVec2f change, ofVec2f& pt);
	
	ofPolyline line;
	ofPath path;

	VertPoints();

	float radFreq = .5;
	float radAmp = 50;
	float thetaFreq = .8;
	float thetaAmp = 10;
	float rad = 100;
	float rotRate = .1;
	
	float transAmp = .2;
	
	ofTrueTypeFont font;
	const int fontsize = 15;

	//word class
	class Word {
	public:
		float r = 100;
		string str;
		vector<glm::vec2> pos;
		float life;
		Word(string s)  {
			str = s;
			pos.resize(s.size());
		};
	private:
	};
	
	//character class

	vector<Word> str_input;

	float fr = ofGetElapsedTimef();

private:
	
};

#endif /* vertex_points_hpp */
