#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "include.h"

void kirikouStart(){
    kirikou.x = 0;
    kirikou.y = 0;
    NF_CreateSprite(1, 0, 0, 0, kirikou.x, kirikou.y);
}
void kirikouUpdate(){
    if(KEY_RIGHT & keysHeld()){
        kirikou.x += 2;
    }
    if(KEY_LEFT & keysHeld()){
        kirikou.x -= 2;
    }
    if(KEY_DOWN & keysHeld()){
        kirikou.y += 2;
    }
    if(KEY_UP & keysHeld()){
        kirikou.y -= 2;
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
    NF_MoveSprite(1, 0, kirikou.x, kirikou.y);
    NF_ScrollBg(1, 3, kirikou.x, kirikou.y);
}