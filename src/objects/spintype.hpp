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

	ofTrueTypeFont font;
	const int fontsize = 80;

	//word class
	class Word {
	public:
		float r = 100;
		string str;
		vector<glm::vec2> pos;
		float life = 100;
		size_t t;
		
		Word(string s)  {
			str = s;
			pos.resize(str.size());
			t = str.size();
		};

		int size() { return str.size(); };
	
		void update();
		void draw(ofTrueTypeFont font);

	private:
	};
	
	//character class

	vector<Word> str_input;

	float fr = ofGetElapsedTimef();

private:
	
};

#endif /* vertex_points_hpp */
