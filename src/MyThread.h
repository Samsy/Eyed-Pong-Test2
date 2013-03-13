#ifndef MYTHREAD_H_INCLUDED
#define MYTHREAD_H_INCLUDED


#include "ofMain.h"



class MyThread : public ofThread{

	public:

 ofVideoGrabber cam; // the cam
 ofImage ImageCam;

unsigned char * pixels2;
bool flag;

		MyThread (){
    cam.setDeviceID(1);
    cam.setVerbose(true);
	cam.initGrabber(640,360);
   flag=false;

   		}

		void start(){
            startThread(true, false);

        }

        void stop(){
            stopThread();
        }


		void threadedFunction(){
 while(isThreadRunning()) {

            cam.update();
            if(cam.isFrameNew()) {
                lock();
                flag=true;
                // load the image
               pixels2 = cam.getPixels();
            ImageCam.setFromPixels(cam.getPixelsRef());
               // pixels2.setFromPixels(cam.getPixelsRef());
                unlock();

            }
        }

		}

		//--------------------------
		void draw(){


		}



};

#endif









