#include "ofAppGlutWindow.h"
#include "testApp.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 940, 360, OF_WINDOW);
	ofSetWindowPosition(200,300);
    ofSetWindowTitle("Eyed-Pong");
	ofRunApp(new testApp());
}
