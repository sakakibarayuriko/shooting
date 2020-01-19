#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //フォント読み込み
    ofTrueTypeFont::setGlobalDpi(72);
    font1.load("SFNSText.ttf", 30);
    font2.load("SFNSText.ttf", 60);
    
    //ライト設定
    ofEnableLighting();
    light.setPosition(512, 0, 50);
    light.enable();
    
    //プレーヤーの数
    Player = 1;
    //敵の数
    Enemy = 8;
    
    //敵の弾
    loc_x[0] = 256;
    loc_y[0] = 384;
    loc_z[0] = -1000;
    
    loc_x[1] = 512;
    loc_y[1] = 200;
    loc_z[1] = -1000;
    
    loc_x[2] = 768;
    loc_y[2] = 384;
    loc_z[2] = -1000;
    
    loc_x[3] = 512;
    loc_y[3] = 600;
    loc_z[3] = -1000;
    
    loc_x[4] = 100;
    loc_y[4] = 100;
    loc_z[4] = -1000;
    
    loc_x[5] = 924;
    loc_y[5] = 100;
    loc_z[5] = -1000;
    
    loc_x[6] = 924;
    loc_y[6] = 668;
    loc_z[6] = -1000;
    
    loc_x[7] = 100;
    loc_y[7] = 668;
    loc_z[7] = -1000;
    
    drawPlayer = true;
    for(int i = 0; i < 8; i++) {
        drawEnemy[i] = true;
        countEnemy[i] = true;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //弾の加速度
    z -= 10;
    
    for(int i = 0; i < 8; i++) {
        loc_x[i] = loc_x[i] + 0;
        loc_y[i] = loc_y[i] + 0;
        loc_z[i] = loc_z[i] + 8;
    }
    
    //弾を撃ち続ける
    if (z == -1000) {
        z = 0;
    }
    
    if(loc_z[0] == 0){
        loc_x[0] = 256;
        loc_y[0] = 384;
        loc_z[0] = -1000;
    }
    
    if(loc_z[1] == 0){
        loc_x[1] = 512;
        loc_y[1] = 200;
        loc_z[1] = -1000;
    }
    
    if(loc_z[2] == 0){
        loc_x[2] = 768;
        loc_y[2] = 384;
        loc_z[2] = -1000;
    }
    
    if(loc_z[3] == 0){
        loc_x[3] = 512;
        loc_y[3] = 600;
        loc_z[3] = -1000;
    }
    
    if(loc_z[4] == 0){
        loc_x[4] = 100;
        loc_y[4] = 100;
        loc_z[4] = -1000;
    }
    
    if(loc_z[5] == 0){
        loc_x[5] = 924;
        loc_y[5] = 100;
        loc_z[5] = -1000;
    }
    
    if(loc_z[6] == 0){
        loc_x[6] = 924;
        loc_y[6] = 668;
        loc_z[6] = -1000;
    }
    
    if(loc_z[7] == 0){
        loc_x[7] = 100;
        loc_y[7] = 668;
        loc_z[7] = -1000;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ゲーム中（プレーヤーかつ敵が残っている）
    if(Enemy != 0 && Player != 0) {
        //
        ofBackground(0);
        ofSetColor(255);
        font1.drawString(ofToString(Enemy) + "enemys", 450, 35);
        
        //プレーヤー
        ofPushMatrix();
        if(drawPlayer){
            //プレーヤー自身描画
            ofSetColor(31, 63, 255);
            ofDrawCircle(mouseX, mouseY,20);
            ofSetColor(116, 193, 206);
            //弾描画
            sphere.set(6,10);
            sphere.setPosition(mouseX, mouseY, z);
            sphere.draw();
        }
        ofPopMatrix();
        
        //敵
        ofPushMatrix();
        for(int i = 0; i < 8; i++) {
            if(drawEnemy[i]){
                //敵自身描画
                ofSetColor(255);
                box.set(40);
                box.setPosition(loc_x[i], loc_y[i], -1000);
                box.draw();
                //弾描画
                ofSetColor(211, 24, 24);
                sphere.set(6,10);
                sphere.setPosition(loc_x[i], loc_y[i], loc_z[i]);
                sphere.draw();
            }
        }
        ofPopMatrix();
        
        //当たり判定
        for(int i = 0; i < 8; i++) {
            playerHitCheck(i);
            enemyHitCheck(i);
        }
    }
    //ゲーム終了
    isFinished();
}

//--------------------------------------------------------------
void ofApp::playerHitCheck(int i){
    //敵がプレーヤーに当てる
    if(!(ofDist(mouseX, mouseY, 0, loc_x[i], loc_y[i], loc_z[i])<=23 && countEnemy[i])){
        return;
    }
    //プレーヤーが減る
    Player -= 1;
}

//--------------------------------------------------------------
void ofApp::enemyHitCheck(int i){
    //プレーヤーが敵に当てる
    if(!(ofDist(mouseX, mouseY, z, loc_x[i], loc_y[i], -1000)<=23)){
        return;
    }
    drawEnemy[i] = false;
    loc_z[i] = -1000;
    if(countEnemy[i]){
        //敵が減る
        Enemy -= 1;
        ofSetColor(211, 24, 24);
        ofDrawCircle(loc_x[i], loc_y[i], loc_z[i], 30);
        countEnemy[i] = false;
    }
}

//--------------------------------------------------------------
void ofApp::isFinished(){
    //敵が消滅
    if(Enemy == 0){
        drawPlayer = false;
        //ゲームクリア
        ofSetColor(256, 256, 0);
        font2.drawString("GameClear!", 350, 384);
    }
    //プレーヤーが消滅
    if(Player == 0){
        for(int i = 0; i < 8; i++) {
            drawEnemy[i] = false;
        }
        //ゲームオーバー
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
