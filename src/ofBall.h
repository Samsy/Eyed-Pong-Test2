#ifndef _OF_BALL // if this class hasn't been defined, the program can define it
#define _OF_BALL // by using this if statement you prevent the class to be called more
                 // than once which would confuse the compiler

#include "ofMain.h"

class ofBall {

    public: // place public functions or variables declarations here

        // methods, equivalent to specific functions of your class objects
        void update();  // update method, used to refresh your objects properties
        void draw();    // draw method, this where you'll do the object's drawing

        // variables
        int ax;      // position
        int ay;
        int speedY; // speed and direction
        int speedX;
        int dim;
        int maxWidth;
        int maxHeight;
// size

        ofBall(int,int,int,int); // constructor - used to initialize an object, if no properties are passed
                  //               the program sets them to the default value

    private: // place private functions or variables declarations here

}; // dont't forget the semicolon!!

#endif
