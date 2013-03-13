#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofBall.h"
#include "tween.h"

class testApp : public ofBaseApp{
	public:

		void setup();
		void update();
		void draw();
		void grabAndDetect();
		void analyseAndDrawBlob();;
		void drawRect();
		void exit();
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
		ofImage detail;

		ofTexture			videoTexture;
		ofTexture			fondTexture;

		ofxCvHaarFinder finder;
        ofVideoGrabber cam;
        tween MyTween;

		unsigned char * pixels;
		unsigned char * fond;

		bool EyeLeft;
		bool EyeRight;
		int  camWidth;
		int  camHeight;
		int rectPongX;

		ofTrueTypeFont	verdana14;
        string typeStr;


    private :

        ofBall *myball;


};


