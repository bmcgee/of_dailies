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
	
	vector<ofVec2f> pts;
	
	VertPoints();
	
	int total_pts = 20;
private:
	
};



#endif /* vertex_points_hpp */
