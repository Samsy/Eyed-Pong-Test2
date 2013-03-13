#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    // resolution de la webcam
    camWidth 		= 640;
    camHeight 		= 360;
    // X de base de la raquette du joueur
    rectPongX = camWidth/2;
    // allocation RGB d'une texture à la taille de la capture
    videoTexture.allocate(camWidth,camHeight, GL_RGB);
     fondTexture.allocate(300,360, GL_RGB);
    // chargement du XML haarcascade ( OpenCv )
    // ce XML permet de repérer les yeux
    finder.setup("haarcascade_eye_tree_eyeglasses.xml");
    // nouvelle balle à 4 paramètres : (X de depart, Y de depart,
    //                                  largeur max de déplacement,
    //                                  hauteur max de déplacement).
    myball = new ofBall(camWidth/2,camHeight/2,camWidth,camHeight);
    // lancement du thread qui se charge de charger les images
    // du live feed.

    // chargement de la petite description de l'appli, dans une texture
    detail.loadImage("fond.jpg");
    fond = detail.getPixels();

    fondTexture.loadData(fond, 300,360, GL_RGB);
    verdana14.loadFont("verdana.ttf", 9, true, true);

    thread.start();

}

//--------------------------------------------------------------
void testApp::update()
{

    // Lorsque le thread est bien lancé
    if(thread.flag)
    {
        thread.lock();
        // récupération d'un tableau de pixels depuis le thread
        pixels=thread.pixels2;
        // récupération d'une oFimage depuis le thread
        img=thread.ImageCam;
        thread.unlock();
        // détéction des yeux à partir de l'image
        finder.findHaarObjects(img);
        // chargement du tableau pixels dans la texture
videoTexture.loadData(pixels, camWidth,camHeight, GL_RGB);
        // update de la boule
        myball->update(rectPongX);

    }
}


//--------------------------------------------------------------
void testApp::draw()
{

    // affichage de la texture ( image du live feed )

    videoTexture.draw(0,0,camWidth,camHeight);
     fondTexture.draw(camWidth,0,300,360);

   // verdana14.drawString(typeStr, 740, 300);
MyTween.update(myball->ax,myball->ay);
    // les deux valeurs Eyeleft et EyeRight, permettent
    // de déterminer si l'oeuil qui a été détécté
    // est à gauche ou a droite de la barre centrale de jeu.
    EyeLeft=false;
    EyeRight=false;
    ofNoFill();
    // la détéction des yeux par le finder et le XML
    // retourne un tableau de blobs contenant des coordonnées de rectangle.
    for(int i = 0; i < finder.blobs.size(); i++)
    {
        // récupération des rectangle du tableau blobs.
        ofRectangle cur = finder.blobs[i].boundingRect;
        // affiahge des différents rectangle
        ofRect(cur.x, cur.y, cur.width, cur.height);

        // si le carré est à droite de la ligne centrale,
        // alors l'oeil gauche est ouvert ( image inversée )
        if(cur.x > camWidth/2)
        {

            EyeLeft=true;
        }

         // si le carré est à gauche de la ligne centrale,
        // alors l'oeil droite est ouvert ( image inversée )
        else
        {

            EyeRight=true;
        }
    }

    //dessin de la ligne centrale
    ofLine(camWidth/2,100,camWidth/2,camHeight-100);
    ofFill();

    // si EyeLeft est faux, c'est donc que l'oeuil gauche est fermé
    if (!EyeLeft && (rectPongX > 0))
    {
        // la raquette se déplace vers la gauche
        rectPongX-=15;
    }

    // si EyeRight est faux, c'est donc que l'oeuil gauche est fermé
    if (!EyeRight && (rectPongX < camWidth-50))
    {
        // la raquette se déplace à droite
        rectPongX+=15;
    }

    // dessin des deux raquettes.

    ofRect(rectPongX,camHeight-40,50,20);

    ofRect (myball->ax-25, 40, 50,20);

    ofSetColor(255,0,0);

    if((myball->ay > camHeight+10) || (myball->ay < 0) ) {
        myball = new ofBall(camWidth/2,camHeight/2,camWidth,camHeight);
    }

    // dessin de la boule
    myball->draw();
    MyTween.draw();
    ofSetColor(255,255,255);

}

void testApp::exit()
{

    // fin du thread lorsque l'on quitte l'application.
    thread.stopThread();
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
