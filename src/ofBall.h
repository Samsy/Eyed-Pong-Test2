#ifndef _OF_BALL
#define _OF_BALL


#include "ofMain.h"

class ofBall {

    public:


        void update(int);
        void draw();

        int exchange;
        int ax;
        int ay;
        int speedY;
        int speedX;
        int dim;
        int maxWidth;
        int maxHeight;
        ofBall(int,int,int,int);
                  //

    private:

};

#endif
