#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

void kirikouStart(){
    kirikou.x = 384;
    kirikou.y = 478;
    cam.x = 0;
    cam.y = 0;
    NF_CreateSprite(1, 0, 0, 0, kirikou.x, kirikou.y);
    //NF_CreateSprite(0, 15, 15, 15, kirikou.x/4, kirikou.y/4);
}

static void bulletCamUpdate(){
    if(bal.x > cam.x-16 && bal.x - cam.x < 256){
        bal.sprx = bal.x - cam.x;
    }
    else{
        bal.sprx = 256;
    }
    if(bal.y > cam.y-32 && bal.y - cam.y < 192){
        bal.spry = bal.y - cam.y;
    }
    else{
        bal.spry = 192;
    }
    NF_MoveSprite(1, 32, bal.sprx, bal.spry);
}

static void bulletUpdate(){
    switch(bal.side){
        case 0:
            break;
        case 1:
            if(NF_GetTile(0, bal.x, bal.y) == 0){
                bal.x+=5;
            }
            else{
                bal.side = 0;
                bal.x = 768;
                bal.y = 768;
            }
            break;
        case 2:
            if(NF_GetTile(0, bal.x, bal.y) == 0){
                bal.x-=5;
            }
            else{
                bal.side = 0;
                bal.x = 768;
                bal.y = 768;
            }
            break;
        case 3:
            if(NF_GetTile(0, bal.x, bal.y) == 0){
                bal.y+=5;
            }
            else{
                bal.side = 0;
                bal.x = 768;
                bal.y = 768;
            }
            break;
        case 4:
            if(NF_GetTile(0, bal.x, bal.y) == 0){
                bal.y-=5;
            }
            else{
                bal.side = 0;
                bal.x = 768;
                bal.y = 768;
            }
            break;
    }
    bulletCamUpdate();
}
static void bulletStart(){
    bal.x = kirikou.x;
    bal.y = kirikou.y;
    mmEffect(SFX_GUN);
}
void kirikouGunUpdate(){
    if(bal.side == 0){
        if(KEY_A & keysDown()){
            bulletStart();
            bal.side = 1;
        }
        if(KEY_B & keysDown()){
            bulletStart();
            bal.side = 3;
        }
        if(KEY_Y & keysDown()){
            bulletStart();
            bal.side = 2;
        }
        if(KEY_X & keysDown()){
            bulletStart();
            bal.side = 4;
        }
    }
    bulletUpdate();
}
void kirikouUpdate(){
    int spr_x, spr_y;
    bool x_flag = false;
    bool y_flag = false;
    if(KEY_RIGHT & keysHeld()){
        NF_HflipSprite(1, 0, false);
        if(NF_GetTile(0, kirikou.x+17, kirikou.y) == 0 && NF_GetTile(0, kirikou.x+17, kirikou.y+30) == 0){
            kirikou.x += 1;
        }
    }
    if(KEY_LEFT & keysHeld()){
        NF_HflipSprite(1, 0, true);
        if(NF_GetTile(0, kirikou.x-1, kirikou.y) == 0 && NF_GetTile(0, kirikou.x-1, kirikou.y+30) == 0){
            kirikou.x -= 1;
        }
    }
    if(KEY_DOWN & keysHeld()){
        if(NF_GetTile(0, kirikou.x, kirikou.y+31) == 0 && NF_GetTile(0, kirikou.x+14, kirikou.y+31) == 0){
            kirikou.y += 1;
        }
    }
    if(KEY_UP & keysHeld()){
        if(NF_GetTile(0, kirikou.x, kirikou.y-1) == 0 && NF_GetTile(0, kirikou.x+14, kirikou.y-1) == 0){
            kirikou.y -= 1;
        }
    }
    if(kirikou.x < 0){
        kirikou.x = 0;
    }
    if(kirikou.x > 768){
        kirikou.x = 768;
    }
    if(kirikou.y < 0){
        kirikou.y = 0;
    }
    if(kirikou.y > 768){
        kirikou.y = 768;
    }
    spr_x = 120;
    spr_y = 80;
    if(kirikou.x < 120){
        spr_x = kirikou.x;
        x_flag = true;
    }
    if(kirikou.y < 80){
        spr_y = kirikou.y;
        y_flag = true;
    }
    if(kirikou.x > 632){
        spr_x = kirikou.x-512;
        x_flag = true;
    }
    if(kirikou.y > 656){
        spr_y = kirikou.y-576;
        y_flag = true;
    }
    if(x_flag == false){
        cam.x = kirikou.x-120;
    }
    else{
        if(kirikou.x < 120){
            cam.x = 0;
        }
        if(kirikou.x > 632){
            cam.x = 512;
        }
    }
    if(y_flag == false){
        cam.y = kirikou.y-80;
    }
    else{
        if(kirikou.y < 80){
            cam.y = 0;
        }
        if(kirikou.y > 688){
            cam.y = 576;
        }
    }
    NF_MoveSprite(1, 0, spr_x, spr_y);
    /*NF_MoveSprite(0, 15, (kirikou.x/4)+32, kirikou.y/4);*/
    NF_ScrollBg(1, 3, cam.x, cam.y);
    NF_ScrollBg(1, 2, cam.x, cam.y);
}
