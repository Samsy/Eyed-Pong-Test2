#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    camWidth 		= 640;
	camHeight 		= 360;
	def = camWidth*camHeight*3;
int totalPixels = camWidth*camHeight*3;
 rectPongX = camWidth/2;


	vidGrabber.setDeviceID(0);
    vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);
	videoTexture.allocate(camWidth,camHeight, GL_RGB);
	finder.setup("haarcascade_eye_tree_eyeglasses.xml");

myball = new ofBall(camWidth/2,camHeight/2,camWidth,camHeight);

}

//--------------------------------------------------------------
void testApp::update(){
	//vidGrabber.update();

vidGrabber.grabFrame();
if(vidGrabber.isFrameNew())
{
       pixels = vidGrabber.getPixels();
    img.setFromPixels(vidGrabber.getPixelsRef());
    finder.findHaarObjects(img);
videoTexture.loadData(pixels, camWidth,camHeight, GL_RGB);
myball->update();

}


}

//--------------------------------------------------------------
void testApp::draw(){
videoTexture.draw(0,0,camWidth,camHeight);
	//img.draw(0, 0);
bool EyeLeft=false;
bool EyeRight=false;
ofNoFill();
	for(int i = 0; i < finder.blobs.size(); i++) {
		 ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
		 if(cur.x > camWidth/2){
                //cout <<" Oeil Gauche : Ouvert " << cur.x << endl;
                EyeLeft=true;}

		 else {
                //cout <<" Oeil Droit : Ouvert " << cur.x << endl;
                EyeRight=true;}
	}

	ofLine(camWidth/2,50,camWidth/2,camHeight-50);
ofFill();
    if (!EyeLeft && (rectPongX > 0)){ rectPongX-=10; }
    if (!EyeRight && (rectPongX < camWidth-50)){ rectPongX+=10;}

    ofRect(rectPongX,camHeight-40,50,20);
    ofRect (myball->ax, 40, 50,20);

  if ((myball->ay > camHeight-60) && (myball->ax > rectPongX ) && (myball->ax < (rectPongX+50)) ) { myball->speedY = -5; }
  if ((myball->ay > camHeight-60) && (myball->ax > rectPongX ) && (myball->ax < (rectPongX+50)) ) { myball->speedY = -5; }

  if (myball->ay < 70 ) { myball->speedY = 5; }
  //if ((myball->ay > camHeight-60) && (myball->ax > rectPongX ) && (myball->ax < (rectPongX+50)) ) { myball->speedY = -5; }

//cout << "X DE LA BALLE " << myball->ax << endl;
//cout << "X DU RECT  " << rectPongX << endl;
   ofSetColor(255,0,0);
    myball->draw();
    ofSetColor(255,255,255);





}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
