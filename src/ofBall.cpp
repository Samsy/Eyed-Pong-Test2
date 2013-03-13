#include "ofBall.h"

ofBall::ofBall(int a, int b, int c, int d)
{
    ax = a;
    ay = b;
    maxWidth= c;
    maxHeight = d;


    exchange = 0;
    speedX = -5;
    speedY = 5;
    dim = 10;
}

void ofBall::update(int rectX)
{

    ax = ax+speedX;
    ay= ay+speedY;

    if(ax>maxWidth)
    {
        ax-=10;
        speedX = -speedX;
    }

    if(ax<0)
    {
        ax+=10;
        speedX = -speedX;
        speedX++;
    }

    if ((ay > maxHeight-60) && (ax > rectX ) && (ax < (rectX+50)) )
    {
        speedY = -5;
    }
    if (ay < 70 )
    {
        speedY = 5;
        exchange++;
    }

}

void ofBall::draw()
{
    ofCircle(ax, ay, dim);
}
