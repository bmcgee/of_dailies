//
//  bmc_type.hpp
//  dailies
//
//  Created by Brian McGee on 11/12/18.
//

#ifndef bmc_type_hpp
#define bmc_type_hpp

#include <stdio.h>
#include "ofMain.h"

class bmcLetter {
public:
	string ltr;
	glm::vec2 pos;			//position
	float ang; 				//rotation
	ofRectangle bb;			//bounding box
	ofColor bgc = {0,0,0};		//bgcolor;
	ofColor c = 255;		//fgcolor
	bool fill = false;
	bool bg = false;
	//bg bool

	void update(glm::vec2 p);
	void draw(ofTrueTypeFont &f);
	
	bmcLetter(string letter);
private:
};


class bmcStringCircle {
public:
	string str;
	glm::vec2 pos;
	
	bool fg = true;
	float sz;
	bool fill = false;
	float rot = 0;
	int life = 0;
	int maxLife = 400; 
	
	ofColor c;
	vector <bmcLetter> letters;
	
	void setup();
	void update();
	void draw(ofTrueTypeFont &f);
	
	//circle version
	float rad = 100;
	
	int size() { return letters.size(); };
	
	bmcStringCircle(string s);
	
private:
};


#endif /* bmc_type_hpp */
