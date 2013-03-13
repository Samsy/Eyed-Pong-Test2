#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofBall.h"
#include "MyThread.h"
#include "tween.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
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
		ofxCvHaarFinder finder;
		ofVideoGrabber 		vidGrabber;
        tween MyTween;
		unsigned char * pixels;
		unsigned char * fond;

		ofTexture			videoTexture;
		ofTexture			fondTexture;
		bool EyeLeft;
		bool EyeRight;
		int 				camWidth;
		int 				camHeight;
		int rectPongX;
		ofTrueTypeFont	verdana14;
        string typeStr;
        MyThread thread;

    private :
        ofBall *myball;


        //MyThread *thread;

};


