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
	ofColor bgc = 0;		//bgcolor;
	ofColor c = 255;		//fgcolor
	bool bg = true;			//bg bool

	void update(glm::vec2 p);
	void draw(ofTrueTypeFont f);
	
	bmcLetter(string letter);
private:
};

class bmcWordCircle {
public:
	string str;
	bool outline;
	ofColor c;
	glm::vec2 pos;
	float sz;
	vector <bmcLetter> letters;
	
	void setup();
	void update();
	void draw(ofTrueTypeFont f);
	
	//circle version
	float rad = 100;
	int size() { return letters.size(); };
	
	bmcWordCircle(string s);
private:
};



#endif /* bmc_type_hpp */
