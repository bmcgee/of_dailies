#pragma once

#include "ofMain.h"
#include "ofxGui.h"
//#include "spintype.hpp"
//#include "wobble_type.hpp"
#include "bmc_type.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		int framerate = 60;
	
		ofxPanel gui;
		ofxFloatSlider radius;
		ofxFloatSlider rotation;
		ofxIntSlider emit;

	
	//bmcWordCircle word;
	bmcStringCircle firstWord = bmcStringCircle("Park that car.");

	vector <bmcStringCircle> words;
	
	
	int start_radius = 10;
	ofTrueTypeFont font;
	
	//int radius = 100;
};
