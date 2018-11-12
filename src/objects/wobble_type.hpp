//
//  bmc_type.hpp
//  dailies
//
//  Created by Brian McGee on 11/8/18.
//

#ifndef bmc_type_hpp
#define bmc_type_hpp

#include <stdio.h>
#include "ofMain.h"


class WobbleType {
	
public:
	WobbleType();
	void setup();
	void update();
	void draw();
	
	ofTrueTypeFont font;
	const int fontsize = 100;
	const string s  = "HELLO WORLD";
	
	vector<ofPath> paths;
	vector<ofPolyline> polylines;
	
	
private:
};

#endif /* bmc_type_hpp */
