#pragma once

#include "ofMain.h"

#define LENGTH 8

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void playerHitCheck(int i);
    void enemyHitCheck(int i);
    void isFinished();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    ofLight light;
    ofTrueTypeFont font1, font2;
    
    int Player;
    int z;
    
    int Enemy;
    bool drawEnemy[LENGTH], drawPlayer;
    bool countEnemy[LENGTH];
    float loc_x[LENGTH], loc_y[LENGTH], loc_z[LENGTH];
};
