#include "ofAppGlutWindow.h"
#include "testApp.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 640, 360, OF_WINDOW);

	ofRunApp(new testApp());
}
