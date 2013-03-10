#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofBall.h"

class testApp : public ofBaseApp{
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofImage img;
		ofImage myImage;
		ofxCvHaarFinder finder;
//ofBall myball;
		ofVideoGrabber 		vidGrabber;
		unsigned char * 	videoInverted;
		unsigned char * pixels;
		ofTexture			videoTexture;
		bool EyeLeft;
		bool EyeRight;
		int 				camWidth;
		int 				camHeight;
		int def;
		int c;
		int begin, end;
		int rectPongX;
        double time_spent;
		int a,r,g,b;
		float fr;

    private :
        ofBall *myball;


};
