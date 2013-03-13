#ifndef TWEEN_H_INCLUDED
#define TWEEN_H_INCLUDED



#include "ofMain.h"

#define tweenNumber 18

class tween {

    public:


        void update(int,int);
        void draw();

        int permutX;
        int permutY;
        int ax[tweenNumber];
        int ay[tweenNumber];
        int alpha;
        int color;
        float dim;
        tween();
                  //

    private:

};



#endif // TWEEN_H_INCLUDED
