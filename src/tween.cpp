#include "tween.h"

tween::tween()
{

       dim = 9.0;
       alpha=225;
        color=0;


}

void tween::update(int permutX, int permutY){

for(int i=tweenNumber-1; i>=1; i--)
{
ax[i]=ax[i-1];
ay[i]=ay[i-1];
}

ax[0]=permutX;
ay[0]=permutY;
}




void tween::draw(){
 ofEnableAlphaBlending();

 for(int i=0; i<tweenNumber; i++)
{
  ofSetColor(255,color,color,alpha);
  ofCircle(ax[i], ay[i], dim);
  alpha-=15;
  color+=10;
  dim=dim-0.5;

}
ofDisableAlphaBlending();
alpha=225;
dim=9;
color=0;




}
