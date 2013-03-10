#include "ofBall.h"

ofBall::ofBall(int a, int b, int c, int d)
{
    ax = a;      // give some random positioning
    ay = b;
    maxWidth= c;
    maxHeight = d;
    speedX = -5;           // and random speed and direction
    speedY = 5;

    dim = 10;
}

void ofBall::update(){

 ax = ax+speedX;
ay= ay+speedY;

if(ax>maxWidth) {
        ax-=10;
        speedX = -5;
        cout << "ax " <<ax << endl;
        cout << "maxWidth " <<maxWidth << endl;
        }

if(ax<0) {
        ax+=10;
        speedX = 5;
        cout << "ax " <<ax << endl;
        cout << "maxWidth " <<maxWidth << endl;
        }
//
}

void ofBall::draw(){
    // values for R, G, B
    //ofSetColor(120,120,120);

    ofCircle(ax, ay, dim);

}
