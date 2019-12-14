#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //loadfont
    ofTrueTypeFont::setGlobalDpi(72);
    font1.load("SFNSText.ttf", 30);
    font2.load("SFNSText.ttf", 60);
    
    //Light
    ofEnableLighting();
    light.setPosition(512, 0, 50);
    light.enable();
    
    Enemy = 8;
    Player = 1;
    
    //Enemy
    //drawRect = true;
    loc_x1 = 256;
    loc_y1 = 384;
    loc_z1 = -1000;
    
    loc_x2 = 512;
    loc_y2 = 200;
    loc_z2 = -1000;
   
    loc_x3 = 768;
    loc_y3 = 384;
    loc_z3 = -1000;
    
    loc_x4 = 512;
    loc_y4 = 600;
    loc_z4 = -1000;
    
    loc_x5 = 100;
    loc_y5 = 100;
    loc_z5 = -1000;
    
    loc_x6 = 924;
    loc_y6 = 100;
    loc_z6 = -1000;
    
    loc_x7 = 924;
    loc_y7 = 668;
    loc_z7 = -1000;
    
    loc_x8 = 100;
    loc_y8 = 668;
    loc_z8 = -1000;
    
    drawInformation = true;
    drawPlayer = true;
    drawEnemy = true;
    drawEnemy2 = true;
    drawEnemy3 = true;
    drawEnemy4 = true;
    drawEnemy5 = true;
    drawEnemy6 = true;
    drawEnemy7 = true;
    drawEnemy8 = true;
    countEnemy = true;
    countEnemy2 = true;
    countEnemy3 = true;
    countEnemy4 = true;
    countEnemy5 = true;
    countEnemy6 = true;
    countEnemy7 = true;
    countEnemy8 = true;
}

//--------------------------------------------------------------
void ofApp::update(){

    loc_x1 = loc_x1 + 0;
    loc_y1 = loc_y1 + 0;
    loc_z1 = loc_z1 + 8;
    
    loc_x2 = loc_x2 + 0;
    loc_y2 = loc_y2 + 0;
    loc_z2 = loc_z2 + 8;
    
    loc_x3 = loc_x3 + 0;
    loc_y3 = loc_y3 + 0;
    loc_z3 = loc_z3 + 8;
    
    loc_x4 = loc_x4 + 0;
    loc_y4 = loc_y4 + 0;
    loc_z4 = loc_z4 + 8;
    
    loc_x5 = loc_x5 + 0;
    loc_y5 = loc_y5 + 0;
    loc_z5 = loc_z5 + 8;
    
    loc_x6 = loc_x6 + 0;
    loc_y6 = loc_y6 + 0;
    loc_z6 = loc_z6 + 8;
    
    loc_x7 = loc_x7 + 0;
    loc_y7 = loc_y7 + 0;
    loc_z7 = loc_z7 + 8;
    
    loc_x8 = loc_x8 + 0;
    loc_y8 = loc_y8 + 0;
    loc_z8 = loc_z8 + 8;
    
    if(loc_z1 == 0){
        loc_x1 = 256;
        loc_y1 = 384;
        loc_z1 = -1000;
    }
    
    if(loc_z2 == 0){
        loc_x2 = 512;
        loc_y2 = 200;
        loc_z2 = -1000;
    }
    
    if(loc_z3 == 0){
        loc_x3 = 768;
        loc_y3 = 384;
        loc_z3 = -1000;
    }
    
    if(loc_z4 == 0){
        loc_x4 = 512;
        loc_y4 = 600;
        loc_z4 = -1000;
    }
    
    if(loc_z5 == 0){
        loc_x5 = 100;
        loc_y5 = 100;
        loc_z5 = -1000;
    }
    
    if(loc_z6 == 0){
        loc_x6 = 924;
        loc_y6 = 100;
        loc_z6 = -1000;
    }
    
    if(loc_z7 == 0){
        loc_x7 = 924;
        loc_y7 = 668;
        loc_z7 = -1000;
    }
    
    if(loc_z8 == 0){
        loc_x8 = 100;
        loc_y8 = 668;
        loc_z8 = -1000;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if(drawInformation){
    ofSetColor(255);
    font1.drawString(ofToString(Enemy) + "enemys", 450, 35);
    }
    
    //Player
    ofPushMatrix();
    if(drawPlayer){
    ofSetColor(31, 63, 255);
    ofDrawCircle(mouseX, mouseY,20);
    ofSetColor(116, 193, 206);
    sphere.set(6,10);
    sphere.setPosition(mouseX, mouseY, z);
    sphere.draw();
    z -= velocity;
    if (z == -1000) {
        z = 0;
     }
    }
         
    ofPopMatrix();
    
    //Enemy
    ofPushMatrix();
    if(drawEnemy){
    ofSetColor(255);
    box.set(40);
    box.setPosition(loc_x1, loc_y1, -1000);
    box.draw();
    ofSetColor(211, 24, 24);
    sphere.set(6,10);
    sphere.setPosition(loc_x1, loc_y1, loc_z1);
    sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy2){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x2, loc_y2, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x2, loc_y2, loc_z2);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy3){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x3, loc_y3, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x3, loc_y3, loc_z3);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy4){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x4, loc_y4, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x4, loc_y4, loc_z4);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy5){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x5, loc_y5, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x5, loc_y5, loc_z5);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy6){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x6, loc_y6, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x6, loc_y6, loc_z6);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy7){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x7, loc_y7, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x7, loc_y7, loc_z7);
        sphere.draw();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    if(drawEnemy8){
        ofSetColor(255);
        box.set(40);
        box.setPosition(loc_x8, loc_y8, -1000);
        box.draw();
        ofSetColor(211, 24, 24);
        sphere.set(6,10);
        sphere.setPosition(loc_x8, loc_y8, loc_z8);
        sphere.draw();
    }
    ofPopMatrix();
    
    if(Player != 0){
    HitCheck();
    HitCheck2();
    HitCheck3();
    HitCheck4();
    HitCheck5();
    HitCheck6();
    HitCheck7();
    HitCheck8();
    HitCheck9();
    gameClear();
    }
    gameOver();
}

//--------------------------------------------------------------
void ofApp::HitCheck(){
    //敵がプレーヤーに当てる
    if(!(ofDist(mouseX, mouseY, 0, loc_x1, loc_y1, loc_z1)<=23 || ofDist(mouseX, mouseY, 0, loc_x2, loc_y2, loc_z2)<=23
    || ofDist(mouseX, mouseY, 0, loc_x3, loc_y3, loc_z3)<=23 || ofDist(mouseX, mouseY, 0, loc_x4, loc_y4, loc_z4)<=23
    || ofDist(mouseX, mouseY, 0, loc_x5, loc_y5, loc_z5)<=23 || ofDist(mouseX, mouseY, 0, loc_x6, loc_y6, loc_z6)<=23
    || ofDist(mouseX, mouseY, 0, loc_x7, loc_y7, loc_z7)<=23 || ofDist(mouseX, mouseY, 0, loc_x8, loc_y8, loc_z8)<=23)){
        return;
    }
    Player -= 1;
}

//--------------------------------------------------------------
void ofApp::HitCheck2(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x1, loc_y1, -1000)<=23)){
        return;
    }
    drawEnemy = false;
    loc_z1 = -1000;
    if(countEnemy){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x1, loc_y1, loc_z1, 30);
        countEnemy = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck3(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x2, loc_y2, -1000)<=23)){
        return;
    }
    drawEnemy2 = false;
    loc_z2 = -1000;
    if(countEnemy2){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x2, loc_y2, loc_z2, 30);
        countEnemy2 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck4(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x3, loc_y3, -1000)<=23)){
        return;
    }
    drawEnemy3 = false;
    loc_z3 = -1000;
    if(countEnemy3){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x3, loc_y3, loc_z3, 30);
        countEnemy3 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck5(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x4, loc_y4, -1000)<=23)){
        return;
    }
    drawEnemy4 = false;
    loc_z4 = -1000;
    if(countEnemy4){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x4, loc_y4, loc_z4, 30);
        countEnemy4 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck6(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x5, loc_y5, -1000)<=23)){
        return;
    }
    drawEnemy5 = false;
    loc_z5 = -1000;
    if(countEnemy5){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x5, loc_y5, loc_z5, 30);
        countEnemy5 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck7(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x6, loc_y6, -1000)<=23)){
        return;
    }
    drawEnemy6 = false;
    loc_z6 = -1000;
    if(countEnemy6){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x6, loc_y6, loc_z6, 30);
        countEnemy6 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck8(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x7, loc_y7, -1000)<=23)){
        return;
    }
    drawEnemy7 = false;
    loc_z7 = -1000;
    if(countEnemy7){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x7, loc_y7, loc_z7, 30);
        countEnemy7 = false;
    }
}

//--------------------------------------------------------------
void ofApp::HitCheck9(){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x8, loc_y8, -1000)<=23)){
        return;
    }
    drawEnemy8 = false;
    loc_z8 = -1000;
    if(countEnemy8){
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x8, loc_y8, loc_z8, 30);
        countEnemy8 = false;
    }
}

//--------------------------------------------------------------
void ofApp::gameClear(){
    if(Enemy == 0){
        drawPlayer = false;
        drawInformation = false;
        //gameclear
        ofSetColor(256, 256, 0);
        font2.drawString("GameClear!", 350, 384);
    }
        return;
}

//--------------------------------------------------------------
void ofApp::gameOver(){
    if(Player == 0){
        drawEnemy = false;
        drawEnemy2 = false;
        drawEnemy3 = false;
        drawEnemy4 = false;
        drawEnemy5 = false;
        drawEnemy6 = false;
        drawEnemy7 = false;
        drawEnemy8 = false;
        drawPlayer = false;
        drawInformation = false;
        //gameover
        ofSetColor(256, 256, 0);
        font2.drawString("GameOver!", 350, 384);
    }
        return;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
