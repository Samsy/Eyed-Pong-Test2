#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{

    camWidth 		= 640;
    camHeight 		= 360;
    rectPongX = camWidth/2;
    videoTexture.allocate(camWidth,camHeight, GL_RGB);
    fondTexture.allocate(300,360, GL_RGB);
    detail.loadImage("fond.jpg");
    fond = detail.getPixels();
    fondTexture.loadData(fond, 300,360, GL_RGB);

    finder.setup("haarcascade_eye_tree_eyeglasses.xml");

    cam.setDeviceID(0);
    cam.setVerbose(true);
    cam.initGrabber(640,360);

    myball = new ofBall(camWidth/2,camHeight/2,camWidth,camHeight);
}


//--------------------------------------------------------------
void testApp::update()
{
    grabAndDetect();
    myball->update(rectPongX);
    MyTween.update(myball->ax,myball->ay);
}


//--------------------------------------------------------------
void testApp::draw()
{
    ofSetColor(255,255,255);
    videoTexture.draw(0,0,camWidth,camHeight);
    fondTexture.draw(camWidth,0,300,360);
    analyseAndDrawBlob();
    drawRect();

    myball->draw();
    MyTween.draw();

    if((myball->ay > camHeight+10) || (myball->ay < 0) )
    {
        myball = new ofBall(camWidth/2,camHeight/2,camWidth,camHeight);
    }
}

//--------------------------------------------------------------

void testApp::grabAndDetect()
{
    cam.update();
    if(cam.isFrameNew())
    {
        img.setFromPixels(cam.getPixelsRef());
        videoTexture.loadData(cam.getPixels(), camWidth,camHeight, GL_RGB);
        finder.findHaarObjects(img);
    }
}

//--------------------------------------------------------------

void testApp::analyseAndDrawBlob()
{

    EyeLeft=false;
    EyeRight=false;
    ofNoFill();
    ofLine(camWidth/2,100,camWidth/2,camHeight-100);

    for(int i = 0; i < finder.blobs.size(); i++)
    {
        ofRectangle cur = finder.blobs[i].boundingRect;
        ofRect(cur.x, cur.y, cur.width, cur.height);

        if(cur.x+(cur.width/2) > camWidth/2)
        {
            EyeLeft=true;
        }
        else
        {
            EyeRight=true;
        }
    }
}

//--------------------------------------------------------------

void testApp::drawRect()
{
    ofFill();
    if (!EyeLeft && (rectPongX > 0))
    {
        rectPongX-=15;
    }

    if (!EyeRight && (rectPongX < camWidth-50))
    {
        rectPongX+=15;
    }


    ofRect(rectPongX,camHeight-40,50,20);
    ofRect (myball->ax-25, 40, 50,20);
    ofSetColor(255,0,0);
}

//--------------------------------------------------------------

void testApp::exit()
{

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
