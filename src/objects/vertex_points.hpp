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
	
	vector<glm::vec2> pts;
	int total_pts = 10;
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
	string str = "brian";
	
	vector<string> str_input;

private:
	
};

class StrPts {
public:
	float life;
	char c;
	//float r;
	glm::vec2 pos;
	//float theta;
	
	StrPts(int x, int y, char c)
	
	void draw();
private:
		
}



#endif /* vertex_points_hpp */
