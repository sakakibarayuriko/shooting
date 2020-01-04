#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void HitCheck();
    void HitCheck2();
    void HitCheck3();
    void HitCheck4();
    void HitCheck5();
    void HitCheck6();
    void HitCheck7();
    void HitCheck8();
    void HitCheck9();
    void gameClear();
    void gameOver();
    
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
    
    int Enemy, Player;
    bool drawEnemy, drawEnemy2, drawEnemy3, drawEnemy4, drawEnemy5, drawEnemy6, drawEnemy7, drawEnemy8, drawPlayer;
    bool countEnemy, countEnemy2, countEnemy3, countEnemy4, countEnemy5, countEnemy6, countEnemy7, countEnemy8;
    bool drawInformation;
    float loc_x1, loc_y1, loc_z1;
    float loc_x2, loc_y2, loc_z2;
    float loc_x3, loc_y3, loc_z3;
    float loc_x4, loc_y4, loc_z4;
    float loc_x5, loc_y5, loc_z5;
    float loc_x6, loc_y6, loc_z6;
    float loc_x7, loc_y7, loc_z7;
    float loc_x8, loc_y8, loc_z8;
    
    int velocity = 10;  //オブジェクトのスピード
    int z = 0;  //オブジェクトのx座標
};
